#pragma once
/*
�������ַ���������ʹ�ñ��ײ��
DocURL��			https://zhuanlan.zhihu.com/p/78023533

�������ַ������ο�����ǰ�Ĳ��
MarketplaceURL :  http://www.aboutcg.org/course/tut_ue4suite_190813/?action=

������˽�������UE4�̳���ο���
URL :				https://zhuanlan.zhihu.com/p/60117613

�����ϵͳ�˽���լϵ�н̳��Լ���ز���������� ���Թ�ע�ҵĲ���
URL :				http://renzhai.net/

������˽�������һ�ڵĿγ̰��ſ��� ������΢�Ź��ں����� ��լ ��ע���� ���ǻ����ͺܶ฻�м���������

���˲��� https://weibo.com/BZRZ/profile?s=6cm7D0  //������ʹ�16�굽���� ��������û��ô�ù� �Ժ�˵���������������� �ȷ�������

*/

#include "CoreMinimal.h"
#include "Interface/ProxyInterface.h"
#include "Containers/Queue.h"
#include "Core/ThreadCoreMacro.h"
#include "Abandonable/SimpleAbandonable.h"
#include "Coroutines/SimpleCoroutines.h"
#include "Async/TaskGraphInterfaces.h"
#include "Engine/StreamableManager.h"
#include "Runnable/ThreadRunnableProxy.h"

//�߳������ӿ�
class IThreadContainer
{
public:
	IThreadContainer() {}
	virtual ~IThreadContainer() {}

protected:
	FCriticalSection Mutex;
};

//�������ɴ����̣߳��������ƣ�������ϵ��̲߳����������٣��������Ҫ�����ٴ�ʹ�ã�
//����ͬ�����첽���ܣ�һ��������С����
class IThreadProxyContainer :public TArray<TSharedPtr<IThreadProxy>>, public IThreadContainer
{
protected:
	typedef TArray<TSharedPtr<IThreadProxy>>	TProxyArray;

public:
	IThreadProxyContainer &operator<<(const TSharedPtr<IThreadProxy> &ThreadProxy)
	{
		MUTEX_LOCL;

		ThreadProxy->CreateSafeThread();
		this->Add(ThreadProxy);

		return *this;
	}

	FThreadHandle operator>>(const FSimpleDelegate &ThreadProxy)
	{
		FThreadHandle ThreadHandle = nullptr;
		{
			MUTEX_LOCL;
			for (auto &Tmp : *this)
			{
				if (Tmp->IsSuspend() && !Tmp->GetThreadDelegate().IsBound())
				{
					Tmp->GetThreadDelegate() = ThreadProxy;
					ThreadHandle = Tmp->GetThreadHandle();
					Tmp->WakeupThread();

					break;
				}
			}
		}

		if (!ThreadHandle.IsValid())
		{
			TSharedPtr<IThreadProxy> Proxy = MakeShareable(new FThreadRunnable(true));
			Proxy->GetThreadDelegate() = ThreadProxy;
			*this << Proxy;

			ThreadHandle = Proxy->GetThreadHandle();
		}

		return ThreadHandle;
	}

	FThreadHandle operator<<(const FSimpleDelegate &ThreadProxy)
	{
		FThreadHandle ThreadHandle = nullptr;
		{
			MUTEX_LOCL;
			for (auto &Tmp : *this)
			{
				if (Tmp->IsSuspend() && !Tmp->GetThreadDelegate().IsBound())
				{
					Tmp->GetThreadDelegate() = ThreadProxy;
					ThreadHandle = Tmp->GetThreadHandle();

					break;
				}
			}
		}

		if (!ThreadHandle.IsValid())
		{
			ThreadHandle = *this << MakeShareable(new FThreadRunnable) << ThreadProxy;
		}

		return ThreadHandle;
	}

	TSharedPtr<IThreadProxy> operator>>(const FThreadHandle &Handle)
	{
		MUTEX_LOCL;
		for (auto &Tmp : *this)
		{
			if (Tmp->GetThreadHandle() == Handle)
			{
				return Tmp;
			}
		}

		return NULL;
	}
};

//�̵߳�������������Զ����������Զ������õ��̳߳أ�ʵ�ָ�Ч�������̳߳��ص�
class IThreadTaskContainer :public TQueue<FSimpleDelegate>, public TArray<TSharedPtr<IThreadProxy>>, public IThreadContainer
{
protected:
	typedef TArray<TSharedPtr<IThreadProxy>>	TProxyArray;
	typedef TQueue<FSimpleDelegate>				TEventQueue;

public:
	void operator<<(const FSimpleDelegate &ThreadProxy)
	{
		MUTEX_LOCL;

		this->Enqueue(ThreadProxy);
	}

	bool operator<<=(FSimpleDelegate &ThreadProxy)
	{
		MUTEX_LOCL;

		return this->Dequeue(ThreadProxy);
	}

	IThreadTaskContainer& operator<<(const TSharedPtr<IThreadProxy> &ThreadProxy)
	{
		MUTEX_LOCL;

		this->Add(ThreadProxy);
		ThreadProxy->CreateSafeThread();

		return *this;
	}

	void operator>>(const FSimpleDelegate &ThreadProxy)
	{
		bool bSuccessful = false;
		{
			MUTEX_LOCL;
			for (auto &Tmp : *this)
			{
				if (Tmp->IsSuspend() && !Tmp->GetThreadDelegate().IsBound())
				{
					Tmp->GetThreadDelegate() = ThreadProxy;
					Tmp->WakeupThread();

					bSuccessful = true;
					break;
				}
			}
		}

		if (!bSuccessful)
		{
			*this << ThreadProxy;
		}
	}
};

//ͬ���첽�߳̽ӿ�
class IAbandonableContainer :public IThreadContainer
{
protected:
	//ͬ����
	void operator<<(const FSimpleDelegate& ThreadDelegate)
	{
		FAsyncTask<FSimpleAbandonable> *SimpleAbandonable = new FAsyncTask<FSimpleAbandonable>(ThreadDelegate);
		SimpleAbandonable->StartBackgroundTask();
		SimpleAbandonable->EnsureCompletion();
		delete SimpleAbandonable;
	}

	//�첽��
	void operator>>(const FSimpleDelegate& ThreadDelegate)
	{
		(new FAutoDeleteAsyncTask<FSimpleAbandonable>(ThreadDelegate))->StartBackgroundTask();
	}
};

//Э�̽ӿ�
class ICoroutinesContainer 
{
public:
	ICoroutinesContainer()
	 :TmpTotalTime(0.f)
	{

	}
	virtual ~ICoroutinesContainer()
	{
		ICoroutinesObject::Array.Empty();
	}

	ICoroutinesContainer &operator<<(float TotalTime)
	{
		TmpTotalTime = TotalTime;

		return *this;
	}

	ICoroutinesContainer &operator<<(const FSimpleDelegate& ThreadDelegate)
	{
		ICoroutinesObject::Array.Add(MakeShareable(new FCoroutinesObject(TmpTotalTime, ThreadDelegate)));

		return *this;
	}

	void operator<<=(float Time)
	{
		TArray<TSharedPtr<ICoroutinesObject>> RemoveObject;
		for (int32 i = 0 ;i < ICoroutinesObject::Array.Num() ;i++)
		{
			FCoroutinesRequest Request(Time);

			ICoroutinesObject::Array[i]->Update(Request);
			if (Request.bCompleteRequest)
			{
				RemoveObject.Add(ICoroutinesObject::Array[i]);
			}
		}

		for (auto &RemoveInstance : RemoveObject)
		{
			ICoroutinesObject::Array.Remove(RemoveInstance);
		}
	}

	FCoroutinesHandle operator>>(const FSimpleDelegate& ThreadDelegate)
	{
		ICoroutinesObject::Array.Add(MakeShareable(new FCoroutinesObject(ThreadDelegate)));

		return ICoroutinesObject::Array[ICoroutinesObject::Array.Num() - 1];
	}
private:
	float TmpTotalTime;
};

//ͼ���߳̽ӿ�
class IGraphContainer :public IThreadContainer
{
protected:

	//�������߳�
	FGraphEventRef operator<<(const FSimpleDelegate& ThreadDelegate)
	{
		MUTEX_LOCL;
		return FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
			ThreadDelegate,
			TStatId(),
			nullptr,
			ENamedThreads::GameThread);
	}

	//�������߳�
	FGraphEventRef operator>>(const FSimpleDelegate& ThreadDelegate)
	{
		MUTEX_LOCL;
		return FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(
			ThreadDelegate,
			TStatId(),
			nullptr,
			ENamedThreads::AnyThread);
	}
};

//��Դ����ӿ�
class IStreamableContainer
{
public:
	virtual ~IStreamableContainer() {}

	//�洢·��
	IStreamableContainer &operator>>(const TArray<FSoftObjectPath> &InObjectPath)
	{
		SetObjectPath(InObjectPath);

		return *this;
	}
	//�첽��Դ
	TSharedPtr<struct FStreamableHandle> operator>>(const FSimpleDelegate& ThreadDelegate)
	{
		return GetStreamableManager()->RequestAsyncLoad(GetObjectPath(), ThreadDelegate);
	}

	//ͬ����ȡ
	TSharedPtr<struct FStreamableHandle> operator<<(const TArray<FSoftObjectPath> &InObjectPath)
	{
		return GetStreamableManager()->RequestSyncLoad(InObjectPath);
	}

protected:
	virtual void SetObjectPath(const TArray<FSoftObjectPath> &InObjectPath) = 0;
	virtual TArray<FSoftObjectPath> &GetObjectPath() = 0;
	virtual FStreamableManager *GetStreamableManager() = 0;
};
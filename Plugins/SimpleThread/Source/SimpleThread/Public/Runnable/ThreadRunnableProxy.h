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

���˲���				https://weibo.com/BZRZ/profile?s=6cm7D0  //������ʹ�16�굽���� ��������û��ô�ù� �Ժ�˵���������������� �ȷ�������
*/

#include "CoreMinimal.h"
#include "HAL/Runnable.h"
#include "Interface/ProxyInterface.h"
#include "Core/SimpleSemaphore.h"

//UE4 Runnable�̣߳����Դ����߳�ʵ��
class SIMPLETHREAD_API FThreadRunnable : public FRunnable, public IThreadProxy
{
public:
	FThreadRunnable(bool InSuspendAtFirst = false);
	virtual ~FThreadRunnable();

	//������ȫ�߳�
	virtual void CreateSafeThread();

	//�����߳�
	virtual void WakeupThread();

	//�߳��Ƿ񱻹���
	virtual bool IsSuspend();

	//�������̵߳ȴ�֪����ǰ�������
	virtual void WaitAndCompleted();

	//���������߳�
	virtual void BlockingAndCompletion();

private:

	//�߳�����ִ�еĵط�
	virtual uint32 Run();

	virtual bool Init();
	virtual void Stop();
	virtual void Exit();

private:

	
	FThreadSafeCounter					StopTaskCounter; //�̰߳�ȫ����
	bool								bSuspendAtFirst; //�Ƿ��һ�������߳�
	class FRunnableThread*				Thread;			 //�߳̾���ʵ��
	FName								RunnableName;	 //�߳����� �Ժ����չ
	FSimpleSemaphore					ThreadEvent;     //�ź��� ����Thread
	FSimpleSemaphore					StartUpEvent;	 //�ź��� ���������߳�
	FSimpleSemaphore					WaitExecuteEvent;//�ź��� ���������߳�
	FCriticalSection					Mutex;			 //��

	static int32						ThreadCount;	 //�߳����м���
};
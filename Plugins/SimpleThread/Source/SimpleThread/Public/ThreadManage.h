// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*
�ǳ���л��ʹ�ñ��ײ�������ײ��������ʹ����������Ŀ���У������Ѿ�Ϊ�������ϸ�Ĳ���
���߳���ȫ֧�����Ķ��߳���Ŀ������
���������Ҫ���๦�ܻ�ӭ�������ǵ�QQȺ ��846023597  ���� helloworld  �������ʲô������������ֱ��@��լ

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

#pragma once

//������˽���ϸ�̳̿��Դ�
#pragma region Course

//�̳��ĵ�����ֹ��������ʧЧ
//��ඣ���Һã��ҽ���լ����������Ϊ��ҽ���һ�¹���UE4���SimpleThread��ʹ�ü��ɡ�
//����һ���ں��Ŷ����߳�ģʽ�Ĳ����SimpleThread��Ӣ�����Ϊ�򵥵��̣߳����������Ĵ���򵥣�
//����ʹ���߿�����ȫ���ù��ĵײ��߳���������У�ֻ��ʹ�þͺ�
//ֻ��Ҫ���¼��󶨵��ò���ϼ�����ɸ��ֶ��̷߳�����
//
//Ŀ¼
//ǰ�û�������׼��
//�����߳�(FThreadProxyManage)
//�����߳�(FThreadTaskManagement)
//ͬ���첽�߳�(FThreadAbandonableManage)
//Э��(FCoroutinesManage)
//Windowsԭ���߳�(FWindowsPlatformThread)
//�첽��Դ��ȡ(FResourceLoadingManage)
//ͼ���߳�(ThreadGraphManage)
//����ͼ���߳�
//1.ǰ�û�������׼��
//�����Ȳ��ú�Ҫ����SimpleThread�̵߳Ļ���
//
////��
//FCriticalSection					Mutex;
//
////��ӡ
//void ThreadP(const FString Mes)
//{
//	{
//		FScopeLock ScopeLock(&Mutex);
//		if (GEngine)
//		{
//			GEngine->AddOnScreenDebugMessage(-1, 100.f, FColor::Red, *Mes);
//		}
//	}
//}
//
////�ṹ��
//struct FMyStruct
//{
//	void Hello(FString Mes)
//	{
//		ThreadP(FString::Printf(TEXT("FMyStruct::Hello : %s"), *Mes));
//	}
//};
//
////����ָ��
//struct FMyStructSP :public TSharedFromThis<FMyStructSP>
//{
//	void HelloSP(FString Mes)
//	{
//		ThreadP(FString::Printf(TEXT("FMyStructSP::Hello : %s"), *Mes));
//	}
//};
//
////��
//UCLASS(config = Game)
//class AThreadTestCharacter : public ACharacter
//{
//
//	GENERATED_BODY()
//public:
//	//���� UObject
//	UFUNCTION()
//		void T1(int32 i);
//	//���� UFunction
//	UFUNCTION()
//		void T2(int32 i, FString Mes);
//	UFUNCTION()
//		void Do();
//	UFUNCTION()
//		void Run();
//	UFUNCTION()
//		void OK();
//protected:
//	virtual void BeginPlay();
//};
//
//void AThreadTestCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//}
//void AThreadTestCharacter::T1(int32 i)
//{
//	ThreadP(FString::Printf(TEXT("T1 : %i"), i));
//}
//
//void AThreadTestCharacter::T2(int32 i, FString Mes)
//{
//	ThreadP(FString::Printf(TEXT("T2 : %i ,Mes = %s"), i, *Mes));
//}
//
//void AThreadTestCharacter::OK()
//{
//	ThreadP(TEXT("Windows Run"));
//}
//
//void AThreadTestCharacter::Run()
//{
//
//}
//
//void AThreadTestCharacter::Do()
//{
//
//}
//���ȴ���һ����AThreadTestCharacter ���Ǽ̳��� ACharacter��
//
//Ȼ������������SimpleThread�ṩ�ĸ����̡߳�
//
//2.�����߳�(FThreadProxyManage)
//�����߳������Լ����̳߳ط���������ͨ�������̴߳���һ���̣߳���ô����̻߳���뵽�̳߳��ڣ����ᱻ���ٵ����ǹ����ѵȴ���һ������
//
//��������ʾһ���������ʹ�÷�ʽ��
//
//CreateXXX�������̲߳���ֱ��ִ������, �����ݵ��첽��ʽ
//
//void AThreadTestCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//
//	FMyStruct MyStruct;
//	TSharedPtr<FMyStructSP> MyStructSP = MakeShareable(new FMyStructSP);
//
//	GThread::GetProxy().CreateUObject(this, &AThreadTestCharacter::T1, 777);
//	GThread::GetProxy().CreateRaw(&MyStruct, &FMyStruct::Hello, FString("Hello~"));
//	GThread::GetProxy().CreateSP(MyStructSP.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//	GThread::GetProxy().CreateUFunction(this, TEXT("T2"), 123, "T22222");
//	GThread::GetProxy().CreateLambda([](FString Mes)
//	{
//		ThreadP(Mes);
//	}, "Lambda");
//
//}
//����֮�����ǻ���Bind
//
//BindXXX : �����̲߳��Ұ����񣬵���ִ�� ͨ�� Join��Detach���������첽ִ�л���ͬ��ִ��;
//
//TArray<FThreadHandle> ThreadHandle;
//
//void AThreadTestCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//
//	ThreadHandle.SetNum(5);
//	FMyStruct MyStruct;
//	TSharedPtr<FMyStructSP> MyStructSP = MakeShareable(new FMyStructSP);
//
//	ThreadHandle[0] = GThread::GetProxy().BindUObject(this, &AThreadTestCharacter::T1, 777);
//	ThreadHandle[1] = GThread::GetProxy().BindRaw(&MyStruct, &FMyStruct::Hello, FString("Hello~"));
//	ThreadHandle[2] = GThread::GetProxy().BindSP(MyStructSP.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//	ThreadHandle[3] = GThread::GetProxy().BindUFunction(this, TEXT("T2"), 123, "T22222");
//	ThreadHandle[4] = GThread::GetProxy().BindLambda([](FString Mes)
//	{
//		ThreadP(Mes);
//	}, "Lambda");
//
//
//	GetWorld()->GetTimerManager().SetTimer(Handle, this, &AThreadTestCharacter::Do, 3.f);
//
//}
//
////ִ�����ǵ��߳���Std�÷�����
//void AThreadTestCharacter::Do()
//{
//	if (Handle.IsValid())
//	{
//		GetWorld()->GetTimerManager().ClearTimer(Handle);
//	}
//	//ͬ��ִ��
//	//for (auto &Tmp : ThreadHandle)
//	//{
//	//	GThread::GetProxy().Join(Tmp);
//	//}
//
//	//�첽ִ��
//	//for (auto &Tmp : ThreadHandle)
//	//{
//	//	GThread::GetProxy().Detach(Tmp);
//	//}
//}
//3.�����߳�(FThreadTaskManagement)
//ʹ�������̣߳��������߳����治�ϵ�ȥ������
//
//BindXXX ��ӵ���������� ����п��õ��߳̿���ֱ��ִ�и�����
//
//��������������ʵ�����ã�
//
//void AThreadTestCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//
//	GThread::GetTask().BindUObject(this, &AThreadTestCharacter::T1, 777);
//	GThread::GetTask().BindRaw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//	GThread::GetTask().BindSP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//	GThread::GetTask().BindUFunction(this, TEXT("T2"), 123, FString("T22222"));
//	GThread::GetTask().BindLambda([](FString Mes)
//	{
//		ThreadP(Mes);
//	}, "Lambda");
//
//}
//�÷��ʹ����̲߳�࣬����������CreateXXX
//
//CreateXXX ֱ�����̳߳������� ��������õ��߳� ֱ�����е�ǰ����;
//
//void AThreadTestCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//
//	GThread::GetTask().CreateUObject(this, &AThreadTestCharacter::T1, 777);
//	GThread::GetTask().CreateRaw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//	GThread::GetTask().CreateSP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//	GThread::GetTask().CreateUFunction(this, TEXT("T2"), 123, FString("T22222"));
//	GThread::GetTask().CreateLambda([](FString Mes)
//	{
//		ThreadP(Mes);
//	}, "Lambda");
//}
//���ݹٷ�:�����̵߳��Ժ��������ȼ��������õ���չ��
//
//	4.ͬ���첽�߳�(FThreadAbandonableManage)
//	���߳���UE4�̳߳��ڵ��̣߳����ɱ�ݣ�Ҫôִ��ͬ����Ҫôִ���첽��ͬ�����ǵ�ͬ���첽�߳�Ҳ��Bind��Create
//
//	BindXXX ͬ���� �����������߳� �������󼤻������߳�
//
//	void AThreadTestCharacter::BeginPlay()
//{
//	Super::BeginPlay();
//
//	GThread::GetAbandonable().BindUObject(this, &AThreadTestCharacter::T1, 777);
//	GThread::GetAbandonable().BindRaw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//	GThread::GetAbandonable().BindSP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//	GThread::GetAbandonable().BindUFunction(this, TEXT("T2"), 123, FString("T22222"));
//	GThread::GetAbandonable().BindLambda([](FString Mes)
//	{
//		ThreadP(Mes);
//	}, "Lambda");
//}
//	 CreateXXX �첽�� ֱ��������������ɺ��Զ�����;
//
//	 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 GThread::GetAbandonable().CreateUObject(this, &AThreadTestCharacter::T1, 777);
//		 GThread::GetAbandonable().CreateRaw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//		 GThread::GetAbandonable().CreateSP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//		 GThread::GetAbandonable().CreateUFunction(this, TEXT("T2"), 123, FString("T22222"));
//		 GThread::GetAbandonable().CreateLambda([](FString Mes)
//		 {
//			 ThreadP(Mes);
//		 }, "Lambda");
//	 }
//	 ����֮�⻹����˱�ݵĺ������̣߳����߳�Ҳ�ǿ���ִ��ͬ���첽
//
//		 ͬ����
//
//		 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 SYNCTASK_UOBJECT(this, &AThreadTestCharacter::T1, 777);
//		 SYNCTASK_Raw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//		 SYNCTASK_SP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//		 SYNCTASK_UFunction(this, TEXT("T2"), 123, FString("T22222"));
//		 SYNCTASK_Lambda([](FString Mes)
//		 {
//			 ThreadP(Mes);
//		 }, "Lambda");
//	 }
//	 �첽��
//
//		 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 ASYNCTASK_UOBJECT(this, &AThreadTestCharacter::T1, 777);
//		 ASYNCTASK_Raw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//		 ASYNCTASK_SP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//		 ASYNCTASK_UFunction(this, TEXT("T2"), 123, FString("T22222"));
//		 ASYNCTASK_Lambda([](FString Mes)
//		 {
//			 ThreadP(Mes);
//		 }, "Lambda");
//	 }
//	 5.Э��(FCoroutinesManage)
//		 �ò��Ҳ������Э�̹��ܣ�ͬ��Ҳ��Bind��Create������
//
//		 Bind	XXX	�󶨺��������ʱ�䣬���ִ��
//
//		 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 //����1s��ִ�к���T1
//		 GThread::GetCoroutines().BindUObject(1.f, this, &AThreadTestCharacter::T1, 777);
//		 GThread::GetCoroutines().BindRaw(2.f, &MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//		 GThread::GetCoroutines().BindSP(2.4f, MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//		 GThread::GetCoroutines().BindUFunction(4.f, this, TEXT("T2"), 123, FString("T22222"));
//		 GThread::GetCoroutines().BindLambda(7.f, [](FString Mes)
//		 {
//			 ThreadP(Mes);
//		 }, "Lambda");
//	 }
//	 CreateXXX	����Ϸ���һ��Handle, �ɳ���Ա������ʲôʱ��ִ��;
//
//	 TArray<FCoroutinesHandle> CoroutinesHandle;
//	 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 CoroutinesHandle.SetNum(5);
//		 CoroutinesHandle[0] = GThread::GetCoroutines().CreateUObject(this, &AThreadTestCharacter::T1, 777);
//		 CoroutinesHandle[1] = GThread::GetCoroutines().CreateRaw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//		 CoroutinesHandle[2] = GThread::GetCoroutines().CreateSP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//		 CoroutinesHandle[3] = GThread::GetCoroutines().CreateUFunction(this, TEXT("T2"), 123, FString("T22222"));
//		 CoroutinesHandle[4] = GThread::GetCoroutines().CreateLambda([](FString Mes)
//		 {
//			 ThreadP(Mes);
//		 }, "Lambda");
//
//		 GetWorld()->GetTimerManager().SetTimer(Handle, this, &AThreadTestCharacter::Do, 3.f);
//	 }
//
//	 //ִ��
//	 void AThreadTestCharacter::Do()
//	 {
//		 if (Handle.IsValid())
//		 {
//			 GetWorld()->GetTimerManager().ClearTimer(Handle);
//		 }
//
//		 for (auto &Tmp : CoroutinesHandle)
//		 {
//			 if (Tmp.IsValid())
//			 {
//				 //���Ѹ�Э���µ��¼�
//				 Tmp.Pin()->Awaken();
//			 }
//		 }
//	 }
//	 6.Windowsԭ���߳�(FWindowsPlatformThread)
//		 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 FWindowsPlatformThread::RunDelegate.BindUObject(this, &AThreadTestCharacter::Run);
//		 FWindowsPlatformThread::CompletedDelegate.BindUObject(this, &AThreadTestCharacter::OK);
//		 FWindowsPlatformThread::Show();//ִ���߳�
//	 }
//
//	 //����ִ��
//	 void AThreadTestCharacter::Run()
//	 {
//		 ...
//	 }
//
//	 //ִ�����
//	 void AThreadTestCharacter::OK()
//	 {
//		 ThreadP(TEXT("Windows Run"));
//	 }
//
//
//	 7.�첽��Դ��ȡ(FResourceLoadingManage)
//		 �첽��Դ��ȡ���Ƿ�Ϊͬ����ȡ���첽��ȡ����������������ʹ�÷���
//
//		 �첽
//
//		 UCLASS(config = Game)
//		 class AThreadTestCharacter : public ACharacter
//	 {
//		 GENERATED_BODY()
//
//	 public:
//		 //����ͼ������Դ·��
//		 UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
//			 TArray<FSoftObjectPath> ObjectPath;
//	 }
//
//	 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 auto La = [](TSharedPtr<FStreamableHandle> *InHandle)
//		 {
//			 TArray<UObject *> ExampleObject;
//			 (*InHandle)->GetLoadedAssets(ExampleObject);
//
//			 for (UObject *Tmp : ExampleObject)
//			 {
//				 ThreadP(Tmp->GetName());
//			 }
//		 };
//
//		 //�첽ʹ�÷���
//		 GThread::GetResourceLoading() >> ObjectPath;
//		 StreamableHandle = GThread::GetResourceLoading().CreateLambda(La, &StreamableHandle);
//	 }
//	 ͬ��
//
//		 UCLASS(config = Game)
//		 class AThreadTestCharacter : public ACharacter
//	 {
//		 GENERATED_BODY()
//	 public:
//		 //����ͼ������Դ·��
//		 UPROPERTY(EditDefaultsOnly, meta = (AllowPrivateAccess = "true"))
//			 TArray<FSoftObjectPath> ObjectPath;
//	 }
//
//	 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 auto La = [](TSharedPtr<FStreamableHandle> *InHandle)
//		 {
//			 TArray<UObject *> ExampleObject;
//			 (*InHandle)->GetLoadedAssets(ExampleObject);
//
//			 for (UObject *Tmp : ExampleObject)
//			 {
//				 ThreadP(Tmp->GetName());
//			 }
//		 };
//
//		 //ͬ��
//		//////////////////////////////////////////////////////////////////////////
//		 StreamableHandle = GThread::GetResourceLoading() << ObjectPath;
//		 La(&StreamableHandle);
//	 }
//
//
//	 8.ͼ���߳�(ThreadGraphManage)
//		 ͼ���߳���UE4ʹ��Ƶ����ߵ��̣߳�������ʵ���̵߳�ǰ�����񣬱���UE4�߳�ϲ������������ʾһ�¸��̵߳�ʹ�ü���.
//
//		 ͬ�����߳�Ҳ�ǰ���Bind��Create
//
//		 BindXXX : ֻ�������߳�
//
//		 TArray<FGraphEventRef > ArrayEventRef;
//	 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 ArrayEventRef.SetNum(5);
//		 ArrayEventRef[0] = GThread::GetGraph().BindUObject(this, &AThreadTestCharacter::T1, 777);
//		 ArrayEventRef[1] = GThread::GetGraph().BindRaw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//		 ArrayEventRef[2] = GThread::GetGraph().BindSP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//		 ArrayEventRef[3] = GThread::GetGraph().BindUFunction(this, TEXT("T2"), 123, FString("T22222"));
//		 ArrayEventRef[4] = GThread::GetGraph().BindLambda([](FString Mes)
//		 {
//			 ThreadP(Mes);
//		 }, "Lambda");
//
//		 //GThread::GetGraph().Wait(ArrayEventRef[0]);
//		 FGraphEventArray ArrayEvent;
//		 for (auto &Tmp : ArrayEventRef)
//		 {
//			 ArrayEvent.Add(Tmp);
//		 }
//		 //�������õȴ���Щ�߳�����������ִ���Լ�
//		 GThread::GetGraph().Wait(ArrayEvent);
//		 ThreadP("Wait-oK");
//	 }
//	 CreateXXX �������߳�
//
//		 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		 GThread::GetGraph().CreateUObject(this, &AThreadTestCharacter::T1, 777);
//		 GThread::GetGraph().CreateRaw(&MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//		 GThread::GetGraph().CreateSP(MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//		 GThread::GetGraph().CreateUFunction(this, TEXT("T2"), 123, FString("T22222"));
//		 GThread::GetGraph().CreateLambda([](FString Mes)
//		 {
//			 ThreadP(Mes);
//		 }, "Lambda");
//	 }
//	 ͬ����Ҳ���Է����¼����ã���������ͼ���̵߳ȴ�������
//
//
//
//		 9.����ͼ���߳�
//		 ����֮�⻹�к����͵�ͼ���̣߳�����ʹ�ø���ǿ�󣬿��ԶԵ����¼����еȴ�����������ʾһ��
//
//		 TArray<FGraphEventRef > ArrayEventRef;
//	 void AThreadTestCharacter::BeginPlay()
//	 {
//		 Super::BeginPlay();
//
//		auto A =  CALL_THREAD_UOBJECT(NULL, ENamedThreads::AnyThread, this, &AThreadTestCharacter::T1, 777);
//       //�ȴ�A
//		auto B =  CALL_THREAD_Raw(A, ENamedThreads::AnyThread, &MyStruct1, &FMyStruct::Hello, FString("Hello~"));
//		auto C =  CALL_THREAD_SP(NULL, ENamedThreads::AnyThread, MyStructSP1.ToSharedRef(), &FMyStructSP::HelloSP, FString("HelloSP~"));
//		auto D =  CALL_THREAD_UFunction(NULL, ENamedThreads::AnyThread, this, TEXT("T2"), 123, FString("T22222"));
//		auto E =  CALL_THREAD_Lambda(, NULL, ENamedThreads::AnyThread, [](FString Mes)
//		 {
//			 ThreadP(Mes);
//		 }, "Lambda");
//	 }
//
//
//	 �ã�������UE4SimpleThread�������ϸ�̳̣�ϣ���ý̳��ܶ����а���
#pragma endregion Course

#include "CoreMinimal.h"
#include "Core/Manage/ThreadProxyManage.h"
#include "Core/Manage/ThreadTaskManage.h"
#include "Core/Manage/ThreadAbandonableManage.h"
#include "Core/Manage/CoroutinesManage.h"
#include "Core/Manage/ResourceLoadingManage.h"
#include "Core/Manage/ThreadGraphManage.h"
#include "Tickable.h"

//�̵߳��ܹ���
namespace TM
{
	//FThreadManagement ���̰߳�ȫ�ģ������׳�������
	class SIMPLETHREAD_API FThreadManagement : public TSharedFromThis<FThreadManagement>, public FTickableGameObject
	{
	public:
		static TSharedRef<FThreadManagement> Get();

		//��Ҫ�ֶ�ɾ���õ���
		static void Destroy();

		//~Tick
	private:
		//�����߳���Ϊ����
		virtual void Tick(float DeltaTime);
		virtual TStatId GetStatId() const;

	public:
		static FThreadProxyManage		&GetProxy() { return Get()->ThreadProxyManage; }
		static FThreadTaskManagement	&GetTask() { return Get()->ThreadTaskManagement; }
		static FThreadAbandonableManage &GetAbandonable() { return Get()->ThreadAbandonableManage; }
		static FCoroutinesManage		&GetCoroutines() { return Get()->CoroutinesManage; }
		static FThreadGraphManage		&GetGraph() { return Get()->ThreadGraphManage; }
		static FResourceLoadingManage	&GetResourceLoading() { return Get()->ResourceLoadingManage; }

	protected:
		//�Զ����̴߳��������Լ�ֱ�ӵĴ����߳�
		FThreadProxyManage ThreadProxyManage;

		//�Զ�����̳߳أ��������̳߳��ڶ���������ִ��
		FThreadTaskManagement ThreadTaskManagement;

		//��UE4�̳߳���ֱ��ȡ�߳�ִ��
		FThreadAbandonableManage ThreadAbandonableManage;

		//Э��
		FCoroutinesManage CoroutinesManage;

		//�߳�ͼ��
		FThreadGraphManage ThreadGraphManage;

		//��Դ��ȡ
		FResourceLoadingManage ResourceLoadingManage;
	private:
		static TSharedPtr<FThreadManagement> ThreadManagement;
	};
}
using namespace TM;

typedef TM::FThreadManagement GThread;
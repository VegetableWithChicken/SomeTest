#pragma once
#include "Misc/ScopeLock.h"
#include "Abandonable/SimpleAbandonable.h"
#include "Async/TaskGraphInterfaces.h"

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

#define DDD(...) __VA_ARGS__

//�����Ǻ��װ
#if PLATFORM_WINDOWS
	#include <iostream>
	#include <thread>
	#define CPUThreadNumber std::thread::hardware_concurrency()
#else
#if PLATFORM_LINUX
	#define CPUThreadNumber 12
#else
#if PLATFORM_MAC
	#define CPUThreadNumber 12
#endif
#endif
#endif

#define MUTEX_LOCL FScopeLock ScopeLock(&Mutex) 

//�첽
#define USE_UE_THREAD_POOL_ASYNCTASK(ThreadDelegate) \
(new FAutoDeleteAsyncTask<FSimpleAbandonable>(ThreadDelegate))->StartBackgroundTask()

#define ASYNCTASK_UOBJECT(Object,...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateUObject(Object,__VA_ARGS__))

#define ASYNCTASK_Raw(Object,...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateRaw(Object,__VA_ARGS__))

#define ASYNCTASK_SP(Object,...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateSP(Object,__VA_ARGS__))

#define ASYNCTASK_Lambda(...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define ASYNCTASK_UFunction(Object,...) \
USE_UE_THREAD_POOL_ASYNCTASK(FSimpleDelegate::CreateUFunction(Object,__VA_ARGS__))

//ͬ��
#define USE_UE_THREAD_POOL_SYNCTASK(ThreadDelegate) \
{FAsyncTask<FSimpleAbandonable> *SimpleAbandonable = new FAsyncTask<FSimpleAbandonable>(ThreadDelegate); \
SimpleAbandonable->StartBackgroundTask(); \
SimpleAbandonable->EnsureCompletion(); \
delete SimpleAbandonable; }

#define SYNCTASK_UOBJECT(Object,...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateUObject(Object,__VA_ARGS__))

#define SYNCTASK_Raw(Object,...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateRaw(Object,__VA_ARGS__))

#define SYNCTASK_SP(Object,...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateSP(Object,__VA_ARGS__))

#define SYNCTASK_Lambda(...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define SYNCTASK_UFunction(Object,...) \
USE_UE_THREAD_POOL_SYNCTASK(FSimpleDelegate::CreateUFunction(Object,__VA_ARGS__))

//�����߳� ��������ǰ������
#define CALL_THREAD(OtherTask,CallThreadName,InTaskDeletegate) \
FSimpleDelegateGraphTask::CreateAndDispatchWhenReady(InTaskDeletegate,TStatId(),OtherTask,CallThreadName);

#define CALL_THREAD_UOBJECT(OtherTask,CallThreadName,Object,...) \
CALL_THREAD(OtherTask,CallThreadName,FSimpleDelegate::CreateUObject(Object,__VA_ARGS__))

#define CALL_THREAD_Raw(OtherTask,CallThreadName,Object,...) \
CALL_THREAD(OtherTask,CallThreadName,FSimpleDelegate::CreateRaw(Object,__VA_ARGS__))

#define CALL_THREAD_SP(OtherTask,CallThreadName,Object,...) \
CALL_THREAD(OtherTask,CallThreadName,FSimpleDelegate::CreateSP(Object,__VA_ARGS__))

#define CALL_THREAD_Lambda(OtherTask,CallThreadName,...) \
CALL_THREAD(OtherTask,CallThreadName,FSimpleDelegate::CreateLambda(__VA_ARGS__))

#define CALL_THREAD_UFunction(OtherTask,CallThreadName,Object,...) \
CALL_THREAD(CallThreadName,FSimpleDelegate::CreateUFunction(Object,__VA_ARGS__))


#define WAITING_OTHER_THREADS_COMPLETED(EventRef) \
FTaskGraphInterface::Get().WaitUntilTaskCompletes(EventRef);

#define WAITING_OTHER_THREADS_COMPLETED_MULTI(EventRef) \
FTaskGraphInterface::Get().WaitUntilTasksComplete(EventRef);

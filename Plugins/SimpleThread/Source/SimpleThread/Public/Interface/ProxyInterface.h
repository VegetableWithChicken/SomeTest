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
#include "Core/SimpleThreadType.h"

//�����̵߳Ľӿ��࣬�ṩ�˻����ķ���
class SIMPLETHREAD_API IThreadProxy : public TSharedFromThis<IThreadProxy>
{
public:
	IThreadProxy();
	virtual ~IThreadProxy(){}

	//������ȫ�߳�
	virtual void CreateSafeThread() = 0;

	//�����߳�
	virtual void WakeupThread() = 0;

	//�߳��Ƿ񱻹���
	virtual bool IsSuspend() = 0;

	//�������̵߳ȴ�֪����ǰ�������
	virtual void WaitAndCompleted() = 0;

	//���������߳�
	virtual void BlockingAndCompletion() = 0;

	//��Ҫ����ִ�д���
	FORCEINLINE FSimpleDelegate &GetThreadDelegate() { return ThreadDelegate; }

	//һ�����ڼ��ӵľ��
	FORCEINLINE FThreadHandle GetThreadHandle() { return SimpleThreadHandle; }
protected:

	//����ʵ��
	FSimpleDelegate ThreadDelegate;

private:
	//���ʵ����Ψһ�������ط�����������
	TSharedPtr<FSimpleThreadHandle> SimpleThreadHandle;
};
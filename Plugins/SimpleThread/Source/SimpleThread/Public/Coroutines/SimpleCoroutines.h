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

//Э�̵�����
struct SIMPLETHREAD_API FCoroutinesRequest
{
	FCoroutinesRequest(float InIntervalTime);

	//�Ƿ��������
	bool bCompleteRequest;

	//ÿһ֡��ʱ����
	float IntervalTime;
};

//Э�̽ӿڶ���
class SIMPLETHREAD_API ICoroutinesObject :public TSharedFromThis<ICoroutinesObject>
{
	friend class ICoroutinesContainer;
public:
	ICoroutinesObject();
	virtual ~ICoroutinesObject(){}

	bool operator==(const ICoroutinesObject& SimpleThreadHandle)
	{
		return this->Handle == SimpleThreadHandle.Handle;
	}

	//����Э��
	FORCEINLINE void Awaken() { bAwaken = true; }
protected:

	virtual void Update(FCoroutinesRequest &CoroutinesRequest) = 0;

protected:

	//Э�̶�������������洢��Э�̶���
	static TArray<TSharedPtr<ICoroutinesObject>> Array;
	uint8 bAwaken : 1;
	FSimpleThreadHandle Handle;
};
//Э�̾��
typedef TWeakPtr<ICoroutinesObject> FCoroutinesHandle;

//Э�̶���
class SIMPLETHREAD_API FCoroutinesObject :public ICoroutinesObject
{
public:
	FCoroutinesObject(const FSimpleDelegate &InSimpleDelegate);
	FCoroutinesObject(float InTotalTime,const FSimpleDelegate &InSimpleDelegate);

	//һ��ע�� ����ÿ֡����
	virtual void Update(FCoroutinesRequest &CoroutinesRequest) final;
private:

	//ע����Ҫ�Ĵ���
	FSimpleDelegate SimpleDelegate;

	//�ܹ���Ҫ�ȴ���ʱ��
	const float TotalTime;

	//��ǰʱ�䣬��Ҫ���ڼ�¼ʱ��
	float RuningTime;
};
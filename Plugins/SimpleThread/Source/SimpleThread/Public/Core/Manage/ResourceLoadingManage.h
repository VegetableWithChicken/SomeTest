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
#include "Interface/ThreadManageInterface.h"
#include "Core/Manage/ManageBase/ThreadManageBase.h"

//Create ���԰��첽������֪ͨ���¼�
struct SIMPLETHREAD_API FResourceLoadingManage :FTreadTemplateBase<IStreamableContainer,TSharedPtr<struct FStreamableHandle>>
{
	typedef FTreadTemplateBase<
		IStreamableContainer,
		TSharedPtr<struct FStreamableHandle>> Super;

	FResourceLoadingManage();
	~FResourceLoadingManage();

protected:

	//������Դ·��
	virtual void SetObjectPath(const TArray<FSoftObjectPath> &InObjectPath) final;

	//��ȡ��Դ·��
	virtual TArray<FSoftObjectPath> &GetObjectPath() final;

	//��ȡ������
	virtual FStreamableManager *GetStreamableManager()final;

private:
	TArray<FSoftObjectPath> SoftObjectPath;
	FStreamableManager *StreamableManager;
};

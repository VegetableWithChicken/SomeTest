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
#include "ManageBase/ThreadManageBase.h"

//Bind   �����̲߳��Ұ����񣬵���ִ�� ͨ�� Join��Detach���������첽ִ�л���ͬ��ִ��
//Create �����̲߳���ֱ��ִ������,�����ݵ��첽��ʽ
class SIMPLETHREAD_API FThreadProxyManage : public FTreadTemplate<IThreadProxyContainer, FThreadHandle>
{
public:
	~FThreadProxyManage();

	//ͬ��
	bool Join(FThreadHandle Handle);

	//�첽
	bool Detach(FThreadHandle Handle);

	//�Ƿ����ͬ��
	EThreadState Joinable(FThreadHandle Handle);
};
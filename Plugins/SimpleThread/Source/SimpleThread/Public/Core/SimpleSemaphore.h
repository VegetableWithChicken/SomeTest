#pragma once
#include "CoreMinimal.h"
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
//��װUE4�¼���Ϊ�˸��õĻ�ȡ�Ƿ����״̬
class FEvent;
struct FSimpleSemaphore
{
	FSimpleSemaphore();
	~FSimpleSemaphore();

	//����
	void Wait();

	//�����ʱ��
	void Wait(uint32 WaitTime, const bool bIgnoreThreadIdleStats = false);

	//����
	void Trigger();

	//�Ƿ���
	FORCEINLINE bool IsWait() { return bWait; }
private:
	FEvent *Event;
	uint8 bWait : 1;
};
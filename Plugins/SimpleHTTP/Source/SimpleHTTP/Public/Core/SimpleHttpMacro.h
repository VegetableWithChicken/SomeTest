/*
�������ַ���������ʹ�ñ��ײ��
 DocURL��			https://zhuanlan.zhihu.com/p/82195344

 �������ַ������ο�����ǰ�Ĳ��
 MarketplaceURL :   https://www.aboutcg.org/courseDetails/682/introduce

 ������˽�������UE4�̳���ο���
 URL :				https://zhuanlan.zhihu.com/p/60117613

 �����ϵͳ�˽���լϵ�н̳��Լ���ز���������� ���Թ�ע�ҵĲ���
 URL :				http://renzhai.net/

 ������˽�������һ�ڵĿγ̰��ſ��� ������΢�Ź��ں����� ��լ ��ע���� ���ǻ����ͺܶ฻�м���������

 ���˲���            https://weibo.com/BZRZ/profile?s=6cm7D0  //������ʹ�16�굽���� ��������û��ô�ù� �Ժ�˵���������������� �ȷ�������
 */

#pragma once
#include "HTTP/SimpleHTTPActionRequest.h"


#define DEFINITION_HTTP_TYPE(VerbString,Content) \
HttpReuest->SetURL(URL);\
HttpReuest->SetVerb(TEXT(##VerbString));\
HttpReuest->SetHeader(TEXT("Content-Type"), TEXT(##Content)); 

#define REQUEST_BIND_FUN(RequestClass) \
Request \
<< FHttpRequestHeaderReceivedDelegate::CreateRaw(this, &##RequestClass##::HttpRequestHeaderReceived)\
<< FHttpRequestProgressDelegate::CreateRaw(this, &##RequestClass##::HttpRequestProgress)\
<< FHttpRequestCompleteDelegate::CreateRaw(this, &##RequestClass##::HttpRequestComplete);

#define SIMPLE_HTTP_REGISTERED_REQUEST_BP(TYPE) \
auto Handle = RegisteredHttpRequest(TYPE, \
	BPResponseDelegate.SimpleHttpRequestCompleteDelegate, \
	BPResponseDelegate.SimpleHttpRequestProgressDelegate, \
	BPResponseDelegate.SimpleHttpRequestHeaderReceivedDelegate, \
	BPResponseDelegate.AllRequestCompleteDelegate)

#define SIMPLE_HTTP_REGISTERED_REQUEST(TYPE) \
auto Handle = RegisteredHttpRequest(TYPE, \
	BPResponseDelegate.SimpleCompleteDelegate, \
	BPResponseDelegate.SimpleSingleRequestProgressDelegate, \
	BPResponseDelegate.SimpleSingleRequestHeaderReceivedDelegate, \
	BPResponseDelegate.AllTasksCompletedDelegate)

void RequestPtrToSimpleRequest(FHttpRequestPtr Request, FSimpleHttpRequest &SimpleHttpRequest);
void ResponsePtrToSimpleResponse(FHttpResponsePtr Response, FSimpleHttpResponse &SimpleHttpResponse);
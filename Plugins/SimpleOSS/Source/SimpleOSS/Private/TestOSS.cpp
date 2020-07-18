// Fill out your copyright notice in the Description page of Project Settings.


#include "TestOSS.h"
#include "string"
#include "OSSThirdParty/include/alibabacloud/oss/OssClient.h"
//#include <OSSThirdParty/include/alibabacloud/oss/client/ClientConfiguration.h>
using namespace AlibabaCloud::OSS;
//https://help.aliyun.com/document_detail/106557.html?spm=a2c4g.11186623.6.1021.142927f32uOqDb

TestOSS::~TestOSS()
{
}

//�˺���Ϣ
std::string AccessKeyId = "LTAI4G3rcebBgb94ddzFiApX";
std::string AccessKeySecret = "ZEkp9OesH1cmJZClwepjkwVdFhqbk1";
std::string EndPoint = "oss-cn-beijing.aliyuncs.com";
std::string BucketName = "smartuiloss";

//����bucket
//int32 OSSTest::MainOSS()
//{
//	std::string AccessKeyId = "LTAI4G3rcebBgb94ddzFiApX";
//	std::string AccessKeySecret = "ZEkp9OesH1cmJZClwepjkwVdFhqbk1";
//	std::string EndPoint = "oss-cn-beijing.aliyuncs.com";
//	std::string BucketName = "smartuiloss";
//
//	//��ʼ��������Դ
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//
//	//ָ���´���bucket�����ơ��洢�����ACL
//	CreateBucketRequest Request(BucketName, StorageClass::IA, CannedAccessControlList::PublicReadWrite);
//
//	auto Outcome = Client.CreateBucket(Request);
//
//	if (!Outcome.isSuccess())
//	{
//		/* �쳣���� */
//		std::cout << "CreateBucket fail" <<
//			",code:" << Outcome.error().Code() <<
//			",message:" << Outcome.error().Message() <<
//			",requestId:" << Outcome.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//
//	//�ͷ��������Դ
//	ShutdownSdk();
//
//	return 0;
//}

//�������ٴ���
//int32 OSSTest::MainOSS()
//{
//	//��ʼ��������Դ
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	/* �������ӳ�����Ĭ��Ϊ16����*/
//	conf.maxConnections = 20;
//
//	/* ��������ʱʱ�䣬��ʱû���յ����ݾ͹ر����ӣ�Ĭ��Ϊ10000ms��*/
//	conf.requestTimeoutMs = 8000;
//
//	/* ���ý������ӵĳ�ʱʱ�䣬Ĭ��Ϊ5000ms��*/
//	conf.connectTimeoutMs = 8000;
//
//	auto sendrateLimiter = std::make_shared<TestOSS>();
//	auto recvrateLimiter = std::make_shared<TestOSS>();
//	conf.sendRateLimiter = sendrateLimiter;
//	conf.recvRateLimiter = recvrateLimiter;
//
//	OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* �����������٣���λKB/s����*/
//	recvrateLimiter->setRate(256);
//
//	/* �����ϴ����٣���λKB/s����*/
//	sendrateLimiter->setRate(256);
//
//	/* �ϴ��ļ���*/
//	auto outcome = Client.PutObject(BucketName, "Test.zip", "C:/Users/Smartuil/Desktop/SomeTest/OSS/Test.zip");
//
//	/* �ϴ������и����ϴ����٣���λKB/s����*/
//	sendrateLimiter->setRate(300);
//
//	//�ͷ��������Դ
//	ShutdownSdk();
//
//	return 0;
//}

////�������Բ���
//int32 OSSTest::MainOSS()
//{
//	/* ��ʼ���������Դ��*/
//	InitializeSdk();
//
//	ClientConfiguration conf;
//
//	/* ����ʧ���������Դ�����Ĭ��Ϊ3�Ρ�*/
//	auto defaultRetryStrategy = std::make_shared<UserRetryStrategy>(5);
//	conf.retryStrategy = defaultRetryStrategy;
//
//	OssClient client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* �ͷ��������Դ��*/
//	ShutdownSdk();
//	return 0;
//}
//
//bool UserRetryStrategy::shouldRetry(const Error & error, long attemptedRetries) const
//{
//	if (attemptedRetries >= m_maxRetries)
//		return false;
//
//	long responseCode = error.Status();
//
//	//http code
//	if ((responseCode == 403 && error.Message().find("RequestTimeTooSkewed") != std::string::npos) ||
//		(responseCode > 499 && responseCode < 599)) {
//		return true;
//	}
//	else {
//		switch (responseCode)
//		{
//		case CURLE_COULDNT_CONNECT:
//		case CURLE_PARTIAL_FILE:
//		case CURLE_WRITE_ERROR:
//		case CURLE_OPERATION_TIMEDOUT:
//		case CURLE_GOT_NOTHING:
//		case CURLE_SEND_ERROR:
//		case CURLE_RECV_ERROR:
//			return true;
//		default:
//			break;
//		};
//	}
//
//	return false;
//}
//
//long UserRetryStrategy::calcDelayTimeMs(const Error & error, long attemptedRetries) const
//{
//	UNUSED_PARAM(error);
//	return (1 << attemptedRetries) * m_scaleFactor;
//}

void print(const std::string &NewStr)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, NewStr.c_str());
	}
}

//�洢�ռ�
int32 OSSTest::MainOSS()
{
	//��ʼ��������Դ
	InitializeSdk();

	ClientConfiguration conf;
	OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, conf);

	/* �оٴ洢�ռ� */
	ListBucketsRequest request;

	auto outcome = Client.ListBuckets(request);

	if (outcome.isSuccess()) {
		/* ��ӡ�洢�ռ���Ϣ */
		std::cout << " success, and bucket count is" << outcome.result().Buckets().size() << std::endl;
		std::cout << "Bucket name is" << std::endl;
		for (auto result : outcome.result().Buckets())
		{
			std::cout << result.Name() << std::endl;
			print(result.Name());
		}
	}
	else {
		/* �쳣���� */
		std::cout << "ListBuckets fail" <<
			",code:" << outcome.error().Code() <<
			",message:" << outcome.error().Message() <<
			",requestId:" << outcome.error().RequestId() << std::endl;
		ShutdownSdk();
		return -1;
	}

	/* ���ô洢�ռ����Ȩ�� */
	SetBucketAclRequest request2(BucketName, CannedAccessControlList::PublicRead);
	auto outcome2 = Client.SetBucketAcl(request2);

	/* ��ȡ�洢�ռ���� */
	GetBucketLocationRequest request3(BucketName);
	auto outcome3 = Client.GetBucketLocation(request3);

	if (outcome3.isSuccess()) {
		print(outcome3.result().Location());
	}

	/* �жϴ洢�ռ��Ƿ���� */
	auto outcome4 = Client.DoesBucketExist(BucketName);

	if (outcome4) {
		std::cout << " The Bucket exists" << std::endl;
		print(" The Bucket exists");
	}
	else {
		std::cout << "The Bucket does not exist" << std::endl;
		print("The Bucket does not exist");
	}

	/* ָ��Ҫɾ����bucket���� */
	DeleteBucketRequest request5("smartuilnewoss");

	/* ɾ��bucket */
	auto outcome5 = Client.DeleteBucket(request5);


	/* ���������߸���ģʽ */
	SetBucketRequestPaymentRequest request6(BucketName);
	request6.setRequestPayer(RequestPayer::Requester);

	auto outcome6 = Client.SetBucketRequestPayment(request6);

	/* ��ȡ�����߸���ģʽ */
	GetBucketRequestPaymentRequest request7(BucketName);
	auto outcome7 = Client.GetBucketRequestPayment(request7);

	auto cc = outcome7.result().Payer();

	//�ͷ��������Դ
	ShutdownSdk();

	return 0;
}
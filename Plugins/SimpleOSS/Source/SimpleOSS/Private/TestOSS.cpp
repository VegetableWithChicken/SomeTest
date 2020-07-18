// Fill out your copyright notice in the Description page of Project Settings.


#include "TestOSS.h"
#include "string"
#include "OSSThirdParty/include/alibabacloud/oss/OssClient.h"

using namespace AlibabaCloud::OSS;

TestOSS::TestOSS()
{
}

TestOSS::~TestOSS()
{
}

int32 OSSTest::MainOSS()
{
	std::string AccessKeyId = "LTAI4G3rcebBgb94ddzFiApX";
	std::string AccessKeySecret = "ZEkp9OesH1cmJZClwepjkwVdFhqbk1";
	std::string EndPoint = "oss-cn-beijing.aliyuncs.com";
	std::string BucketName = "smartuilnewoss";

	//��ʼ��������Դ
	InitializeSdk();

	ClientConfiguration conf;
	OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, conf);

	//ָ���´���bucket�����ơ��洢�����ACL
	CreateBucketRequest Request(BucketName, StorageClass::IA, CannedAccessControlList::PublicReadWrite);

	auto Outcome = Client.CreateBucket(Request);

	if (!Outcome.isSuccess())
	{
		/* �쳣���� */
		std::cout << "CreateBucket fail" <<
			",code:" << Outcome.error().Code() <<
			",message:" << Outcome.error().Message() <<
			",requestId:" << Outcome.error().RequestId() << std::endl;
		ShutdownSdk();
		return -1;
	}

	//�ͷ��������Դ
	ShutdownSdk();

	return 0;
}

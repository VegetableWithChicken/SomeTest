// Fill out your copyright notice in the Description page of Project Settings.


#include "TestOSS.h"
#include "string"
#include "OSSThirdParty/include/alibabacloud/oss/OssClient.h"
#include "Misc/FileHelper.h"
#include "fstream"

//#include <OSSThirdParty/include/alibabacloud/oss/client/ClientConfiguration.h>
using namespace AlibabaCloud::OSS;
//https://help.aliyun.com/document_detail/106557.html?spm=a2c4g.11186623.6.1021.142927f32uOqDb
#if PLATFORM_WINDOWS
#pragma optimize("", off)
#endif

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

void print(const FString &NewStr)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, NewStr);
	}
}

//�洢�ռ�
//int32 OSSTest::MainOSS()
//{
//	//��ʼ��������Դ
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient Client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* �оٴ洢�ռ� */
//	ListBucketsRequest request;
//
//	auto outcome = Client.ListBuckets(request);
//
//	if (outcome.isSuccess()) {
//		/* ��ӡ�洢�ռ���Ϣ */
//		std::cout << " success, and bucket count is" << outcome.result().Buckets().size() << std::endl;
//		std::cout << "Bucket name is" << std::endl;
//		for (auto result : outcome.result().Buckets())
//		{
//			std::cout << result.Name() << std::endl;
//			print(result.Name());
//		}
//	}
//	else {
//		/* �쳣���� */
//		std::cout << "ListBuckets fail" <<
//			",code:" << outcome.error().Code() <<
//			",message:" << outcome.error().Message() <<
//			",requestId:" << outcome.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//
//	/* ���ô洢�ռ����Ȩ�� */
//	SetBucketAclRequest request2(BucketName, CannedAccessControlList::PublicRead);
//	auto outcome2 = Client.SetBucketAcl(request2);
//
//	/* ��ȡ�洢�ռ���� */
//	GetBucketLocationRequest request3(BucketName);
//	auto outcome3 = Client.GetBucketLocation(request3);
//
//	if (outcome3.isSuccess()) {
//		print(outcome3.result().Location());
//	}
//
//	/* �жϴ洢�ռ��Ƿ���� */
//	auto outcome4 = Client.DoesBucketExist(BucketName);
//
//	if (outcome4) {
//		std::cout << " The Bucket exists" << std::endl;
//		print(" The Bucket exists");
//	}
//	else {
//		std::cout << "The Bucket does not exist" << std::endl;
//		print("The Bucket does not exist");
//	}
//
//	/* ָ��Ҫɾ����bucket���� */
//	DeleteBucketRequest request5("smartuilnewoss");
//
//	/* ɾ��bucket */
//	auto outcome5 = Client.DeleteBucket(request5);
//
//
//	/* ���������߸���ģʽ */
//	SetBucketRequestPaymentRequest request6(BucketName);
//	request6.setRequestPayer(RequestPayer::Requester);
//
//	auto outcome6 = Client.SetBucketRequestPayment(request6);
//
//	/* ��ȡ�����߸���ģʽ */
//	GetBucketRequestPaymentRequest request7(BucketName);
//	auto outcome7 = Client.GetBucketRequestPayment(request7);
//
//	auto cc = outcome7.result().Payer();
//
//	//�ͷ��������Դ
//	ShutdownSdk();
//
//	return 0;
//}

int64_t getFileSize(const std::string& file)
{
	std::fstream f(file, std::ios::in | std::ios::binary);
	f.seekg(0, f.end);
	int64_t size = f.tellg();
	f.close();
	return size;
}

//int32 OSSTest::MainOSS()
//{
//	TArray<uint8> StringArray;
//	FFileHelper::LoadFileToArray(StringArray, *FString("C:/Users/Smartuil/Desktop/SomeTest/OSS/Test.txt"));
//
//	std::string ObjectName = "Test.txt";
//	InitializeSdk();
//	ClientConfiguration conf;
//	OssClient client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//	std::shared_ptr<std::iostream> content = std::make_shared<std::stringstream>();
//	*content << "Thank you for using Alibaba Cloud Object Storage Service!";
//	PutObjectRequest request(BucketName, ObjectName, content);
//
//	/*����ѡ����μ�����ʾ�����ô洢���ͼ�����Ȩ��ACL* /
//	//request.MetaData().addHeader("x-oss-object-acl", "private");
//	//request.MetaData().addHeader("x-oss-storage-class", "Standard");
//
//	/* �ϴ��ļ� */
//	auto outcome = client.PutObject(request);
//
//	if (!outcome.isSuccess()) {
//		/* �쳣���� */
//		std::cout << "PutObject fail" <<
//			",code:" << outcome.error().Code() <<
//			",message:" << outcome.error().Message() <<
//			",requestId:" << outcome.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//
//	std::string ObjectName2 = "GTAVTool.zip";
//	std::string UploadFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS/GTAVTool.zip";
//	std::string CheckpointFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS/";
//
//	/* �ϵ������ϴ� */
//	//UploadObjectRequest request2(BucketName, ObjectName2, UploadFilePath, CheckpointFilePath);
//	//auto outcome2 = client.ResumableUploadObject(request2);
//
//	{
//		//std::vector<PutObjectOutcomeCallable> Callables;
//		//for (int i = 0; i < 4; i++) {
//		//	std::shared_ptr<std::iostream> content2 = std::make_shared<std::fstream>(
//		//		"C:/Users/Smartuil/Desktop/SomeTest/OSS/GTAVTool2.zip", 
//		//		std::ios::in | std::ios::binary);
//
//		//	PutObjectRequest request3(BucketName, ObjectName2, content2);
//		//	auto outcomeCallable = client.PutObjectCallable(request3);
//		//	Callables.emplace_back(std::move(outcomeCallable));
//		//}
//		//std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//
//		///* �ж��ϴ� */
//		//client.DisableRequest();
//
//		//for (size_t i = 0; i < Callables.size(); i++) {
//		//	auto outcome3 = Callables[i].get();
//		//	if (outcome3.error().Code() == "ClientError:100002" ||
//		//		outcome3.error().Code() == "ClientError:200042") {
//		//		std::cout << "disable putobject success" << std::endl;
//		//		print("disable putobject success");
//		//	}
//		//}
//	}
//
//	{
//		InitiateMultipartUploadRequest initUploadRequest(BucketName, ObjectName2);
//		/*����ѡ����μ�����ʾ�����ô洢���� */
//		//initUploadRequest.MetaData().addHeader("x-oss-storage-class", "Standard");
//
//		/* ��ʼ����Ƭ�ϴ��¼� */
//		auto uploadIdResult = client.InitiateMultipartUpload(initUploadRequest);
//		auto uploadId = uploadIdResult.result().UploadId();
//		std::string fileToUpload = "C:/Users/Smartuil/Desktop/SomeTest/OSS/GTAVTool2.zip";
//		int64_t partSize = 1024 * 1024;
//		PartList partETagList;
//		auto fileSize = getFileSize(fileToUpload);
//		int32 partCount = static_cast<int32>(fileSize / partSize);
//		/* �����Ƭ���� */
//		if (fileSize % partSize != 0) {
//			partCount++;
//		}
//
//		/* ��ÿһ����Ƭ�����ϴ� */
//		for (int32 i = 1; i <= partCount; i++) {
//			auto skipBytes = partSize * (i - 1);
//			auto size = (partSize < fileSize - skipBytes) ? partSize : (fileSize - skipBytes);
//			std::shared_ptr<std::iostream> content4 = std::make_shared<std::fstream>(fileToUpload, std::ios::in | std::ios::binary);
//			content4->seekg(skipBytes, std::ios::beg);
//
//			UploadPartRequest uploadPartRequest(BucketName, ObjectName2, content4);
//			uploadPartRequest.setContentLength(size);
//			uploadPartRequest.setUploadId(uploadId);
//			uploadPartRequest.setPartNumber(i);
//			auto uploadPartOutcome = client.UploadPart(uploadPartRequest);
//			if (uploadPartOutcome.isSuccess()) {
//				Part part(i, uploadPartOutcome.result().ETag());
//				partETagList.push_back(part);
//			}
//			else {
//				std::cout << "uploadPart fail" <<
//					",code:" << uploadPartOutcome.error().Code() <<
//					",message:" << uploadPartOutcome.error().Message() <<
//					",requestId:" << uploadPartOutcome.error().RequestId() << std::endl;
//			}
//
//		}
//
//		{
//			/* �о����ϴ���Ƭ��Ĭ���о�1000����Ƭ */
//			ListPartsRequest listuploadrequest(BucketName, ObjectName2);
//			listuploadrequest.setMaxParts(2);
//			listuploadrequest.setUploadId(uploadId);
//			ListPartsOutcome listuploadresult;
//			do {
//				listuploadresult = client.ListParts(listuploadrequest);
//				if (!listuploadresult.isSuccess()) {
//					/* �쳣���� */
//					std::cout << "ListParts fail" <<
//						",code:" << listuploadresult.error().Code() <<
//						",message:" << listuploadresult.error().Message() <<
//						",requestId:" << listuploadresult.error().RequestId() << std::endl;
//					break;
//				}
//				else {
//					for (const auto& part : listuploadresult.result().PartList()) {
//						std::cout << "part" <<
//							",name:" << part.PartNumber() <<
//							",size:" << part.Size() <<
//							",etag:" << part.ETag() <<
//							",lastmodify time:" << part.LastModified() << std::endl;
//						//print(std::to_string(part.PartNumber()));
//						//print(std::to_string(part.Size()));
//						//print(part.ETag());
//						//print(part.LastModified());
//
//					}
//				}
//				listuploadrequest.setPartNumberMarker(listuploadresult.result().NextPartNumberMarker());
//			} while (listuploadresult.result().IsTruncated());
//		}
//
//		{
//			/* �о����ϴ��¼���Ĭ���о�1000����Ƭ */
//			ListMultipartUploadsRequest listmultiuploadrequest(BucketName);
//			ListMultipartUploadsOutcome listresult;
//			do {
//				listresult = client.ListMultipartUploads(listmultiuploadrequest);
//				if (!listresult.isSuccess()) {
//					/* �쳣���� */
//					std::cout << "ListMultipartUploads fail" <<
//						",code:" << listresult.error().Code() <<
//						",message:" << listresult.error().Message() <<
//						",requestId:" << listresult.error().RequestId() << std::endl;
//					break;
//				}
//				else {
//					for (const auto& part : listresult.result().MultipartUploadList()) {
//						std::cout << "part" <<
//							",name:" << part.Key <<
//							",uploadid:" << part.UploadId <<
//							",initiated time:" << part.Initiated << std::endl;
//						print(part.Key);
//						print(part.UploadId);
//						print(part.Initiated);
//					}
//				}
//				listmultiuploadrequest.setKeyMarker(listresult.result().NextKeyMarker());
//				listmultiuploadrequest.setUploadIdMarker(listresult.result().NextUploadIdMarker());
//			} while (listresult.result().IsTruncated());
//		}
//
//		{
//			/* ��ʼ����Ƭ�ϴ��¼� */
//			auto uploadIdResult2 = client.InitiateMultipartUpload(initUploadRequest);
//			auto uploadId2 = uploadIdResult2.result().UploadId();
//
//			/* ȡ����Ƭ�ϴ� */
//			AbortMultipartUploadRequest  abortUploadRequest(BucketName, ObjectName2, uploadId2);
//			auto abortUploadIdResult = client.AbortMultipartUpload(abortUploadRequest);
//		}
//
//		/* ��ɷ�Ƭ�ϴ� */
//		CompleteMultipartUploadRequest request4(BucketName, ObjectName2);
//		request4.setUploadId(uploadId);
//		request4.setPartList(partETagList);
//		/*����ѡ����μ�����ʾ�����ö�дȨ��ACL */
//		//request.setAcl(CannedAccessControlList::Private);
//
//		auto outcome4 = client.CompleteMultipartUpload(request4);
//
//		if (!outcome4.isSuccess()) {
//			/* �쳣���� */
//			std::cout << "CompleteMultipartUpload fail" <<
//				",code:" << outcome4.error().Code() <<
//				",message:" << outcome4.error().Message() <<
//				",requestId:" << outcome4.error().RequestId() << std::endl;
//			ShutdownSdk();
//			return -1;
//		}
//	}
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//	return 0;
//}

void ProgressCallback(size_t increment, int64_t transfered, int64_t total, void* userData)
{
	std::cout << "ProgressCallback[" << userData << "] => " <<
		increment << " ," << transfered << "," << total << std::endl;
	print(FString::Printf(TEXT("increment = %i,transfered = %i,total = %i"), increment, transfered, total));
}

#include "Core/ThreadCoreMacro.h"

//int32 OSSTest::MainOSS()
//{
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//
//	std::string ObjectName = "GTAVTool.zip";
//	std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(
//		"C:/Users/Smartuil/Desktop/SomeTest/OSS/GTAVTool2.zip", 
//		std::ios::in | std::ios::binary);
//	PutObjectRequest request(BucketName, ObjectName, content);
//
//	TransferProgress progressCallback = { ProgressCallback , nullptr };
//	request.setTransferProgress(progressCallback);
//
//	auto OutLamada = [=]()
//	{
//		/* �ϴ��ļ� */
//		auto outcome = client.PutObject(request);
//		if (!outcome.isSuccess()) {
//			/* �쳣���� */
//
//			ShutdownSdk();
//		}
//	};
//
//	ASYNCTASK_Lambda(OutLamada);
//
//	return 0;
//}

//int32 OSSTest::MainOSS()
//{
//	std::string ObjectName = "GTAVTool.zip";
//	std::string FileNametoSave = "C:/Users/Smartuil/Desktop/SomeTest/OSS/1.zip";
//	std::string DownloadFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS/2.zip";
//	std::string CheckpointFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS";
//
//	/*��ʼ���������Դ*/
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* �첽��ȡ�ļ� */
//	GetObjectRequest request5(BucketName, ObjectName);
//	TransferProgress progressCallback = { ProgressCallback , nullptr };
//	request5.setTransferProgress(progressCallback);
//	request5.setResponseStreamFactory([=]() 
//	{
//		return std::make_shared<std::fstream>(
//			FileNametoSave, 
//			std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); 
//	});
//	auto OutLamada = [=]()
//	{
//		auto outcome = client.GetObject(request5);
//	};
//	ASYNCTASK_Lambda(OutLamada);
//
//
//	/*��ȡ�ļ��������ļ�*/
//	GetObjectRequest request(BucketName, ObjectName);
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//
//	auto outcome = client.GetObject(request);
//
//	if (outcome.isSuccess()) {
//		std::cout << "GetObjectToFile success" << outcome.result().Metadata().ContentLength() << std::endl;
//	}
//	else {
//		/*�쳣����*/
//		std::cout << "GetObjectToFile fail" <<
//			",code:" << outcome.error().Code() <<
//			",message:" << outcome.error().Message() <<
//			",requestId:" << outcome.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//
//	/*��ȡ�ļ��������ڴ�*/
//	GetObjectRequest request2(BucketName, ObjectName);
//	auto outcome2 = client.GetObject(request2);
//
//	/* ��ȡ�ļ� */
//	GetObjectRequest request3(BucketName, ObjectName);
//	/* �������ط�Χ */
//	request3.setRange(0, 1);
//	auto outcome3 = client.GetObject(request3);
//
//	/* �ϵ��������� */
//	DownloadObjectRequest request4(BucketName, ObjectName, DownloadFilePath, CheckpointFilePath);
//	auto outcome4 = client.ResumableDownloadObject(request4);
//
//	/*�ͷ��������Դ*/
//	ShutdownSdk();
//
//	return 0;
//}

//int32 OSSTest::MainOSS()
//{
//	std::string ObjectName = "GTAVTool.zip";
//	std::string FileNametoSave = "C:/Users/Smartuil/Desktop/SomeTest/OSS/1.zip";
//	std::string DownloadFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS/2.zip";
//	std::string CheckpointFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS";
//
//	/*��ʼ���������Դ*/
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//
//
//	SetObjectAclRequest request(BucketName, ObjectName);
//	request.setAcl(CannedAccessControlList::Private);
//	auto outcome = client.SetObjectAcl(request);
//
//	if (!outcome.isSuccess()) {
//		/* �쳣���� */
//		std::cout << "SetObjectAcl fail" <<
//			",code:" << outcome.error().Code() <<
//			",message:" << outcome.error().Message() <<
//			",requestId:" << outcome.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//
//	/* ��ȡ�ļ�����Ȩ�� */
//	GetObjectAclRequest request2(BucketName, ObjectName);
//	auto outcome2 = client.GetObjectAcl(request2);
//	if (!outcome2.isSuccess()) {
//		/* �쳣���� */
//		std::cout << "GetObjectAcl fail" <<
//			",code:" << outcome2.error().Code() <<
//			",message:" << outcome2.error().Message() <<
//			",requestId:" << outcome2.error().RequestId() << std::endl;
//
//		ShutdownSdk();
//		return -1;
//	}
//	else {
//		std::cout << " GetObjectAcl success, Acl:" << outcome2.result().Acl() << std::endl;
//		print(std::to_string(outcome2.result().Acl()));
//	}
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//
//	return 0;
//}


//int32 OSSTest::MainOSS()
//{
//	std::string ObjectName = "GTAVTool.zip";
//	std::string FileNametoSave = "C:/Users/Smartuil/Desktop/SomeTest/OSS/1.zip";
//	std::string DownloadFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS/2.zip";
//	std::string CheckpointFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS";
//
//	/*��ʼ���������Դ*/
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//	/* ����HTTP header */
//	auto meta = ObjectMetaData();
//	meta.setContentType("text/plain");
//	meta.setCacheControl("max-ag e=3");
//
//	//meta.setContentDisposition();
//	//meta.setContentEncoding();
//	//meta.setContentLength();
//	//meta.setExpirationTime();
//
//	/* �����Զ����ļ�Ԫ��Ϣ */
//	meta.UserMetaData()["Hello"] = "No-value";
//
//	std::shared_ptr<std::iostream> content = std::make_shared<std::stringstream>();
//	*content << "Thank you for using Aliyun Object Storage Service!";
//	auto outcome = client.PutObject(BucketName, ObjectName, content, meta);
//
//	if (!outcome.isSuccess()) {
//		/* �쳣���� */
//		std::cout << "PutObject fail" <<
//			",code:" << outcome.error().Code() <<
//			",message:" << outcome.error().Message() <<
//			",requestId:" << outcome.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//
//	/* ��ȡ�ļ��Ĳ���Ԫ��Ϣ */
//	auto outcome2 = client.GetObjectMeta(BucketName, ObjectName);
//
//	if (!outcome2.isSuccess()) {
//		/* �쳣���� */
//		std::cout << "GetObjectMeta fail" <<
//			",code:" << outcome2.error().Code() <<
//			",message:" << outcome2.error().Message() <<
//			",requestId:" << outcome2.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//	else {
//		auto metadata = outcome2.result();
//		std::cout << " get metadata success, ETag:" << metadata.ETag() << "; LastModified:"
//			<< metadata.LastModified() << "; Size:" << metadata.ContentLength() << std::endl;
//		print(metadata.ETag());
//		print(metadata.LastModified());
//		print(std::to_string(metadata.ContentLength()));
//	}
//
//	/* ��ȡ�ļ���ȫ��Ԫ��Ϣ */
//	auto outcome3 = client.HeadObject(BucketName, ObjectName);
//
//	if (!outcome3.isSuccess()) {
//		/* �쳣���� */
//		std::cout << "HeadObject fail" <<
//			",code:" << outcome3.error().Code() <<
//			",message:" << outcome3.error().Message() <<
//			",requestId:" << outcome3.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//	else {
//		auto headMeta = outcome3.result();
//		std::cout << "headMeta success, ContentType:"
//			<< headMeta.ContentType() << "; ContentLength:" << headMeta.ContentLength()
//			<< "; CacheControl:" << headMeta.CacheControl() << std::endl;
//		print(headMeta.ContentType());	
//		print(std::to_string(headMeta.ContentLength()));
//		print(headMeta.CacheControl());
//		print(headMeta.ContentDisposition());
//		print(headMeta.ContentEncoding());
//		print(headMeta.ContentMd5());
//	}
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//	return 0;
//}

static int64_t calculateFolderLength(const OssClient &client, const std::string &bucketName, const std::string &folder)
{
	std::string nextMarker = "";
	int64_t size = 0;
	ListObjectOutcome outcome2;
	do {
		/*�о��ļ�*/
		ListObjectsRequest request(bucketName);
		request.setPrefix(folder);
		request.setMarker(nextMarker);
		outcome2 = client.ListObjects(request);

		if (!outcome2.isSuccess()) {
			/*�쳣����*/
			std::cout << "ListObjects fail" <<
				",code:" << outcome2.error().Code() <<
				",message:" << outcome2.error().Message() <<
				",requestId:" << outcome2.error().RequestId() << std::endl;
			break;
		}

		for (const auto& object : outcome2.result().ObjectSummarys()) {
			size += _atoi64(object.Key().c_str());
		}

		nextMarker = outcome2.result().NextMarker();
	} while (outcome2.result().IsTruncated());

	return size;
}

//int32 OSSTest::MainOSS()
//{
//	std::string ObjectName = "GTAVTool.zip";
//	std::string FileNametoSave = "C:/Users/Smartuil/Desktop/SomeTest/OSS/1.zip";
//	std::string DownloadFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS/2.zip";
//	std::string CheckpointFilePath = "C:/Users/Smartuil/Desktop/SomeTest/OSS";
//
//	/*��ʼ���������Դ*/
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(EndPoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* �о��ļ� */
//	ListObjectsRequest request(BucketName);
//	request.setMaxKeys(200);
//	auto outcome = client.ListObjects(request);
//
//	if (!outcome.isSuccess()) {
//		/* �쳣���� */
//		std::cout << "ListObjects fail" <<
//			",code:" << outcome.error().Code() <<
//			",message:" << outcome.error().Message() <<
//			",requestId:" << outcome.error().RequestId() << std::endl;
//		ShutdownSdk();
//		return -1;
//	}
//	else {
//		for (const auto& object : outcome.result().ObjectSummarys()) {
//			std::cout << "object" <<
//				",name:" << object.Key() <<
//				",size:" << object.Size() <<
//				",lastmodify time:" << object.LastModified() << std::endl;
//			print(object.Key());
//			print(std::to_string(object.Size()));
//			print(object.LastModified());
//		}
//	}
//	std::string keyPrefix = "yourkeyPrefix";
//	{
//		std::string nextMarker = "";
//		ListObjectOutcome outcome4;
//		do {
//			/* �о��ļ� */
//			ListObjectsRequest request2(BucketName);
//			/* ������б�ߣ�/��Ϊ�ļ��еķָ��� */
//			request2.setDelimiter("/");
//			request2.setPrefix(keyPrefix);
//			request2.setMarker(nextMarker);
//			outcome4 = client.ListObjects(request2);
//
//			if (!outcome4.isSuccess()) {
//				/* �쳣���� */
//				std::cout << "ListObjects fail" <<
//					",code:" << outcome4.error().Code() <<
//					",message:" << outcome4.error().Message() <<
//					",requestId:" << outcome4.error().RequestId() << std::endl;
//				break;
//			}
//			for (const auto& object : outcome4.result().ObjectSummarys()) {
//				std::cout << "object" <<
//					",name:" << object.Key() <<
//					",size:" << object.Size() <<
//					",lastmodify time:" << object.LastModified() << std::endl;
//			}
//			for (const auto& commonPrefix : outcome4.result().CommonPrefixes()) {
//				std::cout << "commonPrefix" << ",name:" << commonPrefix << std::endl;
//			}
//			nextMarker = outcome4.result().NextMarker();
//		} while (outcome4.result().IsTruncated());
//	}
//	
//	std::string nextMarker = "";
//	ListObjectOutcome outcome3;
//	do {
//		/*�о��ļ�*/
//		ListObjectsRequest request3(BucketName);
//		/*������б�ߣ�/��Ϊ�ļ��еķָ���*/
//		request3.setDelimiter("/");
//		request3.setPrefix(keyPrefix);
//		request3.setMarker(nextMarker);
//		outcome3 = client.ListObjects(request3);
//
//		if (!outcome3.isSuccess()) {
//			/*�쳣����*/
//			std::cout << "ListObjects fail" <<
//				",code:" << outcome3.error().Code() <<
//				",message:" << outcome3.error().Message() <<
//				",requestId:" << outcome3.error().RequestId() << std::endl;
//			break;
//		}
//
//		for (const auto& object : outcome3.result().ObjectSummarys()) {
//			std::cout << "object" <<
//				",name:" << object.Key() <<
//				",size:" << object.Size() << std::endl;
//		}
//
//		for (const auto& commonPrefix : outcome3.result().CommonPrefixes()) {
//			int64_t foldersize = calculateFolderLength(client, BucketName, commonPrefix);
//			std::cout << "folder" <<
//				",name:" << commonPrefix <<
//				",size:" << foldersize << std::endl;
//		}
//		nextMarker = outcome3.result().NextMarker();
//	} while (outcome3.result().IsTruncated());
//
//	std::string YourMarker = "Test/";
//	ListObjectOutcome outcome5;
//	do {
//		/* �о��ļ� */
//		ListObjectsRequest request5(BucketName);
//		/* �о�ָ��marker֮����ļ� */
//		request.setMarker(YourMarker);
//		outcome5 = client.ListObjects(request5);
//
//		if (!outcome5.isSuccess()) {
//			/* �쳣���� */
//			std::cout << "ListObjects fail" <<
//				",code:" << outcome5.error().Code() <<
//				",message:" << outcome5.error().Message() <<
//				",requestId:" << outcome5.error().RequestId() << std::endl;
//			break;
//		}
//		YourMarker = outcome.result().NextMarker();
//		for (const auto& object : outcome.result().ObjectSummarys()) {
//			std::cout << "object" <<
//				",name:" << object.Key() <<
//				",size:" << object.Size() <<
//				",lastmodify time:" << object.LastModified() << std::endl;
//		}
//	} while (outcome5.result().IsTruncated());
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//	return 0;
//}

int32 OSSTest::MainOSS()
{
	std::string ObjectName = "GTAVTool.zip";
	/* ��ʼ���������Դ */
	InitializeSdk();

	ClientConfiguration conf;
	OssClient client(EndPoint, AccessKeyId, AccessKeySecret, conf);

	/* ObjectName��ʾɾ��OSS�ļ�ʱ��Ҫָ�������ļ���׺���ڵ�����·��������abc/efg/123.jpg */
	/* ����ɾ���ļ��У��뽫ObjectName����Ϊ��Ӧ���ļ������ơ�����ļ��зǿգ�����Ҫ���ļ����µ�����objectɾ�������ɾ�����ļ��� */
	DeleteObjectRequest request(BucketName, ObjectName);

	/* ɾ���ļ� */
	auto outcome = client.DeleteObject(request);

	if (!outcome.isSuccess()) {
		/* �쳣���� */
		std::cout << "DeleteObject fail" <<
			",code:" << outcome.error().Code() <<
			",message:" << outcome.error().Message() <<
			",requestId:" << outcome.error().RequestId() << std::endl;
		ShutdownSdk();
		return -1;
	}

	/* �ͷ��������Դ */
	ShutdownSdk();

	return 0;
}

#if PLATFORM_WINDOWS
#pragma optimize("", on)
#endif
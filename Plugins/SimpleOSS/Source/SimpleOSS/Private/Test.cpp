#include "Test.h"
//#include "Abandonable/SimpleAbandonable.h"

int32 OSSTest::MainOSS()
{
	return 0;
}
#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif
//void Print_F(const FString &NewStr)
//{
//	if (GEngine)
//	{
//		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, NewStr);
//		
//	}
//}

//int32 OSSTest::MainOSS()
//{
//	FString URL = "https://helloworldd.oss-cn-beijing.aliyuncs.com/Splash.jpg";
//
//	FHTTPClient Client;
//	auto A = [=](FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue)
//	{
//		Print_F(HeaderName);
//		Print_F("-----------------------------");
//		Print_F(NewHeaderValue);
//	};
//
//	auto B = [=](FHttpRequestPtr HttpRequest, int32 BytesSent, int32 BytesReceived)
//	{
//		float ReceivedPercentage = HttpRequest->GetElapsedTime();
//
//		Print_F(FString::Printf(TEXT("ReceivedPercentage = %f,BytesSent = %i,BytesReceived = %i"), ReceivedPercentage, BytesSent, BytesReceived));
//	};
//
//	auto C = [=](FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
//	{
//		if (HttpRequest.IsValid() &&
//			HttpResponse.IsValid() &&
//			bSucceeded &&
//			EHttpResponseCodes::IsOk(HttpResponse->GetResponseCode()))
//		{
//			// If it is a download request, save the file through this code
//			FString Filename = FPaths::GetCleanFilename(HttpRequest->GetURL());//"F:\\PJ\\TestOSS\\EEEEEEEEEE.jpg";
//
//			//	FString tempDir = Get()->SavePaths;//FPaths::ProjectContentDir();
//			FFileHelper::SaveArrayToFile(HttpResponse->GetContent(), *(TEXT("F:\\PJ\\TestOSS\\") + Filename)) /**(tempDir / Filename)*/;
//		}
//	};
//
//	FGetObjectRequest Request(URL);
//
//	Request 
//		<< FHttpRequestHeaderReceivedDelegate::CreateLambda(A) 
//		<< FHttpRequestProgressDelegate::CreateLambda(B) 
//		<< FHttpRequestCompleteDelegate::CreateLambda(C);
//
//	if (!Client.GetObject(Request))
//	{
//		Print_F("false");
//	}
//	
//	return 0;
//}
//int32 OSSTest::MainOSS()
//{
//	return 0;
//}

//int32 OSSTest::MainOSS()
//{
//	auto A = [=](FHttpRequestPtr Request, const FString& HeaderName, const FString& NewHeaderValue)
//	{
//		Print_F(HeaderName/NewHeaderValue);
//	};
//
//	auto B = [=](FHttpRequestPtr HttpRequest, int32 BytesSent, int32 BytesReceived)
//	{
//		/*float ReceivedPercentage = HttpRequest->GetElapsedTime();
//		Print_F(FString::Printf(TEXT("HttpRequest->GetResponse()->GetResponseCode() = %i"), HttpRequest->GetResponse()->GetResponseCode()));
//		Print_F(HttpRequest->GetResponse()->GetContentAsString());
//		Print_F(FString::Printf(TEXT("ReceivedPercentage = %f,BytesSent = %i,BytesReceived = %i"), ReceivedPercentage, BytesSent, BytesReceived));*/
//	};
//
//	auto C = [=](FHttpRequestPtr HttpRequest, FHttpResponsePtr HttpResponse, bool bSucceeded)
//	{
//		if (HttpRequest.IsValid() &&
//			HttpResponse.IsValid() &&
//			bSucceeded &&
//			EHttpResponseCodes::IsOk(HttpResponse->GetResponseCode()))
//		{
//			// If it is a download request, save the file through this code
//			FString Filename = FPaths::GetCleanFilename(HttpRequest->GetURL());//"F:\\PJ\\TestOSS\\EEEEEEEEEE.jpg";
//
//			//	FString tempDir = Get()->SavePaths;//FPaths::ProjectContentDir();
//			FFileHelper::SaveArrayToFile(HttpResponse->GetContent(), *(TEXT("F:\\PJ\\TestOSS\\") + Filename)) /**(tempDir / Filename)*/;
//		
//			Print_F(HttpResponse->GetContentAsString());
//		}
//	};	
//	FString URL = "https://helloworldd.oss-cn-beijing.aliyuncs.com";
//	FHTTPClient Client;
//	FGetObjectsInfoRequest Request(URL);
//	Request
//		<< FHttpRequestHeaderReceivedDelegate::CreateLambda(A)
//		<< FHttpRequestProgressDelegate::CreateLambda(B)
//		<< FHttpRequestCompleteDelegate::CreateLambda(C);
//
//	if (!Client.GetObjectInfo(Request))
//	{
//		Print_F("false");
//	}
//
//	return 0;
//}
#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif

#if 0
#include "alibabacloud/oss/OssClient.h"
#include "FileHelper.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

using namespace AlibabaCloud::OSS;

//ͨ�õ��˺�ע��
std::string AccessKeyId = "XXXX";
std::string AccessKeySecret = "XXXX";// ����;
std::string Endpoint = "oss-cn-beijing.aliyuncs.com";

//����Ͱ
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ָ���´���bucket�����ơ��洢�����ACL */
//	CreateBucketRequest Request(
//		BucketName, 
//		StorageClass::IA,
//		CannedAccessControlList::PublicReadWrite);
//
//	auto Outcome = Client.CreateBucket(Request);
//
//	if (!Outcome.isSuccess())
//	{
//		ShutdownSdk();
//		return -1;
//	}
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//	return 0;
//}

#include "alibabacloud/oss/client/RateLimiter.h"

using namespace std;
class FTestRateLimiter : public RateLimiter
{
public:
	FTestRateLimiter()
		:M_Rate(0)
	{}
	~FTestRateLimiter() {};
	virtual void setRate(int rate) { M_Rate = rate; };
	virtual int Rate() const { return M_Rate; };
private:
	int32 M_Rate;
};
//
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//
//	//���ó�ʱʱ��
//	{
//		conf.maxConnections = 17;
//		conf.requestTimeoutMs = 8000;
//		conf.connectTimeoutMs = 8000;
//	}
//	//���ٴ���
//	{
//		auto sendrateLimiter = make_shared<FTestRateLimiter>();
//		auto recvrateLimiter = make_shared<FTestRateLimiter>();
//		conf.sendRateLimiter = sendrateLimiter;
//		conf.recvRateLimiter = recvrateLimiter;
//	}
//
//	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//	//���ٴ���
//	{ 
//		/* �����������٣���λKB/s�� */
//		conf.recvRateLimiter->setRate(400);
//		/* �����ϴ�����(��λKB/s�� */
//		conf.sendRateLimiter->setRate(400);
//	}
//
//	auto outcome = Client.PutObject(BucketName,"TestOSS.zip","F:/PJ/TestOSS/TestOSS.zip");
//	{
//		/* �����ϴ�����(��λKB/s�� */
//		conf.sendRateLimiter->setRate(600);
//	}
//	
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//	return 0;
//}
//
//#include "alibabacloud/oss/client/RetryStrategy.h"
//class FTestRetryStrategy : public RetryStrategy
//{
//public:
//	FTestRetryStrategy(long maxRetries = 3, long scaleFactor = 300) 
//		:m_ScaleFactor(scaleFactor)
//		, m_MaxRetries(maxRetries)
//	{}
//
//	/* �û����Զ���shouldRetry�����������ж��Ƿ�������� */
//	bool shouldRetry(const Error & error, long attemptedRetries) const;
//
//	/* �û����Զ���calcDelayTimeMs���������ڼ������Ե��ӳٵȴ�ʱ�� */
//	long calcDelayTimeMs(const Error & error, long attemptedRetries) const;
//private:
//	long m_ScaleFactor;//���Եȴ�ʱ��ĳ߶�����
//	long m_MaxRetries;//������Դ���
//};
//
//bool FTestRetryStrategy::shouldRetry(const Error & error, long attemptedRetries) const
//{
//	if (attemptedRetries >= m_MaxRetries)
//	{
//		return false;
//	}
//
//	long responseCode = error.Status();
//
//	//100-199 ����ָ���ͻ���Ӧ��Ӧ��ĳЩ������
//	//200-299 ���ڱ�ʾ����ɹ���
//	//300-399 �����Ѿ��ƶ����ļ����ҳ��������ڶ�λͷ��Ϣ��ָ���µĵ�ַ��Ϣ��
//	//400-499 ����ָ���ͻ��˵Ĵ���
//	//500-599 ����֧�ַ���������
//	//http code
//	if ((responseCode == 403 && error.Message().find("RequestTimeTooSkewed")) ||
//		(responseCode > 499 && responseCode < 599))
//	{
//		return true;
//	}
//	else
//	{
//		switch (responseCode)
//		{
//			//curl error code
//		case CURLE_COULDNT_CONNECT:  //�޷�ͨ�� connect() ����������������������
//		case CURLE_PARTIAL_FILE: //�ļ�����ߴ�С�ڻ����Ԥ�ڡ� ���������ȱ�����һ��Ԥ�ڵĴ���ߴ磬Ȼ�������͵���������ǰָ���ߴ粻���ʱ���ͻᷢ���˴���
//		case CURLE_WRITE_ERROR: //���򱾵��ļ�д�����յ�������ʱ�������󣬻���д��ص�(write callback) �� libcurl ������һ������
//		case CURLE_OPERATION_TIMEDOUT: //������ʱ�� �Ѵﵽ������Ӧ���ָ���ĳ�ʱʱ�䡣 ��ע�⣺ �� Urchin 6.6.0.2 ��ʼ����ʱʱ��������и��ġ� Ҫָ��Զ����־���س�ʱ����� urchin.conf �ļ���ȡ�������е�ע�ͱ�ǣ�
//		case CURLE_GOT_NOTHING: //������δ�����κ����ݣ�����Ӧ����£�δ�����κ����ݾ����ڳ��ִ���
//		case CURLE_SEND_ERROR: //�޷������������ݡ�
//		case CURLE_RECV_ERROR: //������������ʧ�ܡ�
//			return true;
//		default:
//			break;
//		}
//	}
//
//	return false;
//}
///* �û����Զ���calcDelayTimeMs���������ڼ������Ե��ӳٵȴ�ʱ�� */
//long FTestRetryStrategy::calcDelayTimeMs(const Error & error, long attemptedRetries) const
//{
//	UNUSED_PARAM(error);
//	return (1 << attemptedRetries) * m_ScaleFactor;
//}
//
////����
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//
//	/* ����ʧ���������Դ�����Ĭ��Ϊ3�� */
//	auto defaultRetryStrategy = std::make_shared<FTestRetryStrategy>(8);
//	conf.retryStrategy = defaultRetryStrategy;
//
//	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//	
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//	return 0;
//}

//��ӡ
void Print_F(const std::string &NewStr)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, NewStr.c_str());
	}
}
void Print_F(const FString &NewStr)
{
	if (GEngine)
	{
		GEngine->AddOnScreenDebugMessage(-1, 20.f, FColor::Red, NewStr);
	}
}
//
////�о�Ͱ
//int32 OSSTest::MainOSS()
//{
////	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//
//	/* �оٴ洢�ռ� */
//	ListBucketsRequest request;
//
//	auto Outcome = Client.ListBuckets(request);
//
//	if (!Outcome.isSuccess())
//	{
//		ShutdownSdk();
//		return -1;
//	}
//
//	for (auto result : Outcome.result().Buckets())
//	{
//		Print_F(result.Name());
//	}
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//	return 0;
//}


////�о�Ͱ
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//
//		/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ���ô洢�ռ����Ȩ�� */
//	SetBucketAclRequest request(BucketName, CannedAccessControlList::PublicRead);
//	auto Outcome = Client.SetBucketAcl(request);
//
//	if (!Outcome.isSuccess())
//	{
//		ShutdownSdk();
//		return -1;
//	}
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//	return 0;
//}

////��ȡ����
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ��ȡ�洢�ռ���� */
//	GetBucketLocationRequest request(BucketName);
//	auto Outcome = Client.GetBucketLocation(request);
//
//	//�Ƿ�������Ͱ
//	if (Client.DoesBucketExist(BucketName))
//	{
//
//	}
//
//	if (!Outcome.isSuccess())
//	{
//		ShutdownSdk();
//		return -1;
//	}
//
//	Print_F(Outcome.result().Location());
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//	return 0;
//}


////ListMultipartUploads
////AbortMultipartUpload
////ɾ��Ͱ
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "10eer1";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient Client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ָ��Ҫɾ����bucket���� */
//	DeleteBucketRequest request(BucketName);
//
//	/* ɾ��bucket */
//	auto outcome = Client.DeleteBucket(request);
//
//	if (!outcome.isSuccess())
//	{
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//
//		ShutdownSdk();
//		return -1;
//	}
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//
//	return 0;
//}

//���������߸���ģʽ
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "10eer";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ���������߸���ģʽ */
//	SetBucketRequestPaymentRequest request(BucketName);
//
//	request.setRequestPayer(RequestPayer::Requester);
//
//	auto outcome = client.SetBucketRequestPayment(request);
//	if (!outcome.isSuccess()) 
//	{
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//��ȡ�����߸���ģʽ
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "10eer";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ��ȡ�����߸���ģʽ */
//	GetBucketRequestPaymentRequest request(BucketName);
//	auto outcome = client.GetBucketRequestPayment(request);
//
//	if (!outcome.isSuccess())
//	{
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//
//		ShutdownSdk();
//		return -1;
//	}
//
//	RequestPayer CC = outcome.result().Payer();
//
//	ShutdownSdk();
//	return 0;
//}

//��Ȩ
//#include <fstream>
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "pooowdsfawdsadw";
//	std::string PayerAccessKeyId = "LTAI4FqU8PLRK6nZi318Fz63";
//	std::string PayerAccessKeySecret = "*****************************";
//	std::string PayerEndpoint = "oss-cn-beijing.aliyuncs.com";
//
//	std::string ObjectName = "1C3C79E04D88B3DABBFBDD9D92379233";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);//���˻�
//	OssClient payerClient(PayerEndpoint, PayerAccessKeyId, PayerAccessKeySecret, conf);//���˻�
//
//	/* ����bucket */
//	CreateBucketOutcome outCome = client.CreateBucket(CreateBucketRequest(BucketName));
//
//	/* ���������߸���ģʽ */
//	SetBucketRequestPaymentRequest request(BucketName);
//	request.setRequestPayer(RequestPayer::Requester);
//	auto payoutcome = client.SetBucketRequestPayment(request);
//
//	/* �ϴ��ļ��������������߸��� */
//	std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(
//		"F://PJ//TestOSS//1C3C79E04D88B3DABBFBDD9D92379233",
//		std::ios::in | std::ios::binary);
//	PutObjectRequest putrequest(BucketName, ObjectName, content);
//	putrequest.setRequestPayer(RequestPayer::Requester);
//	auto putoutcome = payerClient.PutObject(putrequest);
//
//	/* ��ȡ�ļ��������ڴ棬�����������߸��� */
//	GetObjectRequest getrequest(BucketName, ObjectName);
//	getrequest.setRequestPayer(RequestPayer::Requester);
//	auto getoutcome = payerClient.GetObject(getrequest);
//
//	/* ɾ���ļ��������������߸��� */
//	DeleteObjectRequest delrequest(BucketName, ObjectName);
//	delrequest.setRequestPayer(RequestPayer::Requester);
//	auto deloutcome = payerClient.DeleteObject(delrequest);
//
//	ShutdownSdk();
//	return 0;
//}

//
////���ڴ��ϴ�
//int32 OSSTest::MainOSS()
//{
//	//�ȶ����ڴ�
//	TArray<uint8> StringArray;
//	FFileHelper::LoadFileToArray(StringArray, *FString("F:/PJ/TestOSS/WWW.txt"));
//
//	string BucketName = "helloworldd";
//	std::string ObjectName = "WWW.txt";
//
//	InitializeSdk();
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//	std::shared_ptr<std::iostream> content = std::make_shared<std::stringstream>();
//	*content << "hello~";
////	cout << "sdsd" << endl;
//	PutObjectRequest request(BucketName, ObjectName, content);
//
//	auto outcome = client.PutObject(request);
//	if (!outcome.isSuccess())
//	{
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

////�����ϴ�
//int32 OSSTest::MainOSS()
//{
//	string BucketName = "helloworldd";
//	std::string ObjectName = "EEEWWW.txt";
//
//	InitializeSdk();
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	auto outcome = client.PutObject(BucketName,ObjectName,"F:/PJ/TestOSS/EEE.txt");
//
//	if (!outcome.isSuccess())
//	{
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//�ϵ�����
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "1-1StoneDefenc2e.mp4";
//	std::string UploadFilePath = "F:\\PJ\\TestOSS\\1-1StoneDefenc2e.mp4";
//	std::string CheckpointFilePath = "F:\\PJ\\TestOSS\\Hello";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	UploadObjectRequest request(BucketName, ObjectName, UploadFilePath, CheckpointFilePath);
//	auto outcome = client.ResumableUploadObject(request);
//
//	if (!outcome.isSuccess())
//	{
//		/* �쳣���� */
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//�ж��ϴ�
#include <fstream>
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "1-1StoneDefenc2e.mp4";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	std::vector<PutObjectOutcomeCallable> Callables;
//	for (int32 i = 0; i < 4; i++)
//	{
//		std::shared_ptr<std::iostream> 
//			content = std::make_shared<std::fstream>(
//			"F:\\PJ\\TestOSS\\1-1StoneDefenc2e.mp4", 
//				std::ios::in | std::ios::binary);
//
//		PutObjectRequest request(BucketName, ObjectName, content);
//		auto outcomeCallable = client.PutObjectCallable(request);
//		Callables.emplace_back(std::move(outcomeCallable));
//	}
//
//	std::this_thread::sleep_for(std::chrono::milliseconds(1000));
//
//	/* �ж��ϴ� */
//	client.DisableRequest();
//	for (int32 i = 0; i < Callables.size(); i++)
//	{
//		auto outcome = Callables[i].get();
//		if (outcome.error().Code() == "ClientError:100002" ||
//			outcome.error().Code() == "ClientError:200042")
//		{
//			Print_F("disable putobject success");
//		}
//	}
//
//	ShutdownSdk();
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
//��Ƭ�ϴ�
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "1-1StoneDefenc2e.mp4";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	InitiateMultipartUploadRequest initUploadRequest(BucketName, ObjectName);
//	auto uploadIdResult = client.InitiateMultipartUpload(initUploadRequest);
//	auto uploadId = uploadIdResult.result().UploadId();
//	std::string fileToUpload = "F:\\PJ\\TestOSS\\1-1StoneDefenc2e.mp4";
//	int64_t partSize = 1024 * 1024 * 10;
//	PartList partETagList;
//
//	auto fileSize = getFileSize(fileToUpload);
//	int32 partCount = static_cast<int32> (fileSize / partSize);
//
//	/* �����Ƭ���� */
//	if (fileSize % partSize != 0) 
//	{
//		partCount++;
//	}
//
//	for (int32 i = 1; i <= partCount; i++)
//	{
//		auto skipBytes = partSize * (i - 1);
//		auto size = (partSize < fileSize - skipBytes) ? partSize : (fileSize - skipBytes);
//		std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>(fileToUpload, std::ios::in | std::ios::binary);
//		
//		//std::ios::beg std::ios::end
//		content->seekg(skipBytes, std::ios::beg);
//
//		UploadPartRequest uploadPartRequest(BucketName, ObjectName, content);
//		uploadPartRequest.setContentLength(size);
//		uploadPartRequest.setUploadId(uploadId);
//		uploadPartRequest.setPartNumber(i);
//
//		auto uploadPartOutcome = client.UploadPart(uploadPartRequest);
//		if (uploadPartOutcome.isSuccess()) 
//		{
//			Part part(i, uploadPartOutcome.result().ETag());
//			partETagList.push_back(part);
//		}
//		else
//		{
//			Print_F(uploadPartOutcome.error().Code());
//			Print_F(uploadPartOutcome.error().Message());
//			Print_F(uploadPartOutcome.error().RequestId());
//		}
//	}
//	//�о����ǵķ�Ƭ
//	//{
//	//	/* �о����ϴ���Ƭ,Ĭ���о�1000����Ƭ */
//	//	ListPartsRequest listuploadrequest(BucketName, ObjectName);
//	//	listuploadrequest.setMaxParts(2);
//	//	listuploadrequest.setUploadId(uploadId);
//	//	ListPartsOutcome listuploadresult;
//
//	//	do 
//	//	{
//	//		listuploadresult = client.ListParts(listuploadrequest);
//	//		if (!listuploadresult.isSuccess())
//	//		{
//	//			/* �쳣���� */
//	//			Print_F(listuploadresult.error().Code());
//	//			Print_F(listuploadresult.error().Message());
//	//			Print_F(listuploadresult.error().RequestId());
//	//			break;
//	//		}
//	//		else
//	//		{
//	//			for (const auto& part : listuploadresult.result().PartList())
//	//			{
//	//				Print_F(std::to_string(part.PartNumber()));
//	//				Print_F(std::to_string(part.Size()));
//	//				Print_F(part.ETag());
//	//				Print_F(part.LastModified());
//	//			}
//	//		}
//	//			
//	//		listuploadrequest.setPartNumberMarker(listuploadresult.result().NextPartNumberMarker());
//	//	} while (listuploadresult.result().IsTruncated());
//	//}
//
//	//�оٷ�Ƭ�ϴ��¼�
//	//{
//	//	ListMultipartUploadsRequest listmultiuploadrequest(BucketName);
//	//	listmultiuploadrequest.setMaxUploads(2);
//	//	ListMultipartUploadsOutcome listresult;
//	//	do 
//	//	{
//	//		listresult = client.ListMultipartUploads(listmultiuploadrequest);
//	//		if (!listresult.isSuccess())
//	//		{
//	//			/* �쳣���� */
//	//			Print_F(listresult.error().Code());
//	//			Print_F(listresult.error().Message());
//	//			Print_F(listresult.error().RequestId());
//	//			break;
//	//		}
//	//		else
//	//		{
//	//			for (const auto& part : listresult.result().MultipartUploadList())
//	//			{
//	//				Print_F(part.Key);
//	//				Print_F(part.UploadId);
//	//				Print_F(part.Initiated);
//	//			}
//	//		}
//	//		listmultiuploadrequest.setKeyMarker(listresult.result().NextKeyMarker());
//	//		listmultiuploadrequest.setUploadIdMarker(listresult.result().NextUploadIdMarker());
//	//	} while (listresult.result().IsTruncated());
//	//}
//
//	//ȡ����Ƭ�ϴ�
//	{
//		AbortMultipartUploadRequest  abortUploadRequest(BucketName, ObjectName, uploadId);
//		auto abortUploadIdResult = client.AbortMultipartUpload(abortUploadRequest);
//		if (!abortUploadIdResult.isSuccess())
//		{
//			Print_F(abortUploadIdResult.error().Code());
//			Print_F(abortUploadIdResult.error().Message());
//			Print_F(abortUploadIdResult.error().RequestId());
//			ShutdownSdk();
//			return -1;
//		}
//		ShutdownSdk();
//		return 0;
//	}
//
//	CompleteMultipartUploadRequest request(BucketName, ObjectName);
//	request.setUploadId(uploadId);
//	request.setPartList(partETagList);
//	auto outcome = client.CompleteMultipartUpload(request);
//	if (!outcome.isSuccess())
//	{
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

void ProgressCallback(size_t increment, int64_t transfered, int64_t total, void* userData)
{
	Print_F(FString::Printf(TEXT("increment = %i,transfered =%i ,total = %i"), increment, transfered, total));
}
//�����ϴ�
#include "Core/ThreadCoreMacro.h"
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "1-1StoneDefenc2e.mp4";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	std::shared_ptr<std::iostream> content = std::make_shared<std::fstream>("F:\\PJ\\TestOSS\\1-1StoneDefenc2e.mp4", std::ios::in | std::ios::binary);
//	PutObjectRequest request(BucketName, ObjectName, content);
//	TransferProgress progressCallback = { ProgressCallback , nullptr };
//	request.setTransferProgress(progressCallback);
//
//	auto OutLamada = [=]()
//	{
//		auto outcome = client.PutObject(request);
//		if (!outcome.isSuccess())
//		{
//			Print_F(outcome.error().Code());
//			Print_F(outcome.error().Message());
//			Print_F(outcome.error().RequestId());
//		}
//		ShutdownSdk();
//	};
//
//	ASYNCTASK_Lambda(OutLamada);
//
//	return 0;
//}
//���ص�����
//#include <memory>
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEEWWW.txt";
//
//	std::string FileNametoSave = "F:\\PJ\\TestOSS\\EEEEEEEEEE.txt";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	GetObjectRequest request(BucketName, ObjectName);
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	
//	auto outcome = client.GetObject(request);
//	if (outcome.isSuccess())
//	{
//		Print_F(to_string(outcome.result().Metadata().ContentLength()));
//	}
//	else
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}
//���ص������ڴ�
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEEWWW.txt";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	GetObjectRequest request(BucketName, ObjectName);
//
//	auto outcome = client.GetObject(request);
//	if (outcome.isSuccess())
//	{
//		Print_F(to_string(outcome.result().Metadata().ContentLength()));
//		
//		/*��ӡ��������*/
//		std::string content;
//		*(outcome.result().Content()) >> content;
//		Print_F(content);
//	}
//	else
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//��Χ����
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEEWWW.txt";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	GetObjectRequest request(BucketName, ObjectName);
//	request.setRange(0, 2);
//	auto outcome = client.GetObject(request);
//	if (outcome.isSuccess())
//	{
//		Print_F(to_string(outcome.result().Metadata().ContentLength()));
//
//		/*��ӡ��������*/
//		std::string content;
//		*(outcome.result().Content()) >> content;
//		Print_F(content);
//	}
//	else
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

////��Ƭ����
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "10eer";
//	std::string ObjectName = "11B9DA17474BEB54CD82248028D8B607";
//
//	std::string DownloadFilePath = "F://PJ//TestOSS//11B9DA17474BEB54CD82248028D8B607";
//	std::string CheckpointFilePath = "F://PJ//TestOSS//Hello";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	DownloadObjectRequest request(BucketName, ObjectName, DownloadFilePath, CheckpointFilePath);
//	auto outcome = client.ResumableDownloadObject(request);
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//������ʾ������
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "10eer";
//	std::string ObjectName = "11B9DA17474BEB54CD82248028D8B607";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	GetObjectRequest request(BucketName, ObjectName);
//	TransferProgress progressCallback = { ProgressCallback , nullptr };
//	request.setTransferProgress(progressCallback);
//
//	request.setResponseStreamFactory([=]() 
//	{
//		return std::make_shared<std::fstream>(
//			"F:\\PJ\\TestOSS\\ERTDGGR", 
//			std::ios_base::out | 
//			std::ios_base::in | 
//			std::ios_base::trunc |
//			std::ios_base::binary);
//	});
//
//	auto OutLamada = [=]()
//	{
//		auto outcome = client.GetObject(request);
//		if (!outcome.isSuccess())
//		{
//			Print_F(outcome.error().Code());
//			Print_F(outcome.error().Message());
//			Print_F(outcome.error().RequestId());
//		}
//		ShutdownSdk();
//	};
//
//	ASYNCTASK_Lambda(OutLamada);
//
//	return 0;
//}


//�����ļ���дȨ��
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEE.txt";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	SetObjectAclRequest request(BucketName, ObjectName);
//	request.setAcl(CannedAccessControlList::Private);
//
//	auto outcome = client.SetObjectAcl(request);
//
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//		
//	ShutdownSdk();
//	return 0;
//}

//��ȡ��дȨ��
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEE.txt";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	GetObjectAclRequest request(BucketName, ObjectName);
//	auto outcome = client.GetObjectAcl(request);
//
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//	else
//	{
//		Print_F(to_string(outcome.result().Acl()));
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//����Ԫ����
//Content-Type
//https://help.aliyun.com/knowledge_detail/39522.html?spm=a2c4g.11186623.4.2.6386370c1sfuf4
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEE.txt";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	auto meta = ObjectMetaData();
//	meta.setContentType("text/plain");
//	meta.setCacheControl("max-age=3");
//
//	//meta.setContentDisposition()
//	//meta.setContentEncoding()
//	//meta.setContentLength()
//	//meta.setExpirationTime()
//
//	meta.UserMetaData()["Hello"] = "No-value";
//	std::shared_ptr<std::iostream> content = std::make_shared<std::stringstream>();
//	*content << "Thank you for using hello mate Storage Service!";
//
//	auto outcome = client.PutObject(BucketName, ObjectName, content, meta);
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//��ȡԪ����
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEE.txt";
//
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ��ȡ�ļ��Ĳ���Ԫ��Ϣ */
//	auto outcome = client.GetObjectMeta(BucketName, ObjectName);
//	
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//	else
//	{
//		auto metadata = outcome.result();
//		Print_F(metadata.ETag());
//		Print_F(metadata.LastModified());
//		Print_F(to_string(metadata.ContentLength()));
//	}
//
//	/* ��ȡ�ļ���ȫ��Ԫ��Ϣ */
//	outcome = client.HeadObject(BucketName, ObjectName);
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//	else
//	{
//		auto headMeta = outcome.result();
//		Print_F(headMeta.ContentType());
//		Print_F(to_string(headMeta.ContentLength()));
//		Print_F(headMeta.CacheControl());
//		Print_F(headMeta.ContentDisposition());
//		Print_F(headMeta.ContentEncoding());
//		Print_F(headMeta.ContentMd5());
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//���о��ļ�
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	ListObjectsRequest request(BucketName);
//	auto outcome = client.ListObjects(request);
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//	else
//	{
//		for (const auto& object : outcome.result().ObjectSummarys())
//		{
//			Print_F(TEXT("------------------------"));
//			Print_F(object.Key());
//			Print_F(to_string(object.Size()));
//			Print_F(object.LastModified());
//		}
//	}
//
//	ShutdownSdk();
//	return 0;
//}

////�о�ָ���������ļ�
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	ListObjectsRequest request(BucketName);
//	request.setMaxKeys(1);
//	auto outcome = client.ListObjects(request);
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//	else
//	{
//		for (const auto& object : outcome.result().ObjectSummarys())
//		{
//			Print_F(TEXT("------------------------"));
//			Print_F(object.Key());
//			Print_F(to_string(object.Size()));
//			Print_F(object.LastModified());
//		}
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//�о�ָ��Ŀ¼�µ��ļ�����Ŀ¼
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string keyPrefix = "UU/";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	std::string nextMarker = "";
//	ListObjectOutcome outcome;
//	do
//	{
//		/* �о��ļ� */
//		ListObjectsRequest request(BucketName);
//		/* ������б�ߣ�/��Ϊ�ļ��еķָ��� */
//		request.setDelimiter("/");
//		request.setPrefix(keyPrefix);
//		request.setMarker(nextMarker);
//
//		outcome = client.ListObjects(request);
//		if (!outcome.isSuccess())
//		{
//			/*�쳣����*/
//			Print_F(outcome.error().Code());
//			Print_F(outcome.error().Message());
//			Print_F(outcome.error().RequestId());
//			break;
//		}
//
//		for (const auto& object : outcome.result().ObjectSummarys())
//		{	
//			Print_F(object.Key());
//			Print_F(to_string(object.Size()));
//			Print_F(object.LastModified());
//			Print_F(TEXT("-----------object-------------"));
//		}
//
//		for (const auto& commonPrefix : outcome.result().CommonPrefixes())
//		{	
//			Print_F(commonPrefix);
//			Print_F(TEXT("------------commonPrefix------------"));
//		}
//		nextMarker = outcome.result().NextMarker();
//	} while (outcome.result().IsTruncated());
//
//	ShutdownSdk();
//	return 0;
//}

////�о�ָ�� marker ֮����ļ�
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string nextMarker = "UU/";
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	ListObjectOutcome outcome;
//	do
//	{
//		/* �о��ļ� */
//		ListObjectsRequest request(BucketName);
//		request.setMarker(nextMarker);
//
//		outcome = client.ListObjects(request);
//		if (!outcome.isSuccess())
//		{
//			/*�쳣����*/
//			Print_F(outcome.error().Code());
//			Print_F(outcome.error().Message());
//			Print_F(outcome.error().RequestId());
//			break;
//		}
//
//		for (const auto& object : outcome.result().ObjectSummarys())
//		{	
//			Print_F(object.Key());
//			Print_F(to_string(object.Size()));
//			Print_F(object.LastModified());
//			Print_F(TEXT("-----------object-------------"));
//		}
//
//		for (const auto& commonPrefix : outcome.result().CommonPrefixes())
//		{	
//			Print_F(commonPrefix);
//			Print_F(TEXT("------------commonPrefix------------"));
//		}
//		nextMarker = outcome.result().NextMarker();
//	} while (outcome.result().IsTruncated());
//
//	ShutdownSdk();
//	return 0;
//}

//�����ţ�'��
//˫���ţ�"��
//and���ţ�&��
//�����ţ�< >��
//�ٺţ�����
//����
//ָ���ļ����Ʊ���
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string nextMarker = "";
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	ListObjectOutcome outcome;
//	do
//	{
//		/* �о��ļ� */
//		ListObjectsRequest request(BucketName);
//		request.setMarker(nextMarker);
//		request.setEncodingType("url");
//
//		outcome = client.ListObjects(request);
//		if (!outcome.isSuccess())
//		{
//			/*�쳣����*/
//			Print_F(outcome.error().Code());
//			Print_F(outcome.error().Message());
//			Print_F(outcome.error().RequestId());
//			break;
//		}
//
//		for (const auto& object : outcome.result().ObjectSummarys())
//		{
//			Print_F(object.Key());
//			Print_F(to_string(object.Size()));
//			Print_F(object.LastModified());
//			Print_F(TEXT("-----------object-------------"));
//		}
//
//		nextMarker = outcome.result().NextMarker();
//	} while (outcome.result().IsTruncated());
//
//	ShutdownSdk();
//	return 0;
//}
//�жϵ�ǰ�����Ƿ����
void DoesObjectExist(const OssClient &client, const std::string &BucketName, const std::string &ObjectName)
{
	/* �ж��ļ��Ƿ���� */
	if (client.DoesObjectExist(BucketName, ObjectName))
	{
		Print_F(TEXT("Y"));
	}
	else
	{
		Print_F(TEXT("N"));
	}
}
//ɾ������
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "WWW.txt";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	DeleteObjectRequest request(BucketName, ObjectName);
//
//	DoesObjectExist(client, BucketName, ObjectName);
//
//	/* ɾ���ļ� */
//	auto outcome = client.DeleteObject(request);
//
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	DoesObjectExist(client, BucketName, ObjectName);
//
//	ShutdownSdk();
//	return 0;
//}

//ɾ���������
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName1 = "EEEWWW.txt";
//	std::string ObjectName2 = "UU/EEEWe.txt";
//	std::string ObjectName3 = "UU/TT/EEEWWWWEERW.txt";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	DeleteObjectsRequest request(BucketName);
//	request.addKey(ObjectName1);
//	request.addKey(ObjectName2);
//	request.addKey(ObjectName3);
//
//	/* ɾ���ļ� */
//	auto outcome = client.DeleteObjects(request);
//
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//����С�ļ�
//int32 OSSTest::MainOSS()
//{
//	std::string SourceBucketName = "helloworldd";
//	std::string CopyBucketName = "helloworldd";
//	std::string SourceObjectName = "UU/EEEWe.txt";
//	std::string CopyObjectName = "EEEWe.txt";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	CopyObjectRequest request(CopyBucketName, CopyObjectName);
//	request.setCopySource(SourceBucketName, SourceObjectName);
//
//	auto outcome = client.CopyObject(request);
//
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//��Ƭ����
//int32 OSSTest::MainOSS()
//{
//	std::string SourceBucketName = "10eer";
//	std::string CopyBucketName = "helloworldd";
//	std::string SourceObjectName = "1A25C5164E5CEC4C41B88588F5201B84";
//	std::string CopyObjectName = "WWWW";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	auto getObjectMetaReq = GetObjectMetaRequest(SourceBucketName, SourceObjectName);
//	auto getObjectMetaResult = client.GetObjectMeta(getObjectMetaReq);
//	if (!getObjectMetaResult.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(getObjectMetaResult.error().Code());
//		Print_F(getObjectMetaResult.error().Message());
//		Print_F(getObjectMetaResult.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//	/* ��ȡ�������ļ���С */
//	auto objectSize = getObjectMetaResult.result().ContentLength();
//
//	/* �������ļ� */
//	InitiateMultipartUploadRequest initUploadRequest(CopyBucketName, CopyObjectName);
//
//	/* ��ʼ����Ƭ�����¼� */
//	auto uploadIdResult = client.InitiateMultipartUpload(initUploadRequest);
//
//	auto uploadId = uploadIdResult.result().UploadId();
//	int64_t partSize = 1024 * 1024*10;
//	int partCount = static_cast<int>(objectSize / partSize);//30
//
//	 /* �����Ƭ����*/
//	if (objectSize % partSize != 0)
//	{
//		partCount++;
//	}
//	PartList partETagList;
//	/* ��ÿһ����Ƭ���п��� */
//	for (int i = 1; i <= partCount; i++)
//	{
//		auto skipBytes = partSize * (i - 1);
//		auto size = (partSize < objectSize - skipBytes) ? partSize : (objectSize - skipBytes);
//		auto uploadPartCopyReq = UploadPartCopyRequest(CopyBucketName, CopyObjectName, SourceBucketName, SourceObjectName, uploadId, i + 1);
//		uploadPartCopyReq.setCopySourceRange(skipBytes, skipBytes + size - 1);
//		auto uploadPartOutcome = client.UploadPartCopy(uploadPartCopyReq);
//		if (uploadPartOutcome.isSuccess()) 
//		{
//			Part part(i, uploadPartOutcome.result().ETag());
//			partETagList.push_back(part);
//		}
//		else
//		{
//			/*�쳣����*/
//			Print_F(getObjectMetaResult.error().Code());
//			Print_F(getObjectMetaResult.error().Message());
//			Print_F(getObjectMetaResult.error().RequestId());
//		}
//	}
//
//	CompleteMultipartUploadRequest request(CopyBucketName, CopyObjectName, partETagList, uploadId);
//	auto outcome = client.CompleteMultipartUpload(request);
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//	
//	ShutdownSdk();
//	return 0;
//}
//��Object�Ĵ洢���ʹӱ�׼���Ƶ����ת��Ϊ�鵵���ͣ�
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEEWe.txt";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	ObjectMetaData objectMeta;
//	objectMeta.addHeader("x-oss-storage-class", "Archive");//Standard��IA��Archive
//	CopyObjectRequest request(BucketName, BucketName, objectMeta);
//	request.setCopySource(BucketName, ObjectName);
//
//	/* �޸�Ϊ����ָ�����ļ��洢���� */
//	auto outcome = client.CopyObject(request);
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//			
//	ShutdownSdk();
//	return 0;
//}

//
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEEWe.txt";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ���Ŀ���ļ��Ƿ�Ϊ�鵵���͡�����ǣ�����Ҫ�Ƚⶳ���ܸ��Ĵ洢���� */
//	auto restoreOutcome = client.RestoreObject(BucketName, ObjectName);
//	if (!restoreOutcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(restoreOutcome.error().Code());
//		Print_F(restoreOutcome.error().Message());
//		Print_F(restoreOutcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	std::string onGoingRestore("ongoing-request=\"false\"");
//	int32 maxWaitTimeInSeconds = 600;
//	while (maxWaitTimeInSeconds > 0)
//	{
//		auto meta = client.HeadObject(BucketName, ObjectName);
//		std::string restoreStatus = meta.result().HttpMetaData()["x-oss-restore"];
//		std::transform(restoreStatus.begin(), restoreStatus.end(), restoreStatus.begin(), ::tolower);//toupper
//		if (!restoreStatus.empty() &&
//			restoreStatus.compare(0, onGoingRestore.size(), onGoingRestore) == 0)
//		{	
//			/* �ɹ��ⶳ�鵵�ļ�*/
//			Print_F(restoreStatus);
//		
//			break;
//		}
//
//		std::this_thread::sleep_for(std::chrono::seconds(10));
//		maxWaitTimeInSeconds--;
//	}
//
//	ObjectMetaData objectMeta;
//	objectMeta.addHeader("x-oss-storage-class", "IA");//Standard��IA��Archive
//	CopyObjectRequest request(BucketName, BucketName, objectMeta);
//	request.setCopySource(BucketName, ObjectName);
//
//	/* �޸�Ϊ����ָ�����ļ��洢���� */
//	auto outcome = client.CopyObject(request);
//	if (!outcome.isSuccess())
//	{
//		/*�쳣����*/
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//����������
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "EEEWe.txt";
//	std::string LinkObjectName = "WE.txt";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ����HTTP header */
//	auto meta = ObjectMetaData();
//	meta.setContentType("text/plain");
//
//	/* �����Զ����ļ�Ԫ��Ϣ */
//	meta.UserMetaData()["meta"] = "meta-value";
//
//	/* ���������� */
//	CreateSymlinkRequest request(BucketName, ObjectName, meta);
//	request.SetSymlinkTarget(LinkObjectName);
//	auto outcome = client.CreateSymlink(request);
//	if (!outcome.isSuccess())
//	{
//		/* �쳣���� */
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//	}
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//	return 0;
//}

//��ȡ������ָ����ļ�����
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string LinkName = "EEEWe.txt";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	GetSymlinkRequest request(BucketName, LinkName);
//	auto outcome = client.GetSymlink(request);
//
//	if (!outcome.isSuccess())
//	{
//		/* �쳣���� */
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//	}
//	else
//	{
//		Print_F(outcome.result().SymlinkTarget());
//	}
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//	return 0;
//}

//���÷�����
//int32 OSSTest::MainOSS()
//{
//	/* ��ʼ��OSS�˺���Ϣ */
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ���÷����� */
//	SetBucketRefererRequest request(BucketName);
//	request.addReferer("http://www.renzhai.net");
//	request.addReferer("http://www.*.net");
//	request.setAllowEmptyReferer(false);
//
//	auto outcome = client.SetBucketReferer(request);
//	if (!outcome.isSuccess())
//	{
//		/* �쳣���� */
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//��ȡ������
//int32 OSSTest::MainOSS()
//{
//	/* ��ʼ��OSS�˺���Ϣ */
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//	
//	/* ��ȡ��������Ϣ */
//	GetBucketRefererRequest request(BucketName);
//	auto outcome = client.GetBucketReferer(request);
//	if (!outcome.isSuccess())
//	{
//		/* �쳣���� */
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//	else
//	{
//		Print_F(to_string(outcome.result().AllowEmptyReferer()));
//		Print_F(to_string(outcome.result().RefererList().size()));
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//ɾ��������
//int32 OSSTest::MainOSS()
//{
//	/* ��ʼ��OSS�˺���Ϣ */
//	std::string BucketName = "helloworldd";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ��շ�����,����������ֱ����գ���Ҫ�½�һ�������referer�Ĺ���������֮ǰ�Ĺ��� */
//	SetBucketRefererRequest request(BucketName);
//	request.setAllowEmptyReferer(true);
//
//	auto outcome = client.SetBucketReferer(request);
//
//	if (!outcome.isSuccess())
//	{
//		/* �쳣���� */
//		Print_F(outcome.error().Code());
//		Print_F(outcome.error().Message());
//		Print_F(outcome.error().RequestId());
//		ShutdownSdk();
//		return -1;
//	}
//
//	ShutdownSdk();
//	return 0;
//}

//OSSͼ�����������
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "Splash.jpg";
//
//	string FileNametoSave = "F:\\PJ\\TestOSS\\EEEEEEEEEE.jpg";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	/* ���� */
//	std::string Process = "image/resize,m_fixed,w_100,h_100";
//	GetObjectRequest request(BucketName, ObjectName);
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	request.setProcess(Process);
//	auto outcome = client.GetObject(request);
//
//	/* �ü� */
//	Process = "image/crop,w_100,h_100,x_100,y_100,r_1";
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	request.setProcess(Process);
//	outcome = client.GetObject(request);
//
//	/* ��ת */
//	Process = "image/rotate,90";
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	request.setProcess(Process);
//	outcome = client.GetObject(request);
//
//	/* �� */
//	Process = "image/sharpen,229";
//	request.setProcess(Process);
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	outcome = client.GetObject(request);
//
//	/* ˮӡ */
//	Process = "image/watermark,text_SGVsbG8g5Zu-54mH5pyN5YqhIQ";
//	request.setProcess(Process);
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	outcome = client.GetObject(request);
//
//	/*�Զ������ʽ */
//	Process = "image/auto-orient,1/bright,55/contrast,-42/sharpen,318/blur,r_1,s_13/watermark,text_aGVsbG8gd29ybGQ,color_ff0000,size_48,rotate_48,shadow_34,g_north,t_51,x_10,y_10";
//	request.setProcess(Process);
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	outcome = client.GetObject(request);
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//	return 0;
//}

//OSSͼ������Զ�����ʽ
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "Splash.jpg";
//
//	string FileNametoSave = "F:\\PJ\\TestOSS\\EEEEEEEEEE.jpg";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	std::string Process = "style/MyHello";
//	GetObjectRequest request(BucketName, ObjectName);
//	request.setProcess(Process);
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	auto outcome = client.GetObject(request);
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//	return 0;
//}

//�������� 
//http://<yourBucketName>.<yourEndpoint>/<yourObjectName>?x-oss-process=image/<yourAction1>,<yourParamValue1>/<yourAction2>,<yourParamValue2>/...
//�Զ�����ʽ 
//http://<yourBucketName>.<yourEndpoint>/<yourObjectName>?x-oss-process=style/<yourStyleName>
//int32 OSSTest::MainOSS()
//{
//	std::string BucketName = "helloworldd";
//	std::string ObjectName = "Splash.jpg";
//
//	string FileNametoSave = "F:\\PJ\\TestOSS\\EEEEEEEEEE.jpg";
//
//	/* ��ʼ���������Դ */
//	InitializeSdk();
//
//	ClientConfiguration conf;
//	OssClient client(Endpoint, AccessKeyId, AccessKeySecret, conf);
//
//	std::string Process = "image/resize,m_fixed,w_100,h_100/rotate,90";
//	GetObjectRequest request(BucketName, ObjectName);
//	request.setProcess(Process);
//	request.setResponseStreamFactory([=]() {return std::make_shared<std::fstream>(FileNametoSave, std::ios_base::out | std::ios_base::in | std::ios_base::trunc | std::ios_base::binary); });
//	auto outcome = client.GetObject(request);
//
//	/* �ͷ��������Դ */
//	ShutdownSdk();
//	return 0;
//}

void DSFSFSDS(int32 A, int64 V, int64 C, void* D)
{
	Print_F(FString::Printf(TEXT("increment = %i,transfered =%i ,total = %i"), A, V, C));
}

//int32 OSSTest::MainOSS()
//{
//	//std::string AccessKeyId = "LTAIeU8z1jgOd0gq";
//	//std::string AccessKeySecret = "xE77upb6oPWjXYXY6Nr4X6HtBB5ITz";// ;
//	//std::string Endpoint = "oss-cn-beijing.aliyuncs.com";
//	TSharedPtr<FOSS> MyOSS = MakeShareable(new FOSS);
//	auto OutLamada = [=]()
//	{
//		MyOSS->PutObjectByLocal(FString("helloworldd"), FString("F:/SynchronizedUpdate/Engine421/aliyun-oss-cpp-sdk-master.zip"), FString("aliyun-oss-cpp-sdk-master.zip"), DSFSFSDS);
//	};
//
//	MyOSS->InitAccounts("LTAIeU8z1jgOd0gq","xx","oss-cn-beijing.aliyuncs.com");
//
////	ASYNCTASK_Lambda(OutLamada, MyOSS);
//	(new FAutoDeleteAsyncTask<FSimpleAbandonable>(FSimpleDelegate::CreateLambda(OutLamada)))->StartBackgroundTask();
//	return 0;
//}
#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif
#endif // 
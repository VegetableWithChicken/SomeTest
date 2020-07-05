#include "TestReflex.h"

#if OFF_REFLEXACTOR

#include "UObject/GeneratedCppIncludes.h"
#include "SomeTest/ReflexSystem/ReflexActor.h"//���������ļ�
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
	//���ɵ�ReflexActor����Ŀ����Ӻ���
	void EmptyLinkFunctionForGeneratedCodeReflexActor() {}

	// Cross Module References
	//����UClass��Ӧ��UClass������ע��
	SOMETEST_API UClass* Z_Construct_UClass_AReflexActor_NoRegister();
	//����UClass��Ӧ��UClass������ע��
	SOMETEST_API UClass* Z_Construct_UClass_AReflexActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();

	//����SomeTest�����UPackage����
	UPackage* Z_Construct_UPackage__Script_SomeTest();

	SOMETEST_API UFunction* Z_Construct_UDelegateFunction_SomeTest_CharacterDelegate_Dynamic__DelegateSignature();
	SOMETEST_API UFunction* Z_Construct_UDelegateFunction_SomeTest_CharacterDelegate_DynamicRetVal__DelegateSignature();
	SOMETEST_API UFunction* Z_Construct_UDelegateFunction_SomeTest_CharacterDelegate_DynamicMulticast__DelegateSignature();
	SOMETEST_API UFunction* Z_Construct_UDelegateFunction_SomeTest_CharacterDelegate_DynamicMulticast2__DelegateSignature();
	UPackage* Z_Construct_UPackage__Script_SomeTest()
	{
		static UPackage* ReturnPackage = nullptr;
		if (!ReturnPackage)
		{
			static UObject* (*const SingletonFuncArray[])() = {
				(UObject* (*)())Z_Construct_UDelegateFunction_SomeTest_CharacterDelegate_Dynamic__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SomeTest_CharacterDelegate_DynamicRetVal__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SomeTest_CharacterDelegate_DynamicMulticast__DelegateSignature,
				(UObject* (*)())Z_Construct_UDelegateFunction_SomeTest_CharacterDelegate_DynamicMulticast2__DelegateSignature,
			};
			static const UE4CodeGen_Private::FPackageParams PackageParams = {
				"/Script/SomeTest",
				SingletonFuncArray,
				UE_ARRAY_COUNT(SingletonFuncArray),
				PKG_CompiledIn | 0x00000000,
				0x1AC6EC1B,
				0xAB156667,
				METADATA_PARAMS(nullptr, 0)
			};

			//struct FPackageParams
			//{
			//	const char*                        NameUTF8 =						"/Script/SomeTest";
			//	UObject*						   (*const *SingletonFuncArray)() = SingletonFuncArray;
			//	int32                              NumSingletons =					sizeof(SingletonFuncArray) - 1;
			//	uint32                             PackageFlags =					PKG_CompiledIn | 0x00000000; // EPackageFlags �˰����ԡ������ڡ��ࡣ
			//	uint32                             BodyCRC =						0x1AC6EC1B;
			//	uint32                             DeclarationsCRC =				0xAB156667;
			//#if WITH_METADATA
			//	const FMetaDataPairParam*          MetaDataArray =					nullptr;
			//	int32                              NumMetaData =					0;
			//#endif
			//};

			UE4CodeGen_Private::ConstructUPackage(ReturnPackage, PackageParams);
		}
		return ReturnPackage;
	}

	// End Cross Module References
	//��̬ע��
	void AReflexActor::StaticRegisterNativesAReflexActor()
	{
	}

	//����AReflexActor��Ӧ��UClass���� ��ע��
	UClass* Z_Construct_UClass_AReflexActor_NoRegister()
	{
		return AReflexActor::StaticClass();
	}

	struct Z_Construct_UClass_AReflexActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA//��Ҫ�ڱ༭��ģʽ��
	//Ԫ���ݵ���Բ���
	static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
	//�����ض�C++�������
	static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
	//�����
	static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	//������
	UObject* (*const Z_Construct_UClass_AReflexActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,//����UClass��Ӧ��UClass������ע��
		(UObject* (*)())Z_Construct_UPackage__Script_SomeTest,//����SomeTest�����UPackage����
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ReflexSystem/ReflexActor.h" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	//�����ض�C++������� Ϊ����
	const FCppClassTypeInfoStatic Z_Construct_UClass_AReflexActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AReflexActor>::IsAbstract,
	};

	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AReflexActor_Statics::ClassParams = {
		&AReflexActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		nullptr,
		nullptr,
		nullptr,
		sizeof(DependentSingletons) - 1,
		0,
		0,
		0,
		0x009000A4u,
		//METADATA_PARAMS(Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams, sizeof(Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams) - 1)չ��
		Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams, sizeof(Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams) - 1,
	};

	//struct FClassParams
	//{
	//	UClass*										(*ClassNoRegisterFunc)() =					&AReflexActor::StaticClass;
	//	const char*                                 ClassConfigNameUTF8							= "Engine";
	//	const FCppClassTypeInfoStatic*              CppClassInfo =								&StaticCppClassTypeInfo;
	//	UObject*									(*const *DependencySingletonFuncArray)() =	DependentSingletons;
	//	const FClassFunctionLinkInfo*               FunctionLinkArray =							nullptr;
	//	const FPropertyParamsBase* const*           PropertyArray =								nullptr;
	//	const FImplementedInterfaceParams*          ImplementedInterfaceArray =					nullptr;
	//	int32                                       NumDependencySingletons =					sizeof(DependentSingletons) - 1;
	//	int32                                       NumFunctions =								0;
	//	int32                                       NumProperties =								0;
	//	int32                                       NumImplementedInterfaces					0;
	//	uint32                                      ClassFlags =								0x009000A4u; // EClassFlags
	//#if WITH_METADATA
	//	const FMetaDataPairParam*                   MetaDataArray =								Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams;
	//	int32                                       NumMetaData =								sizeof(Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams) - 1;
	//#endif
	//};


	//���� ע���Ա
	UClass* Z_Construct_UClass_AReflexActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AReflexActor_Statics::ClassParams);
		}
		return OuterClass;
	}

	//IMPLEMENT_CLASS(AReflexActor, 1395401713);չ��
	//#define IMPLEMENT_CLASS(AReflexActor, TClassCrc)
	//�ӳ�ע��
	static TClassCompiledInDefer<AReflexActor> AutoInitializeAReflexActor(TEXT("AReflexActor"), sizeof(AReflexActor), 1395401713); 

	UClass* AReflexActor::GetPrivateStaticClass() 
	{ 
		static UClass* PrivateStaticClass = NULL; 
		if (!PrivateStaticClass) 
		{ 
			/* this could be handled with templates, but we want it external to avoid code bloat */ 
			//�������ģ�崦��������ϣ�������ⲿ�ģ��Ա���������͡�
			GetPrivateStaticClassBody( 
				StaticPackage(), 
				(TCHAR*)TEXT("AReflexActor") + 1 + ((StaticClassFlags & CLASS_Deprecated) ? 11 : 0),//+1 Ϊ��ȥ��ǰ׺ U��A��F ��+11 �Ǻ�׺_Deprecated
				PrivateStaticClass, 
				StaticRegisterNativesAReflexActor, 
				sizeof(AReflexActor), 
				alignof(AReflexActor), 
				(EClassFlags)AReflexActor::StaticClassFlags, 
				AReflexActor::StaticClassCastFlags(), 
				AReflexActor::StaticConfigName(), 
				(UClass::ClassConstructorType)InternalConstructor<AReflexActor>, 
				(UClass::ClassVTableHelperCtorCallerType)InternalVTableHelperCtorCaller<AReflexActor>, 
				&AReflexActor::AddReferencedObjects, 
				&AReflexActor::Super::StaticClass, 
				&AReflexActor::WithinClass::StaticClass 
			); 
		} 
		return PrivateStaticClass; 
	}

	template<> SOMETEST_API UClass* StaticClass<AReflexActor>()
	{
		return AReflexActor::StaticClass();
	}

	static FCompiledInDefer Z_CompiledInDefer_UClass_AReflexActor(Z_Construct_UClass_AReflexActor, &AReflexActor::StaticClass, TEXT("/Script/SomeTest"), TEXT("AReflexActor"), false, nullptr, nullptr, nullptr);
	//DEFINE_VTABLE_PTR_HELPER_CTOR(AReflexActor);չ��
	AReflexActor::AReflexActor(FVTableHelper& Helper) : Super(Helper) {};

	PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif

// Sets default values
AReflexActor::AReflexActor()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReflexActor::BeginPlay()
{
	Super::BeginPlay();

}

// Called every frame
void AReflexActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

#endif
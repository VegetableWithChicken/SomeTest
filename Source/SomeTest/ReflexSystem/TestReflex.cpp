#include "TestReflex.h"

#if OFF_REFLEXACTOR

#include "UObject/GeneratedCppIncludes.h"
#include "SomeTest/ReflexSystem/ReflexActor.h"//引用依赖文件
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
	PRAGMA_DISABLE_DEPRECATION_WARNINGS
	//生成的ReflexActor代码的空链接函数
	void EmptyLinkFunctionForGeneratedCodeReflexActor() {}

	// Cross Module References
	//构造UClass对应的UClass对象，无注册
	SOMETEST_API UClass* Z_Construct_UClass_AReflexActor_NoRegister();
	//构造UClass对应的UClass对象，有注册
	SOMETEST_API UClass* Z_Construct_UClass_AReflexActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();

	//构造SomeTest本身的UPackage对象
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
			//	uint32                             PackageFlags =					PKG_CompiledIn | 0x00000000; // EPackageFlags 此包来自“编译于”类。
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
	//静态注册
	void AReflexActor::StaticRegisterNativesAReflexActor()
	{
	}

	//构造AReflexActor对应的UClass对象 无注册
	UClass* Z_Construct_UClass_AReflexActor_NoRegister()
	{
		return AReflexActor::StaticClass();
	}

	struct Z_Construct_UClass_AReflexActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
#if WITH_METADATA//需要在编辑器模式下
	//元数据的配对参数
	static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
	//定义特定C++类的特性
	static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
	//类参数
	static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	//依赖项
	UObject* (*const Z_Construct_UClass_AReflexActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,//构造UClass对应的UClass对象，有注册
		(UObject* (*)())Z_Construct_UPackage__Script_SomeTest,//构造SomeTest本身的UPackage对象
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ReflexSystem/ReflexActor.h" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	//定义特定C++类的特性 为抽象
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
		//METADATA_PARAMS(Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams, sizeof(Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams) - 1)展开
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


	//构造 注册成员
	UClass* Z_Construct_UClass_AReflexActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AReflexActor_Statics::ClassParams);
		}
		return OuterClass;
	}

	//IMPLEMENT_CLASS(AReflexActor, 1395401713);展开
	//#define IMPLEMENT_CLASS(AReflexActor, TClassCrc)
	//延迟注册
	static TClassCompiledInDefer<AReflexActor> AutoInitializeAReflexActor(TEXT("AReflexActor"), sizeof(AReflexActor), 1395401713); 

	UClass* AReflexActor::GetPrivateStaticClass() 
	{ 
		static UClass* PrivateStaticClass = NULL; 
		if (!PrivateStaticClass) 
		{ 
			/* this could be handled with templates, but we want it external to avoid code bloat */ 
			//这可以用模板处理，但我们希望它是外部的，以避免代码膨胀。
			GetPrivateStaticClassBody( 
				StaticPackage(), 
				(TCHAR*)TEXT("AReflexActor") + 1 + ((StaticClassFlags & CLASS_Deprecated) ? 11 : 0),//+1 为了去掉前缀 U、A、F ，+11 是后缀_Deprecated
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
	//DEFINE_VTABLE_PTR_HELPER_CTOR(AReflexActor);展开
	AReflexActor::AReflexActor(FVTableHelper& Helper) : Super(Helper) {};

	PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif
//////////////////////////////////////////////////////////////////////////////

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.
/*===========================================================================
	Generated code exported from UnrealHeaderTool.
	DO NOT modify this manually! Edit the corresponding .h files instead!
===========================================================================*/

#include "UObject/GeneratedCppIncludes.h"
#include "SomeTest/ReflexSystem/ReflexActor.h"
#ifdef _MSC_VER
#pragma warning (push)
#pragma warning (disable : 4883)
#endif
PRAGMA_DISABLE_DEPRECATION_WARNINGS
void EmptyLinkFunctionForGeneratedCodeReflexActor() {}
	// Cross Module References
	SOMETEST_API UClass* Z_Construct_UClass_AReflexActor_NoRegister();
	SOMETEST_API UClass* Z_Construct_UClass_AReflexActor();
	ENGINE_API UClass* Z_Construct_UClass_AActor();
	UPackage* Z_Construct_UPackage__Script_SomeTest();

	SOMETEST_API UFunction* Z_Construct_UFunction_AReflexActor_TestFunc2();
	SOMETEST_API UFunction* Z_Construct_UFunction_AReflexActor_TestFunc3();
	SOMETEST_API UFunction* Z_Construct_UFunction_AReflexActor_TestFunc4();
	SOMETEST_API UFunction* Z_Construct_UFunction_AReflexActor_TestFunc5();
	SOMETEST_API UFunction* Z_Construct_UFunction_AReflexActor_TestFunc6();

	ENGINE_API UClass* Z_Construct_UClass_UBoxComponent_NoRegister();

	// End Cross Module References
	static FName NAME_AReflexActor_TestFunc5 = FName(TEXT("TestFunc5"));
	void AReflexActor::TestFunc5(int32 IntValue)
	{
		ReflexActor_eventTestFunc5_Parms Parms;
		Parms.IntValue = IntValue;
		ProcessEvent(FindFunctionChecked(NAME_AReflexActor_TestFunc5), &Parms);
	}

	static FName NAME_AReflexActor_TestFunc6 = FName(TEXT("TestFunc6"));
	void AReflexActor::TestFunc6(bool bShowWindows)
	{
		ReflexActor_eventTestFunc6_Parms Parms;
		Parms.bShowWindows = bShowWindows ? true : false;
		ProcessEvent(FindFunctionChecked(NAME_AReflexActor_TestFunc6), &Parms);
	}

	void AReflexActor::StaticRegisterNativesAReflexActor()//锟斤拷一锟斤拷锟芥本锟角空碉拷
	{
		UClass* Class = AReflexActor::StaticClass();
		static const FNameNativePtrPair Funcs[] = {
			{ "TestFunc1", &AReflexActor::execTestFunc1 },
			{ "TestFunc2", &AReflexActor::execTestFunc2 },
			{ "TestFunc3", &AReflexActor::execTestFunc3 },
			{ "TestFunc4", &AReflexActor::execTestFunc4 },
			{ "TestFunc5", &AReflexActor::execTestFunc5 },
		};
		//注锟斤拷锟斤拷锟角的猴拷锟斤拷锟斤拷Class锟斤拷锟斤拷
		FNativeFunctionRegistrar::RegisterFunctions(Class, Funcs, (sizeof(UE4ArrayCountHelper(Funcs)) - 1)/*UE_ARRAY_COUNT(Funcs)*/);
	}

	//	void TestFunc1(){}
	struct Z_Construct_UFunction_AReflexActor_TestFunc1_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};

	//	void TestFunc1(){}
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AReflexActor_TestFunc1_Statics::Function_MetaDataParams[] = {
		{ "Category", "TestFunc" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	//	void TestFunc1(){}
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AReflexActor_TestFunc1_Statics::FuncParams = 
	{ 
		(UObject*(*)())Z_Construct_UClass_AReflexActor, 
		nullptr, 
		"TestFunc1", 
		nullptr, 
		nullptr, 
		0, 
		nullptr,
		0, 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		(EFunctionFlags)0x04020401, 
		0, 
		0, 
		METADATA_PARAMS(Z_Construct_UFunction_AReflexActor_TestFunc1_Statics::Function_MetaDataParams, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc1_Statics::Function_MetaDataParams))
	};

	//	void TestFunc1(){}
	UFunction* Z_Construct_UFunction_AReflexActor_TestFunc1()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AReflexActor_TestFunc1_Statics::FuncParams);
		}
		return ReturnFunction;
	}

	//bool TestFunc2()
	//{
	//	return false;
	//}
	struct Z_Construct_UFunction_AReflexActor_TestFunc2_Statics
	{
		//return bool
		struct ReflexActor_eventTestFunc2_Parms
		{
			bool ReturnValue;
		};

		static void NewProp_ReturnValue_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_ReturnValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};

	void Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::NewProp_ReturnValue_SetBit(void* Obj)
	{
		((ReflexActor_eventTestFunc2_Parms*)Obj)->ReturnValue = 1;
	}

	//锟斤拷锟斤拷值
	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::NewProp_ReturnValue = 
	{ 
		"ReturnValue", 
		nullptr,
		(EPropertyFlags)0x0010000000000580, 
		UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, 
		RF_Public | RF_Transient | RF_MarkAsNative,
		1, 
		sizeof(bool), 
		sizeof(ReflexActor_eventTestFunc2_Parms), 
		&Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::NewProp_ReturnValue_SetBit, 
		METADATA_PARAMS(nullptr, 0) 
	};

	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::NewProp_ReturnValue,
	};

#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::Function_MetaDataParams[] = {
		{ "Category", "TestFunc" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif

	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::FuncParams = 
	{ 
		(UObject*(*)())Z_Construct_UClass_AReflexActor, 
		nullptr, 
		"TestFunc2", 
		nullptr, 
		nullptr, 
		sizeof(ReflexActor_eventTestFunc2_Parms), 
		Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::PropPointers, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::PropPointers), 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		(EFunctionFlags)0x04020401, 
		0,
		0, 
		METADATA_PARAMS(Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::Function_MetaDataParams,
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::Function_MetaDataParams))
	};

	UFunction* Z_Construct_UFunction_AReflexActor_TestFunc2()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AReflexActor_TestFunc2_Statics::FuncParams);
		}
		return ReturnFunction;
	}

	//FString TestFunc3(int32 IntValue, const FString &Name, bool bShowWindows)
	//{
	//	return FString(TEXT("Hllo"));
	//}
	struct Z_Construct_UFunction_AReflexActor_TestFunc3_Statics
	{
		struct ReflexActor_eventTestFunc3_Parms
		{
			int32 IntValue;
			FString Name;
			bool bShowWindows;
			FString ReturnValue;
		};
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_ReturnValue;
		static void NewProp_bShowWindows_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowWindows;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_Name_MetaData[];
#endif
		static const UE4CodeGen_Private::FStrPropertyParams NewProp_Name;
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_IntValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};

	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_ReturnValue = 
	{ 
		"ReturnValue", 
		nullptr, 
		(EPropertyFlags)0x0010000000000580, 
		UE4CodeGen_Private::EPropertyGenFlags::Str, 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		1, 
		STRUCT_OFFSET(ReflexActor_eventTestFunc3_Parms, ReturnValue),
		METADATA_PARAMS(nullptr, 0) 
	};

	void Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_bShowWindows_SetBit(void* Obj)
	{
		((ReflexActor_eventTestFunc3_Parms*)Obj)->bShowWindows = 1;
	}

	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_bShowWindows = 
	{ 
		"bShowWindows",
		nullptr,
		(EPropertyFlags)0x0010000000000080, 
		UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		1, 
		sizeof(bool), 
		sizeof(ReflexActor_eventTestFunc3_Parms), 
		&Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_bShowWindows_SetBit, 
		METADATA_PARAMS(nullptr, 0)
	};

#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_Name_MetaData[] = {
		{ "NativeConst", "" },
	};
#endif

	const UE4CodeGen_Private::FStrPropertyParams Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_Name = 
	{ 
		"Name", 
		nullptr, 
		(EPropertyFlags)0x0010000000000080, 
		UE4CodeGen_Private::EPropertyGenFlags::Str, RF_Public | RF_Transient | RF_MarkAsNative, 
		1, 
		STRUCT_OFFSET(ReflexActor_eventTestFunc3_Parms, Name),
		METADATA_PARAMS(Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_Name_MetaData, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_Name_MetaData)) 
	};

	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_IntValue =
	{ 
		"IntValue", 
		nullptr, 
		(EPropertyFlags)0x0010000000000080, 
		UE4CodeGen_Private::EPropertyGenFlags::Int, 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		1, 
		STRUCT_OFFSET(ReflexActor_eventTestFunc3_Parms, IntValue), 
		METADATA_PARAMS(nullptr, 0) 
	};

	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_ReturnValue,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_bShowWindows,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_Name,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::NewProp_IntValue,
	};

#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::Function_MetaDataParams[] = {
		{ "Category", "TestFunc" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::FuncParams = 
	{ 
		(UObject*(*)())Z_Construct_UClass_AReflexActor, 
		nullptr, 
		"TestFunc3", 
		nullptr, 
		nullptr,
		sizeof(ReflexActor_eventTestFunc3_Parms), 
		Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::PropPointers, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::PropPointers), 
		RF_Public | RF_Transient | RF_MarkAsNative,
		(EFunctionFlags)0x04020401, 
		0, 
		0,
		METADATA_PARAMS(Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::Function_MetaDataParams, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::Function_MetaDataParams)) 
	};

	UFunction* Z_Construct_UFunction_AReflexActor_TestFunc3()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AReflexActor_TestFunc3_Statics::FuncParams);
		}
		return ReturnFunction;
	}

	//		void TestFunc4() {}
	struct Z_Construct_UFunction_AReflexActor_TestFunc4_Statics
	{
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AReflexActor_TestFunc4_Statics::Function_MetaDataParams[] = {
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AReflexActor_TestFunc4_Statics::FuncParams = 
	{ 
		(UObject*(*)())Z_Construct_UClass_AReflexActor, 
		nullptr, 
		"TestFunc4", 
		nullptr, 
		nullptr, 
		0, 
		nullptr, 
		0, 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		(EFunctionFlags)0x00020401,
		0, 
		0, 
		METADATA_PARAMS(Z_Construct_UFunction_AReflexActor_TestFunc4_Statics::Function_MetaDataParams, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc4_Statics::Function_MetaDataParams))
	};

	UFunction* Z_Construct_UFunction_AReflexActor_TestFunc4()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AReflexActor_TestFunc4_Statics::FuncParams);
		}
		return ReturnFunction;
	}

	//void TestFunc5(int32 IntValue);
	struct Z_Construct_UFunction_AReflexActor_TestFunc5_Statics
	{
		static const UE4CodeGen_Private::FIntPropertyParams NewProp_IntValue;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};
	const UE4CodeGen_Private::FIntPropertyParams Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::NewProp_IntValue = 
	{ 
		"IntValue", 
		nullptr,
		(EPropertyFlags)0x0010000000000080, 
		UE4CodeGen_Private::EPropertyGenFlags::Int,
		RF_Public | RF_Transient | RF_MarkAsNative, 
		1, 
		STRUCT_OFFSET(ReflexActor_eventTestFunc5_Parms, IntValue), 
		METADATA_PARAMS(nullptr, 0) 
	};

	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::NewProp_IntValue,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::Function_MetaDataParams[] = {
		{ "Category", "TestFunc" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::FuncParams = 
	{ 
		(UObject*(*)())Z_Construct_UClass_AReflexActor,
		nullptr, 
		"TestFunc5",
		nullptr, 
		nullptr, 
		sizeof(ReflexActor_eventTestFunc5_Parms), 
		Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::PropPointers, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::PropPointers), 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		(EFunctionFlags)0x08020C00,
		0, 
		0,
		METADATA_PARAMS(Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::Function_MetaDataParams, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::Function_MetaDataParams)) 
	};

	UFunction* Z_Construct_UFunction_AReflexActor_TestFunc5()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AReflexActor_TestFunc5_Statics::FuncParams);
		}
		return ReturnFunction;
	}

	//void TestFunc6(bool bShowWindows);
	struct Z_Construct_UFunction_AReflexActor_TestFunc6_Statics
	{
		static void NewProp_bShowWindows_SetBit(void* Obj);
		static const UE4CodeGen_Private::FBoolPropertyParams NewProp_bShowWindows;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Function_MetaDataParams[];
#endif
		static const UE4CodeGen_Private::FFunctionParams FuncParams;
	};

	void Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::NewProp_bShowWindows_SetBit(void* Obj)
	{
		((ReflexActor_eventTestFunc6_Parms*)Obj)->bShowWindows = 1;
	}

	const UE4CodeGen_Private::FBoolPropertyParams Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::NewProp_bShowWindows = 
	{ 
		"bShowWindows", 
		nullptr, 
		(EPropertyFlags)0x0010000000000080, 
		UE4CodeGen_Private::EPropertyGenFlags::Bool | UE4CodeGen_Private::EPropertyGenFlags::NativeBool, 
		RF_Public | RF_Transient | RF_MarkAsNative,
		1, 
		sizeof(bool), 
		sizeof(ReflexActor_eventTestFunc6_Parms),
		&Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::NewProp_bShowWindows_SetBit, 
		METADATA_PARAMS(nullptr, 0) 
	};

	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::NewProp_bShowWindows,
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::Function_MetaDataParams[] = {
		{ "Category", "TestFunc" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	const UE4CodeGen_Private::FFunctionParams Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::FuncParams = 
	{ 
		(UObject*(*)())Z_Construct_UClass_AReflexActor,
		nullptr,
		"TestFunc6",
		nullptr, 
		nullptr, 
		sizeof(ReflexActor_eventTestFunc6_Parms), 
		Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::PropPointers,
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::PropPointers), 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		(EFunctionFlags)0x08020800, 
		0, 
		0, 
		METADATA_PARAMS(Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::Function_MetaDataParams, 
		UE_ARRAY_COUNT(Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::Function_MetaDataParams)) 
	};

	UFunction* Z_Construct_UFunction_AReflexActor_TestFunc6()
	{
		static UFunction* ReturnFunction = nullptr;
		if (!ReturnFunction)
		{
			UE4CodeGen_Private::ConstructUFunction(ReturnFunction, Z_Construct_UFunction_AReflexActor_TestFunc6_Statics::FuncParams);
		}
		return ReturnFunction;
	}
	UClass* Z_Construct_UClass_AReflexActor_NoRegister()
	{
		return AReflexActor::StaticClass();
	}
	struct Z_Construct_UClass_AReflexActor_Statics
	{
		static UObject* (*const DependentSingletons[])();
		static const FClassFunctionLinkInfo FuncInfo[];
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam Class_MetaDataParams[];
#endif
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyBoxComponent2_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MyBoxComponent2;
#if WITH_METADATA
		static const UE4CodeGen_Private::FMetaDataPairParam NewProp_MyBoxComponent_MetaData[];
#endif
		static const UE4CodeGen_Private::FObjectPropertyParams NewProp_MyBoxComponent;
		static const UE4CodeGen_Private::FPropertyParamsBase* const PropPointers[];
		static const FCppClassTypeInfoStatic StaticCppClassTypeInfo;
		static const UE4CodeGen_Private::FClassParams ClassParams;
	};
	UObject* (*const Z_Construct_UClass_AReflexActor_Statics::DependentSingletons[])() = {
		(UObject* (*)())Z_Construct_UClass_AActor,
		(UObject* (*)())Z_Construct_UPackage__Script_SomeTest,
	};
	const FClassFunctionLinkInfo Z_Construct_UClass_AReflexActor_Statics::FuncInfo[] = {
		{ &Z_Construct_UFunction_AReflexActor_TestFunc1, "TestFunc1" }, // 743892907
		{ &Z_Construct_UFunction_AReflexActor_TestFunc2, "TestFunc2" }, // 148666166
		{ &Z_Construct_UFunction_AReflexActor_TestFunc3, "TestFunc3" }, // 338474474
		{ &Z_Construct_UFunction_AReflexActor_TestFunc4, "TestFunc4" }, // 3765401457
		{ &Z_Construct_UFunction_AReflexActor_TestFunc5, "TestFunc5" }, // 3504347143
		{ &Z_Construct_UFunction_AReflexActor_TestFunc6, "TestFunc6" }, // 1158434529
	};
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams[] = {
		{ "IncludePath", "ReflexSystem/ReflexActor.h" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent2_MetaData[] = {
		{ "Category", "BoxComponent" },
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent2 = 
	{ "MyBoxComponent2", 
		nullptr, 
		(EPropertyFlags)0x0040000000090009, 
		UE4CodeGen_Private::EPropertyGenFlags::Object, 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		1,
		STRUCT_OFFSET(AReflexActor, MyBoxComponent2), 
		Z_Construct_UClass_UBoxComponent_NoRegister,
		METADATA_PARAMS(Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent2_MetaData, 
		UE_ARRAY_COUNT(Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent2_MetaData))
	};

#if WITH_METADATA
	const UE4CodeGen_Private::FMetaDataPairParam Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent_MetaData[] = {
		{ "EditInline", "true" },
		{ "ModuleRelativePath", "ReflexSystem/ReflexActor.h" },
	};
#endif
	const UE4CodeGen_Private::FObjectPropertyParams Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent = 
	{ 
		"MyBoxComponent", 
		nullptr,
		(EPropertyFlags)0x0040000000080008, 
		UE4CodeGen_Private::EPropertyGenFlags::Object, 
		RF_Public | RF_Transient | RF_MarkAsNative, 
		1, 
		STRUCT_OFFSET(AReflexActor, MyBoxComponent), 
		Z_Construct_UClass_UBoxComponent_NoRegister, 
		METADATA_PARAMS(Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent_MetaData, 
		UE_ARRAY_COUNT(Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent_MetaData)) 
	};

	const UE4CodeGen_Private::FPropertyParamsBase* const Z_Construct_UClass_AReflexActor_Statics::PropPointers[] = {
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent2,
		(const UE4CodeGen_Private::FPropertyParamsBase*)&Z_Construct_UClass_AReflexActor_Statics::NewProp_MyBoxComponent,
	};

	const FCppClassTypeInfoStatic Z_Construct_UClass_AReflexActor_Statics::StaticCppClassTypeInfo = {
		TCppClassTypeTraits<AReflexActor>::IsAbstract,
	};

	const UE4CodeGen_Private::FClassParams Z_Construct_UClass_AReflexActor_Statics::ClassParams = {
		&AReflexActor::StaticClass,
		"Engine",
		&StaticCppClassTypeInfo,
		DependentSingletons,
		FuncInfo,
		Z_Construct_UClass_AReflexActor_Statics::PropPointers,
		nullptr,
		UE_ARRAY_COUNT(DependentSingletons),
		UE_ARRAY_COUNT(FuncInfo),
		UE_ARRAY_COUNT(Z_Construct_UClass_AReflexActor_Statics::PropPointers),
		0,
		0x009000A4u,
		METADATA_PARAMS(Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams, UE_ARRAY_COUNT(Z_Construct_UClass_AReflexActor_Statics::Class_MetaDataParams))
	};
	UClass* Z_Construct_UClass_AReflexActor()
	{
		static UClass* OuterClass = nullptr;
		if (!OuterClass)
		{
			UE4CodeGen_Private::ConstructUClass(OuterClass, Z_Construct_UClass_AReflexActor_Statics::ClassParams);
		}
		return OuterClass;
	}
	IMPLEMENT_CLASS(AReflexActor, 1509107908);
	template<> SOMETEST_API UClass* StaticClass<AReflexActor>()
	{
		return AReflexActor::StaticClass();
	}
	static FCompiledInDefer Z_CompiledInDefer_UClass_AReflexActor(Z_Construct_UClass_AReflexActor, &AReflexActor::StaticClass, TEXT("/Script/SomeTest"), TEXT("AReflexActor"), false, nullptr, nullptr, nullptr);
	DEFINE_VTABLE_PTR_HELPER_CTOR(AReflexActor);
	PRAGMA_ENABLE_DEPRECATION_WARNINGS
#ifdef _MSC_VER
#pragma warning (pop)
#endif


//////////////////////////////////////////////////////////////////////////////
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
// Fill out your copyright notice in the Description page of Project Settings.


#include "TestDelegateCharacter.h"

void ATestDelegateCharacter::StaticCharacterDelegateProc(int nCode)
{
	UE_LOG(LogTemp, Log, TEXT("StaticCharacterDelegateProc : %d"), nCode);
}

void ATestDelegateCharacter::StaticDelegateProc(int nCode)
{
	UE_LOG(LogTemp, Log, TEXT("StaticDelegateProc : %d"), nCode);
}

void ATestDelegateCharacter::OnBind()
{
	// Bind Static
	CharacterDelegate1.BindStatic(StaticDelegateProc);

	CharacterDelegate2.BindStatic(ATestDelegateCharacter::StaticCharacterDelegateProc);

	// Bind Raw
	DelegateCppTestClass Obj1;
	CharacterDelegate3.BindRaw(&Obj1, &DelegateCppTestClass::CppDelegateProc);

	// Bind Lambda
	auto LambdaDelegateProc = [](int nCode)->void
	{
		UE_LOG(LogTemp, Log, TEXT("LambdaDelegateProc : %d"), nCode);
	};

	CharacterDelegate4.BindLambda(LambdaDelegateProc);

	CharacterDelegate5.BindLambda(
		[](int nCode)->void
	{
		UE_LOG(LogTemp, Log, TEXT("LambdaDelegateProc2 : %d"), nCode);
	}
	);

	// Bind Weak Lambda
	auto WeakLambdaDelegateProc = [](int nCode)->void
	{
		UE_LOG(LogTemp, Log, TEXT("WeakLambdaDelegateProc : %d"), nCode);
	};
	UDelegatepTestClass* UObj1 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegate6.BindWeakLambda(UObj1, WeakLambdaDelegateProc);

	UDelegatepTestClass* UObj2 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegate7.BindWeakLambda(
		UObj2, [](int nCode)->void
	{
		UE_LOG(LogTemp, Log, TEXT("WeakLambdaDelegateProc2 : %d"), nCode);
	}
	);

	// Bind SP(Shared Pointer)
	TSharedRef<DelegateCppTestClass> ObjSP1 = MakeShareable(new DelegateCppTestClass());
	CharacterDelegate8.BindSP(ObjSP1, &DelegateCppTestClass::CppDelegateProc2);

	TSharedRef<DelegateCppTestClass> ObjSP2 = MakeShared<DelegateCppTestClass>();
	CharacterDelegate9.BindSP(ObjSP2, &DelegateCppTestClass::CppDelegateProc3);

	// Bind Thread Safe SP(Shared Pointer)
	TSharedRef<DelegateCppTestClass, ESPMode::ThreadSafe> ObjSafeSP1 = MakeShareable(new DelegateCppTestClass());
	CharacterDelegate10.BindThreadSafeSP(ObjSafeSP1, &DelegateCppTestClass::CppDelegateProc4);

	TSharedRef<DelegateCppTestClass, ESPMode::ThreadSafe> ObjSafeSP2 = MakeShared<DelegateCppTestClass, ESPMode::ThreadSafe>();
	CharacterDelegate11.BindThreadSafeSP(ObjSafeSP2, &DelegateCppTestClass::CppDelegateProc5);

	// Bind UObject
	UDelegatepTestClass* UObj3 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegate12.BindUObject(UObj3, &UDelegatepTestClass::DelegateProc1);

	// Bind UFunction
	UDelegatepTestClass* UObj4 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegate13.BindUFunction(UObj4, STATIC_FUNCTION_FNAME(TEXT("UDelegatepTestClass::DelegateUFunctionProc1")));
}

void ATestDelegateCharacter::OnExecute()
{
	CharacterDelegate1.ExecuteIfBound(1);
	CharacterDelegate2.ExecuteIfBound(2);
	CharacterDelegate3.ExecuteIfBound(3);
	CharacterDelegate4.ExecuteIfBound(4);
	CharacterDelegate5.ExecuteIfBound(5);
	CharacterDelegate6.ExecuteIfBound(6);
	CharacterDelegate7.ExecuteIfBound(7);
	CharacterDelegate8.ExecuteIfBound(8);
	CharacterDelegate9.ExecuteIfBound(9);
	CharacterDelegate10.ExecuteIfBound(10);
	CharacterDelegate11.ExecuteIfBound(11);
	CharacterDelegate12.ExecuteIfBound(12);
	if (CharacterDelegate13.IsBound())
	{
		CharacterDelegate13.Execute(13);
	}
}

void ATestDelegateCharacter::OnUnbind()
{
	CharacterDelegate1.Unbind();
	CharacterDelegate2.Unbind();
	CharacterDelegate3.Unbind();
	CharacterDelegate4.Unbind();
	CharacterDelegate5.Unbind();
	CharacterDelegate6.Unbind();
	CharacterDelegate7.Unbind();
	CharacterDelegate8.Unbind();
	CharacterDelegate9.Unbind();
	CharacterDelegate10.Unbind();
	CharacterDelegate11.Unbind();
	CharacterDelegate12.Unbind();
	CharacterDelegate13.Unbind();
}

void ATestDelegateCharacter::StaticDelegateProc2(int nCode)
{
	UE_LOG(LogTemp, Log, TEXT("StaticDelegateProc2 : %d"), nCode);
}

void ATestDelegateCharacter::OnDelegateMulticastTest()
{
	// Add Static
	bool b1 = CharacterDelegateMulticast1.IsBound(); // false

	FDelegateHandle HandleMC1 = CharacterDelegateMulticast1.AddStatic(StaticDelegateProc); // ��ʵ������Ϊ��1
	CharacterDelegateMulticast1.AddStatic(ATestDelegateCharacter::StaticCharacterDelegateProc); // ��ʵ������Ϊ��2

	bool b2 = CharacterDelegateMulticast1.IsBound(); // true
	bool b3 = CharacterDelegateMulticast1.IsBoundToObject(this); // false

	CharacterDelegateMulticast1.Remove(HandleMC1); // ��ʵ������Ϊ��1

	FCharacterDelegate_Multicast::FDelegate MC1 = FCharacterDelegate_Multicast::FDelegate::CreateStatic(StaticDelegateProc2);
	CharacterDelegateMulticast1.Add(MC1); // ��ʵ������Ϊ��2
	CharacterDelegateMulticast1.Broadcast(1); // ִ�а�ʵ���б���2����  ע��ִ��˳������뺯�������˳����ͬ


	// Add Raw
	DelegateCppTestClass ObjMC1;
	CharacterDelegateMulticast2.AddRaw(&ObjMC1, &DelegateCppTestClass::CppDelegateProc); // ��ʵ������Ϊ��1
	CharacterDelegateMulticast2.AddRaw(&ObjMC1, &DelegateCppTestClass::CppDelegateProc2); // ��ʵ������Ϊ��2
	CharacterDelegateMulticast2.AddStatic(ATestDelegateCharacter::StaticCharacterDelegateProc); // ��ʵ������Ϊ��3

	bool b4 = CharacterDelegateMulticast2.IsBoundToObject(&ObjMC1); // true

	CharacterDelegateMulticast2.RemoveAll(&ObjMC1); // CppDelegateProc��CppDelegateProc2��ɾ������ʵ������Ϊ��1

	bool b5 = CharacterDelegateMulticast2.IsBoundToObject(&ObjMC1); // false

	CharacterDelegateMulticast2.Broadcast(2); // ִ�а�ʵ���б���1����  ע��ִ��˳������뺯�������˳����ͬ

	CharacterDelegateMulticast2.Clear(); // ��ʵ������Ϊ��0

	// Add Lambda
	auto LambdaDelegateMCProc = [](int nCode)->void
	{
		UE_LOG(LogTemp, Log, TEXT("LambdaDelegateMCProc : %d"), nCode);
	};
	CharacterDelegateMulticast3.AddLambda(LambdaDelegateMCProc);// ��ʵ������Ϊ��1

	CharacterDelegateMulticast3.AddLambda(
		[](int nCode)->void
	{
		UE_LOG(LogTemp, Log, TEXT("LambdaDelegateMCProc2 : %d"), nCode);
	}
	);// ��ʵ������Ϊ��2
	CharacterDelegateMulticast3.Broadcast(3);// ִ�а�ʵ���б���2����  ע��ִ��˳������뺯�������˳����ͬ

	// Add Weak Lambda
	auto WeakLambdaDelegateMCProc = [](int nCode)->void
	{
		UE_LOG(LogTemp, Log, TEXT("WeakLambdaDelegateMCProc : %d"), nCode);
	};
	UDelegatepTestClass* UObjMC1 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegateMulticast4.AddWeakLambda(UObjMC1, WeakLambdaDelegateMCProc);// ��ʵ������Ϊ��1

	UDelegatepTestClass* UObjMC2 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegateMulticast4.AddWeakLambda(
		UObjMC2, [](int nCode)->void
	{
		UE_LOG(LogTemp, Log, TEXT("WeakLambdaDelegateMCProc2 : %d"), nCode);
	}
	);// ��ʵ������Ϊ��2
	CharacterDelegateMulticast4.Broadcast(4);// ִ�а�ʵ���б���2����  ע��ִ��˳������뺯�������˳����ͬ

	// Add SP(Shared Pointer)
	TSharedRef<DelegateCppTestClass> ObjMCSP1 = MakeShareable(new DelegateCppTestClass());
	CharacterDelegateMulticast5.AddSP(ObjMCSP1, &DelegateCppTestClass::CppDelegateProc2);// ��ʵ������Ϊ��1

	TSharedRef<DelegateCppTestClass> ObjMCSP2 = MakeShared<DelegateCppTestClass>();
	CharacterDelegateMulticast5.AddSP(ObjMCSP2, &DelegateCppTestClass::CppDelegateProc3);// ��ʵ������Ϊ��2
	CharacterDelegateMulticast5.Broadcast(5);

	// Add Thread Safe SP(Shared Pointer)
	TSharedRef<DelegateCppTestClass, ESPMode::ThreadSafe> ObjSafeMCSP1 = MakeShareable(new DelegateCppTestClass());
	CharacterDelegateMulticast6.AddThreadSafeSP(ObjSafeMCSP1, &DelegateCppTestClass::CppDelegateProc4);// ��ʵ������Ϊ��1

	TSharedRef<DelegateCppTestClass, ESPMode::ThreadSafe> ObjSafeMCSP2 = MakeShared<DelegateCppTestClass, ESPMode::ThreadSafe>();
	CharacterDelegateMulticast6.AddThreadSafeSP(ObjSafeMCSP2, &DelegateCppTestClass::CppDelegateProc5);// ��ʵ������Ϊ��2

	CharacterDelegateMulticast6.Broadcast(6);// ִ�а�ʵ���б���2����  ע��ִ��˳������뺯�������˳����ͬ

	// Add UObject
	UDelegatepTestClass* UObjMC3 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegateMulticast7.AddUObject(UObjMC3, &UDelegatepTestClass::DelegateProc1);// ��ʵ������Ϊ��1
	CharacterDelegateMulticast7.AddUObject(UObjMC3, &UDelegatepTestClass::DelegateProc2);// ��ʵ������Ϊ��2

	CharacterDelegateMulticast7.Broadcast(7);// ִ�а�ʵ���б���2����  ע��ִ��˳������뺯�������˳����ͬ

	// Add UFunction
	UDelegatepTestClass* UObjMC4 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegateMulticast8.AddUFunction(UObjMC4, STATIC_FUNCTION_FNAME(TEXT("UDelegatepTestClass::DelegateUFunctionProc1")));// ��ʵ������Ϊ��1
	CharacterDelegateMulticast8.Broadcast(8);// ִ�а�ʵ���б���1����  ע��ִ��˳������뺯�������˳����ͬ
}

void ATestDelegateCharacter::OnTriggerEvent(int nCode)
{
	UE_LOG(LogTemp, Log, TEXT("OnTriggerEvent : %d"), nCode);
}

void ATestDelegateCharacter::OnEventTest()
{
	CharacterEvent.AddUObject(this, &ATestDelegateCharacter::OnTriggerEvent);
	CharacterEvent.Broadcast(1);
}

void ATestDelegateCharacter::OnDelegateDynamicTest()
{
	bool bd1 = CharacterDelegateDynamic.IsBound(); // false

	UDelegatepTestClass* UObjDy1 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	CharacterDelegateDynamic.BindUFunction(UObjDy1, STATIC_FUNCTION_FNAME(TEXT("UDelegatepTestClass::DelegateUFunctionProc1")));// ��ʵ������Ϊ��1

	bool bd2 = CharacterDelegateDynamic.IsBound(); // true

	CharacterDelegateDynamic.ExecuteIfBound(1);

	CharacterDelegateDynamic.Unbind();

	// ʹ��BindDynamic��
	CharacterDelegateDynamic2.BindDynamic(this, &ATestDelegateCharacter::DynamicMulticastProc);
	if (CharacterDelegateDynamic2.IsBound()) // true
	{
		CharacterDelegateDynamic2.Execute(2);
	}

	CharacterDelegateDynamic2.Clear(); // ������Unbindһ�����ڲ���ֱ�ӵ���Unbind����
}

bool ATestDelegateCharacter::DynamicMulticastProc(int nCode)
{
	UE_LOG(LogTemp, Log, TEXT("DynamicMulticastProc : %d"), nCode);
	return true;
}

void ATestDelegateCharacter::OnDelegateDynamicMulticastTest()
{
	UDelegatepTestClass* UObjDMC1 = NewObject<UDelegatepTestClass>(this, UDelegatepTestClass::StaticClass());
	// ʹ��AddDynamic��
	//CharacterDelegateDynamicMulticast.AddDynamic(UObjDMC1, &UDelegatepTestClass::DelegateProc1); // ����ʱ����Unable to bind delegate (function might not be marked as a UFUNCTION or object may be pending kill)
	CharacterDelegateDynamicMulticast.AddDynamic(UObjDMC1, &UDelegatepTestClass::DelegateUFunctionProc1); // ��ʵ������Ϊ��1
	//CharacterDelegateDynamicMulticast.AddDynamic(UObjDMC1, &UDelegatepTestClass::DelegateUFunctionProc1); // ����ʱ���� ����DelegateUFunctionProc1�İ�ʵ���Ѵ���
	CharacterDelegateDynamicMulticast.AddDynamic(UObjDMC1, &UDelegatepTestClass::DelegateUFunctionProc2); // ��ʵ������Ϊ��2

	// ʹ��AddUniqueDynamic��
	CharacterDelegateDynamicMulticast.AddUniqueDynamic(this, &ATestDelegateCharacter::DynamicMulticastProc1); // ��ʵ������Ϊ��3
	CharacterDelegateDynamicMulticast.AddUniqueDynamic(this, &ATestDelegateCharacter::DynamicMulticastProc1); // ����DynamicMulticastProc�İ�ʵ���Ѵ���
	CharacterDelegateDynamicMulticast.AddUniqueDynamic(this, &ATestDelegateCharacter::DynamicMulticastProc2); // ��ʵ������Ϊ��4

	FScriptDelegate delegateVar1; // FScriptDelegate��ΪTScriptDelegate<> //typedef TScriptDelegate<> FScriptDelegate;
	delegateVar1.BindUFunction(this, STATIC_FUNCTION_FNAME(TEXT("ATestDelegateCharacter::DynamicMulticastProc3")));
	CharacterDelegateDynamicMulticast.Add(delegateVar1); // ��ʵ������Ϊ��5
	FScriptDelegate delegateVar2;
	delegateVar2.BindUFunction(this, STATIC_FUNCTION_FNAME(TEXT("ATestDelegateCharacter::DynamicMulticastProc3")));
	//CharacterDelegateDynamicMulticast.Add(delegateVar2); // ����ʱ���� ����DynamicMulticastProc3�İ�ʵ���Ѵ���
	CharacterDelegateDynamicMulticast.AddUnique(delegateVar2); // ����DynamicMulticastProc3�İ�ʵ���Ѵ���

	// ʹ��RemoveDynamic��
	CharacterDelegateDynamicMulticast.RemoveDynamic(this, &ATestDelegateCharacter::DynamicMulticastProc2); // ��ʵ������Ϊ��4

	// ʹ��IsAlreadyBound��
	bool bDMC1 = CharacterDelegateDynamicMulticast.IsAlreadyBound(this, &ATestDelegateCharacter::DynamicMulticastProc3);// true

	CharacterDelegateDynamicMulticast.Remove(delegateVar2); // ��ʵ������Ϊ��3
	CharacterDelegateDynamicMulticast.Remove(UObjDMC1, STATIC_FUNCTION_FNAME(TEXT("UDelegatepTestClass::DelegateUFunctionProc1")));// ��ʵ������Ϊ��2

	bool bDMC2 = CharacterDelegateDynamicMulticast.IsAlreadyBound(this, &ATestDelegateCharacter::DynamicMulticastProc3); // false

	CharacterDelegateDynamicMulticast.RemoveAll(this); // ��ʵ������Ϊ��1

	CharacterDelegateDynamicMulticast.Broadcast(300); // ִ�а�ʵ���б���1����  ע��ִ��˳������뺯�������˳����ͬ

	CharacterDelegateDynamicMulticast.Clear(); // ������а�ʵ��
}

void ATestDelegateCharacter::DynamicMulticastProc1(int nCode)
{
	UE_LOG(LogTemp, Log, TEXT("DynamicMulticastProc1 : %d"), nCode);
}

void ATestDelegateCharacter::DynamicMulticastProc2(int nCode)
{
	UE_LOG(LogTemp, Log, TEXT("DynamicMulticastProc2 : %d"), nCode);
}

void ATestDelegateCharacter::DynamicMulticastProc3(int nCode)
{
	UE_LOG(LogTemp, Log, TEXT("DynamicMulticastProc3 : %d"), nCode);
}

void ATestDelegateCharacter::BrocastCharacterDelegateDynamicMulticast(int nCode)
{
	CharacterDelegateDynamicMulticast2.Broadcast(nCode);
	CharacterDelegateDynamicMulticast2.Clear();
}

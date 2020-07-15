// Copyright 1998-2018 Epic Games, Inc. All Rights Reserved.
#pragma once

#include "CoreMinimal.h"

//һ������
struct FParamElement
{
	FName Name;
	bool bConst;//const
	bool bPointer;//*
	bool bReference;//&
	FName Type;//float int ...

	FParamElement()
		: bPointer(false)
		, bReference(false)
		, bConst(false)
	{}
};

//����
struct FVariableAnalysis :public FParamElement
{
	FString CodeType;//�ǲ��� Resources
	bool bStatic;

	FVariableAnalysis()
		:bStatic(false)
	{}
};

//��������
struct FFunctionAnalysis
{
	TArray<FParamElement> ParamArray;
	FParamElement Return;

	FName FunctionName;
	bool bStatic;
	bool bVirtual;
	FString CodeType;

	FFunctionAnalysis()
		:bStatic(false)
		, bVirtual(false)
	{}
};

//�������Ա
struct FClassAnalysis
{
	TArray<FFunctionAnalysis> Function;
	TArray<FVariableAnalysis> Variable;

	FName ClassName;
	TArray<FName> InheritName;
	FName CodeCPPName;

	int32 CodeLine;//������������У�
	FString Include;
};

enum ECollectionParmType
{
	Type_Return,
	Type_Parm,
};

//IUnrealTypeCollection
class IUTC
{
public:
	//�ռ���ͨ��·���ռ�����Ϣ
	virtual bool Collection(const FString &Paths, FClassAnalysis &ClassAnalysis) = 0;
};

//IUnrealTypeBuilder
class IUTB
{
public:
	//����������Ϣ
	virtual bool Builder(const FClassAnalysis &ClassAnalysis) = 0;
};

class FConstructionManagement
{
public:
	//ִ�����ǵ����߼�
	void Builder();
};
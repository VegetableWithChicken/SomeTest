#pragma once
#include "CoreMinimal.h"

struct FFunctionTerminal
{
	FName Name;

	FName Type;
	FString DefaultValue;
	UObject* DefaultObject;
	FText DefaultTextValue;

	//�ö��ӵ���������
	TEnumAsByte<enum EEdGraphPinDirection> Direction;

	//��Ϊ��ֵ
	UEdGraphPin *RHS;
	TArray<UEdGraphPin*> LHS;

	FGuid PinId;

	//�Ƿ������� ������Ӳ��������ڵ������ �� ����������
	bool IsLink;
	bool IsBPVariable;
	FFunctionTerminal()
		:DefaultObject(nullptr)	
		,RHS(nullptr)
		,IsLink(false)
		, IsBPVariable(false)
	{}
};
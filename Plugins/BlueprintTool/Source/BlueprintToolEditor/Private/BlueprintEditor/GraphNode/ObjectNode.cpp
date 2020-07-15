#include "BlueprintEditor/GraphNode/ObjectNode.h"
#include "Type/BTEType.h"

VariableIndex(UObject)

UObjectNode::UObjectNode()
{
	VariableName = *FString::Printf(TEXT("%s_%i"), *GetClass()->GetName(), IncreaseProgressively(UObject));
}

void UObjectNode::AllocateDefaultPins()
{
	CreatePin(EEdGraphPinDirection::EGPD_Output, FPC_Public::PC_Object, FName(), VariableName);
}

void UObjectNode::SetValue(UObject *InValue)
{
	Value = InValue;

	if (Value)
	{
		FString L, R;
		//Value->GetOuter()->GetName() = /Game/Head_Hight
		Value->GetOuter()->GetName().Split(TEXT("/"), &L, &R, ESearchCase::IgnoreCase, ESearchDir::FromEnd);
		//DefaultValue = /Game/Head_Hight.Head_Hight
		FString DefaultValue = Value->GetOuter()->GetName() + TEXT(".") + R;
		//NewPaths = StaticMesh'/Game/Head_Hight.Head_Hight'
		//Value->GetClass()->GetName() = StaticMesh
		FString NewPaths = FString::Printf(TEXT("%s\'%s\'"), *Value->GetClass()->GetName(), *DefaultValue);

		//UStaticMesh * NewActorMesh = LoadObject<UStaticMesh>(NULL, *NewPaths);

		Pins[0]->DefaultValue = NewPaths;
	}
}

#if WITH_EDITOR
void UObjectNode::PostEditChangeChainProperty(struct FPropertyChangedChainEvent& PropertyChangedEvent)
{
	if (PropertyChangedEvent.GetPropertyName() == "VariableName")
	{
		Pins[0]->PinName = VariableName;
	}
	else if (PropertyChangedEvent.GetPropertyName() == "Value")
	{
		//�Ӵ��������ȡ���ڴ�
		//LoadObject()
		//LoadClass()

		//���ڴ������Ҿ������
		//FindObject()
		
		//StaticMesh'/Game/Head_Hight.Head_Hight'

		SetValue(Value);

		Update.ExecuteIfBound();
	}

	Super::PostEditChangeChainProperty(PropertyChangedEvent);
}
#endif

#include "TestGraphSchema.h"
#include "TestNode_HelloWorld.h"
#include "ScopedTransaction.h"

#define LOCTEXT_NAMESPACE "TestGraphSchema"

void UTestGraphSchema::GetGraphContextActions(FGraphContextMenuBuilder& ContextMenuBuilder) const
{
	//FTestGraphSchemaAction(FText InNodeCategory, FText InMenuDesc, FText InToolTip, const int32 InGrouping, FText InKeywords = FText(), int32 InSectionID = 0)
	TSharedPtr<FTestGraphSchemaAction> NewNodeAction(new
		FTestGraphSchemaAction(
			LOCTEXT("A", "Grap Node"),
			LOCTEXT("Desc", "MyTestAA"),
			LOCTEXT("NewGraphText", "Add a Node"),
			0));

	NewNodeAction->NodeHelloWorld = NewObject<UTestNode_HelloWorld>(ContextMenuBuilder.OwnerOfTemporaries);//������������ʱģ��ڵ�
	ContextMenuBuilder.AddAction(NewNodeAction);

	//NewNodeAction->K2Node_Event = NewObject<UK2Node_Event>(ContextMenuBuilder.OwnerOfTemporaries);
	//ContextMenuBuilder.AddAction(NewNodeAction);
}

void UTestGraphSchema::GetContextMenuActions(const UEdGraph* CurrentGraph, const UEdGraphNode* InGraphNode, const UEdGraphPin* InGraphPin, class FMenuBuilder* MenuBuilder, bool bIsDebugging) const
{

}

UEdGraphNode* FTestGraphSchemaAction::PerformAction(class UEdGraph* ParentGraph, UEdGraphPin* FromPin, const FVector2D Location, bool bSelectNewNode /*= true*/)
{
	UEdGraphNode *UEdResultNode = nullptr;
	if (NodeHelloWorld != nullptr)
	{
		const FScopedTransaction Transaction(LOCTEXT("FF", "Hell:NewNode"));

		ParentGraph->Modify();

		if (FromPin != nullptr)
		{
			FromPin->Modify();
		}

		NodeHelloWorld->Rename(nullptr, ParentGraph);
		ParentGraph->AddNode(NodeHelloWorld, true, bSelectNewNode);

		NodeHelloWorld->CreateNewGuid();
		NodeHelloWorld->PostPlacedNewNode();
		NodeHelloWorld->AllocateDefaultPins();
		NodeHelloWorld->AutowireNewNode(FromPin);

		NodeHelloWorld->NodePosX = Location.X;
		NodeHelloWorld->NodePosY = Location.Y;

		NodeHelloWorld->SetFlags(RF_Transactional);//Object is transactional.�����л�����GC�����й�

		UEdResultNode = NodeHelloWorld;
	}
	return UEdResultNode;
}

#undef LOCTEXT_NAMESPACE
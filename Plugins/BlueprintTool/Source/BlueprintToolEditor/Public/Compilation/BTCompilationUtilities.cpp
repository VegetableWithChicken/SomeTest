#include "BTCompilationUtilities.h"
#include "BlueprintEditor/Core/Architect/K3Node.h"
#include "Type/BTEType.h"
#include "BTCompilationContext.h"
#include "BTFunctionContext.h"
#include "ScriptObject.h"

TArray<UEdGraphNode*> GetEventRoot(UEdGraph *EdGraph)
{
	TArray<UEdGraphNode*> EventRoot;
	for (TArray<UEdGraphNode*>::TConstIterator It(EdGraph->Nodes); It; ++It)
	{
		UK3Node* RootNode = Cast<UK3Node>(*It);
		if (RootNode->Function)
		{
			if (RootNode->Function->GetMetaData("CodeType") == "Event")
			{
				EventRoot.Add(RootNode);
			}
		}
	}

	return EventRoot;
}

void TraverseNodes(UEdGraphNode* Node, TArray<UEdGraphNode*> &VisitedNodes)
{
	VisitedNodes.Add(Node);

	for (int32 i = 0; i < Node->Pins.Num(); ++i)
	{
		UEdGraphPin* MyPin = Node->Pins[i];
		if ((MyPin->Direction == EGPD_Output) && 
			(MyPin->PinType.PinCategory == FPC_Public::PC_Exec))
		{
			for (int32 j = 0; j < MyPin->LinkedTo.Num(); ++j)
			{
				UEdGraphPin* OtherPin = MyPin->LinkedTo[j];
				if (OtherPin)
				{
					UEdGraphNode* OtherNode = OtherPin->GetOwningNode();
					if (!VisitedNodes.Contains(OtherNode))
					{
						TraverseNodes(OtherNode, VisitedNodes);
					}
				}
			}
		}
	}
}

void PruneIsolatedNodes(const TArray<UEdGraphNode*>& RootSet, TArray<TArray<UEdGraphNode*>>& GraphNodes)
{
	for (TArray<UEdGraphNode*>::TConstIterator It(RootSet); It; ++It)
	{
		GraphNodes.Add(TArray<UEdGraphNode*>());
		UEdGraphNode* RootNode = *It;

		TraverseNodes(RootNode, GraphNodes[GraphNodes.Num() - 1]);
	}
}

void FBTCompilationUtilities::FlushCompilationQueueImpl(UBlueprintData *Data)
{
	TArray<UEdGraphNode*> RootSet = GetEventRoot(Data->EdGraph);
	if (RootSet.Num() >= 1)
	{
		//��һ�׶Σ��޼����ǵ���ͼ��ȥ�����������ӵ���ͼ
		TArray<TArray<UEdGraphNode*>> VisitedNodes;
		PruneIsolatedNodes(RootSet, VisitedNodes);

		//�ڶ��׶����EventNode���ֽ���
		for (TArray<UEdGraphNode*> Nodes : VisitedNodes)
		{
			UK3Node *K3 = Cast<UK3Node>(Nodes[0]);
			K3->Function->Script.Empty();
		}

		FBTCompilerContext BTCompilerContext;
		for (TArray<TArray<UEdGraphNode*>>::TConstIterator It(VisitedNodes); It; ++It)
		{
			TArray<UEdGraphNode*> GraphNodeTmp = *It;

			//�����׶�ע��ű������������Զ����UBT���߲�ѯ
			for (UEdGraphNode *Tmp : GraphNodeTmp)
			{
				UK3Node *K3Node = Cast<UK3Node>(Tmp);
				UBTScriptObject::FunctionList.Add(K3Node->Function);
			}

			//���Ľ׶� �������ǵĺ������뻷���Լ����
			FBTFunctionContext BTFunctionContext;
			BTFunctionContext.LinearExecutionList = GraphNodeTmp;
			BTCompilerContext.CompileFunction(BTFunctionContext);
		}
	}
}

void FBTCompilationUtilities::ClearByte(UBlueprintData *Data)
{
	TArray<UEdGraphNode*> RootSet = GetEventRoot(Data->EdGraph);

	for (UEdGraphNode* Nodes : RootSet)
	{
		UK3Node *K3 = Cast<UK3Node>(Nodes);
		K3->Function->Script.Empty();
	}
}


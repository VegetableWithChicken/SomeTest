#pragma once

#include "EdGraph/EdGraph.h"
#include "BPArchitectEdGraph.generated.h"


UCLASS()
class UBPArchitectEdGraph : public UEdGraph
{
	//GENERATED_UCLASS_BODY()������֮ǰ�汾�ĺ꣬�Զ����ɴ���ָ�������Ĺ��캯���������û���ȥ�������캯������Ҫ��CPP��ʵ�֣����򱨴�֮���Ա��public��

	//GENERATED_BODY()�������°汾�ĺ꣬�����ɹ��캯���������Ҫ�Զ��壬��Ҫ�Լ����������壬֮���Ա��private��

	//�ܽ᣺ʹ�ú��ߣ���Ҫʹ��ǰ�ߡ�

	GENERATED_UCLASS_BODY()
public:

	void InitializeGraph();

	UEdGraphNode* CreateNewNode(UObject* AssetObject, const FVector2D& Location);

	template<typename TNodeClass>
	TNodeClass* CreateNewNode(const FVector2D& Location)
	{
		TNodeClass* Node = NewObject<TNodeClass>(this);
		Node->Rename(NULL, this, REN_NonTransactional);
		this->AddNode(Node, true, false);

		Node->CreateNewGuid();
		Node->PostPlacedNewNode();
		Node->AllocateDefaultPins();

		Node->NodePosX = Location.X;
		Node->NodePosY = Location.Y;

		Node->SnapToGrid(16);

		return Node;
	}
};


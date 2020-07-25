
#pragma once

#include "CoreMinimal.h"
#include "BlueprintData.generated.h"

UCLASS()
class BLUEPRINTTOOLRUNTIME_API UBlueprintData : public UObject
{
	GENERATED_BODY()

public:

	UBlueprintData();

#if WITH_EDITORONLY_DATA
	UPROPERTY()
	class UEdGraph* EdGraph;
#endif // WITH_EDITORONLY_DATA

	//ͳһ���ٵ�ǰ���������
	static void AddReferencedObjects(UObject* InThis, FReferenceCollector& Collector);
};
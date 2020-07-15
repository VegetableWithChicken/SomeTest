#pragma once


#include "CoreMinimal.h"
#include "SimpleCode.h"
//#include "SimpleCodeLibrary.Reflect.h"
#include "TTTSimpleCodeLibrary.BT.h"
#include "SimpleCodeLibrary.generated.h"

#if PLATFORM_WINDOWS
#pragma optimize("",off) 
#endif

UCLASS()
class BLUEPRINTTOOLCODE_API USimpleCodeLibrary : public USimpleCode
{
	GENERATED_BODY()
public:
	GENERATED_BT_BODY()
public:
	UFUNCTION(Meta = (CodeType = "Describe", Group = "SimpleCodeLibrary"))
	static void SetLocation(UStaticMeshComponent *Target, FVector InLocation);

	UFUNCTION(Meta = (CodeType = "Describe", Group = "SimpleCodeLibrary"))
	static void SetRotator(UStaticMeshComponent *Target, FRotator InRot);

	//����ģ��
	UFUNCTION(Meta = (CodeType = "Describe", Group = "SimpleCodeLibrary"))
	static void SetMesh(UStaticMeshComponent *Target, UStaticMesh *InMesh);

	//���ò���
	UFUNCTION(Meta = (CodeType = "Describe", Group = "SimpleCodeLibrary"))
	static void SetMaterial(UStaticMeshComponent *Target, int32 Index, UMaterialInterface *InMaterial);

	//���ò��ʵ���ɫ
	UFUNCTION(Meta = (CodeType = "Describe", Group = "SimpleCodeLibrary"))
	static void SetMaterialColor(UStaticMeshComponent *Target,FName ColorName,FLinearColor InColor,int32 MatralIndex);
};

#if PLATFORM_WINDOWS
#pragma optimize("",on) 
#endif
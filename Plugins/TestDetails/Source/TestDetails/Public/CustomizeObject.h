// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "StructVariable.h"
#include "CustomizeObject.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)//蓝图可用
class TESTDETAILS_API UCustomizeObject : public UObject
{
	GENERATED_BODY()
public:
	UPROPERTY(EditAnywhere, Category = Hell)//被自定义覆盖
		FStructVariable Hle;

	UPROPERTY(EditAnywhere, Category = Hell)
		float Hello;

	UPROPERTY(EditAnywhere, Category = Hell)
		FText HelloA;

	UPROPERTY(EditAnywhere, Category = Hell)
		TArray<int32> HelloAArray;

	UPROPERTY(EditAnywhere, Category = Hell)
		int32 HelloI;

	UPROPERTY(EditAnywhere, Category = Hell)
		float HelloF;
};

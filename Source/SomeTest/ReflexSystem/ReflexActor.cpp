// Fill out your copyright notice in the Description page of Project Settings.


#include "ReflexActor.h"

// Sets default values
AReflexActor::AReflexActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AReflexActor::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AReflexActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AReflexActor::TestFunc5_Implementation(int32 IntValue)
{

}


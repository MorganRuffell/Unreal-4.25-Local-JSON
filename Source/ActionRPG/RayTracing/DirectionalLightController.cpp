// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "DirectionalLightController.h"

// Sets default values
ADirectionalLightController::ADirectionalLightController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ADirectionalLightController::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void ADirectionalLightController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


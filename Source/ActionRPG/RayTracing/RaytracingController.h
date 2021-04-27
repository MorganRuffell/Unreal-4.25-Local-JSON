// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "RaytracingController.generated.h"

UCLASS()
class ACTIONRPG_API ARaytracingController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARaytracingController();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

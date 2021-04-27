// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataAssets/Effects/RaytracingDataAsset.h"
#include "RaytracingController.generated.h"

UCLASS(Blueprintable)
class ACTIONRPG_API ARaytracingController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARaytracingController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RaytracingData")
	URaytracingDataAsset* RaytracingData;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Engine/PostProcessVolume.h"
#include "Components/PostProcessComponent.h"
#include "DataAssets/JSON/Interfaces/JSONValuesForAActor.h"
#include "DataAssets/Effects/RaytracingDataAsset.h"
#include "RaytracingController.generated.h"

UCLASS(Blueprintable)
class ACTIONRPG_API ARaytracingController : public AActor , public IJSONValuesForAActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ARaytracingController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RaytracingData")
	URaytracingDataAsset* RaytracingData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RaytracingSystem")
	UPostProcessComponent* RaytracingSystem;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;
	
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

public:

	bool GetJSONDataAssetData() override;

	//bool GetJSONDataAssetData(UJSONDataAssetBase DataAsset) override;

};

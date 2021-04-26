// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/Effects/ExponentialHeightDataAsset.h"
#include "GameFramework/Actor.h"
#include "ARPGHeightFog.generated.h"

UCLASS()
class ACTIONRPG_API AARPGHeightFog : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARPGHeightFog();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "HeightFogData")
	UExponentialHeightDataAsset* HeightFogData;
};

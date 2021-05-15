// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "GameFramework/Actor.h"
#include "Engine/StreamableManager.h"
#include "DataAssets/SoulDataAsset.h"
#include "ARPGSoul.generated.h"

UCLASS()
class ACTIONRPG_API AARPGSoul : public AActor
{
	GENERATED_BODY()

public:
	AARPGSoul();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Assets")
	TSoftObjectPtr<USoulDataAsset> SoulSoftDataAsset;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

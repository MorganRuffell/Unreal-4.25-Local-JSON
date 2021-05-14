// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "DataAssets/NPCSpawnBoxDataAsset.h"
#include "ARPGSpawnBox.generated.h"

UCLASS()
class ACTIONRPG_API AARPGSpawnBox : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AARPGSpawnBox();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Assets")
	TArray<TSoftObjectPtr<UNPCSpawnBoxDataAsset>> SoftSpawnBoxDataArray;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

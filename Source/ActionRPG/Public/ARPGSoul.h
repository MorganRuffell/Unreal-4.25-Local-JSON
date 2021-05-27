// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Math/UnrealMathUtility.h"
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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ActorPosition")
	FVector InitalActorLocation;
	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Assets")
	TSoftObjectPtr<USoulDataAsset> SoulSoftDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collider")
	class USphereComponent* SoulCollider;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collider")
	bool CanSimulatePhysics = false;
	

	float Min = 0.0f;
	float Max = 0.0f;
	float Final = 0.0f;



protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION()
	void PostDelay();

	void ResolveSoftObject();


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

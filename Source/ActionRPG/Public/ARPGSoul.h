// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "UObject/SoftObjectPtr.h"
#include "Curves/CurveFloat.h"
#include "Kismet/KismetMathLibrary.h"
#include "Kismet/GameplayStatics.h"
#include "Components\TimelineComponent.h"
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
	
	UPROPERTY()
	FVector Container;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Assets")
	TSoftObjectPtr<USoulDataAsset> SoulSoftDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collider")
	USphereComponent* SoulShape;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collider")
	UParticleSystemComponent* SummonParticleSystem;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Collider")
	bool CanSimulatePhysics = false;
	

	float Min = 0.0f;
	float Max = 0.0f;
	float Final = 0.0f;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "")
	UTimelineComponent* Timeline;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "")
	UCurveFloat* fSoulCurve;

	FOnTimelineFloat InterpFunction{};
	FOnTimelineEvent TimelineFinished{};


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timeline")
	float RotateValue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timeline")
	float CurveFloatValue;


protected:

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:

	UFUNCTION()
	void PostDelay();

	UFUNCTION(BlueprintCallable)
	void ResolveSoftObject();


	UFUNCTION()
	void TimelineFloatReturn(float value);
	
	void OnTimelineFinished();

	void FinishCollectItem();


	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

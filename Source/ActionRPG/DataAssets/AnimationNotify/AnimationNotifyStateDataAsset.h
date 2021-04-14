// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "Particles/ParticleSystem.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "AnimationNotifyStateDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCameraShakeData 
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera Shake Data")
	float InnerRadius = 0.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera Shake Data")
	float OuterRadius = 1000.0f;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera Shake Data")
	float Falloff = 1.0f;

};

USTRUCT(BlueprintType)
struct FAttackDelay
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackDelayTime = 0.04f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int32 MaxAttackDelayCount = 2.0f;
};

UCLASS(BlueprintType)
class ACTIONRPG_API UAnimationNotifyStateDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:
	
	UAnimationNotifyStateDataAsset();
	~UAnimationNotifyStateDataAsset();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Effect Color")
	FLinearColor EffectColor;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Attack Delay Timings")
	FAttackDelay attackDelays;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera Shake Data")
	FCameraShakeData AnimNotifyCameraData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement Notifies")
	float MoveValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement Notifies")
	float MoveForwardValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement Notifies")
	float MotionSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Particle Systems")
	UParticleSystem* GoblinFireParticleSystem;

};

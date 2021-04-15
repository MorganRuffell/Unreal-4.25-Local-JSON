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

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera Shake Data")
	bool OrientShakeToEpicentre = false;

};

USTRUCT(BlueprintType)
struct FAttackDelay
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackDelayTime = 0.04f;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxAttackDelayCount = 2.0f;
};

USTRUCT(BlueprintType)
struct FANMoveForward
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanSweep = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool CanTeleport = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MoveForwardValue = 40.f;

};

USTRUCT(BlueprintType)
struct FSlowMotion
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float MotionSpeed = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float TimeDilation = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float EndSpeed = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	bool bForceSlowMotion = false;

};

USTRUCT(BlueprintType)
struct FWeaponAttackNotifyData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float AttackDelay = 0.04;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	int MaxAttackDelayCount = 2;
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
	FAttackDelay AttackDelays;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Camera Shake Data")
	FCameraShakeData AnimNotifyCameraData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "MoveForwardData")
	FANMoveForward MoveForwardData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "SlowMotionData")
	FSlowMotion SlowMotionData;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "WeaponAttackNSData")
	FWeaponAttackNotifyData WeaponAttackNSData;

public:


	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement Notifies")
	float MoveValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Movement Notifies")
	float MoveForwardValue;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Particle Systems")
	UParticleSystem* GoblinFireParticleSystem;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

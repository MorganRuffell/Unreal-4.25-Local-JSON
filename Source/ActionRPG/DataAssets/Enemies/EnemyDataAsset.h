// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//We are no longer building this on a UDatAsset now they are on a JSON data asset
#include "DataAssets/JSONDataAssetBase.h"

#include "Particles/ParticleSystem.h"
#include "Sound/SoundBase.h"
#include "EnemyDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLevel3EnemyComponents
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Components")
	UParticleSystem* NPCGoblinFireParticleSystem;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Enemy Components")
	USoundBase* FireballAbilitySound;

};

UCLASS(BlueprintType)
class ACTIONRPG_API UEnemyDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	//Public constructor and destructor
	UEnemyDataAsset();
	~UEnemyDataAsset();

	
	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Reward")
	float _TimeBonusPerKill;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Reward")
	int32 _MinSoulsDropped;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Reward")
	int32 _MaxSoulsDropped;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "Level 3 Attributes")
	FLevel3EnemyComponents Level3Attributes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* FalldownAnimationMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* HitAnimationMontage;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;
	
	virtual bool FromJson(FJsonObject& jsonObject) override;

	//Unreal Shared Pointers and references

	//TSharedRef<UEnemyDataAsset> SharedRef;
	//TSharedPtr<UEnemyDataAsset> SharedPtr;

};

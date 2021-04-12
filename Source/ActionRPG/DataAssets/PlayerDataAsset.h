// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Components/Visual.h"
#include "Blueprint/UserWidget.h"
#include "DataAssets/JSONDataAssetBase.h"
#include "PlayerDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerControllerAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Camera Attributes")
	float CameraZOffsetMultiplier = -1.0f;

};

UENUM(BlueprintType)
enum class ERPGSlots : uint8
{
	Potion,
	Skill,
	Token,
	Weapon,
	Undefined
};

UCLASS(BlueprintType)
class ACTIONRPG_API UPlayerDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UPlayerDataAsset();
	~UPlayerDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackDelay")
	int32 AttackDelayCount;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackDelay")
	float AttackDelayTime;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attack")
	bool bCanUseAnyAttack;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RPG Slots")
	ERPGSlots _RPGSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Controller Attributes")
	FPlayerControllerAttributes PlayerControllerAttr;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Montages" )
	UAnimMontage* RollingMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation Montages")
	UAnimMontage* ReactToHitMontage;


public:
	//Section purely for the JSON Stuff.	

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

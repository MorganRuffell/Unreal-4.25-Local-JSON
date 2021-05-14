// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/Widget.h"
#include "Components/Visual.h"
#include "Blueprint/UserWidget.h"
#include "ActionRPG/Public/RPGCharacterBase.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "Templates/SharedPointer.h"
#include "PlayerDataAsset.generated.h"

class ARPGCharacterBase;

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPlayerDamageColor
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Color")
	float Red;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Color")
	float Green;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Color")
	float Blue;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Damage Color")
	float Alpha;
};

USTRUCT(BlueprintType)
struct FPlayerDataAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data Attributes")
	float PlayerMaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data Attributes")
	float PlayerMaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data Attributes")
	float PlayerMovementSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data Attributes")
	int PlayerBaseLevel;
};

USTRUCT(BlueprintType)
struct FPlayerControllerAttributes
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Camera Attributes")
	float CameraZOffsetMultiplier = -1.0f;

};

USTRUCT(BlueprintType)
struct FAttackDelayData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackDelay")
	float AttackDelayTime_Upper;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackDelay")
	float AttackDelayTime_Lower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackDelay")
	int32 AttackDelayCount;
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

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController")
	bool CanUseInventory = true;

	//Serialize these

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController")
	bool CanUseHUD = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController")
	bool ForcePCUI = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController")
	bool ForceMobileUI = false;

	//

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PlayerController")
	bool CanUseTeleportPhysics = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, CateGory = "PlayerController")
	float CloseInventoryDelay = 0.75f;



public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackDelay")
	FAttackDelayData AttackDelayData;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attack")
	bool bCanUseAnyAttack;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "RemoteActivation")
	bool CanRemoteActivate;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RPG Slots")
	ERPGSlots _RPGSlot;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RPG Slots")
	FRPGItemSlot ItemSlot;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Controller Attributes")
	FPlayerControllerAttributes PlayerControllerAttr;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data Attributes")
	FPlayerDataAttributes PlayerData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data Attributes")
	FPlayerDamageColor PlayerDamageColor_RGB;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data Attributes")
	FLinearColor DamageColor;

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

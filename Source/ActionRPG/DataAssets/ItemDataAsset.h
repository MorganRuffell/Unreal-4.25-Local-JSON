// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectConverter.h"
#include "DataAssets/JSONDataAssetBase.h"
#include "Sound/SoundBase.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundConcurrency.h"
#include "ItemDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FPickupSoundValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Attributes")
	float VolumeMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Attributes")
	float PitchMultiplier = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound Attributes")
	float SoundStartTime = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound & Sound Settings")
	USoundBase* PickupSound;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound & Sound Settings")
	USoundAttenuation* SoundAttenuationSettings;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sound & Sound Settings")
	USoundConcurrency* SoundConcurrencySettings;

};

UENUM(BlueprintType)
enum class EPotionType : uint8
{
	_Health,
	_Mana,
	_DeathsDoor
};

UCLASS(Blueprintable)
class ACTIONRPG_API UItemDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UItemDataAsset();
	~UItemDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float _RotationSpeed;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Interaction Attributes")
	float _InteractionRadius;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FText _ItemTextName;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FText _ManaString;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	EPotionType _PotionType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sounds & Sound Settings")
	FPickupSoundValues _SoundAttributes;

public:

	//If you override a virtual function, always use a the override keyword
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;


};

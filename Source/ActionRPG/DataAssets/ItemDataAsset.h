// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "JsonObjectConverter.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "Engine/StaticMesh.h"
#include "Math/Color.h"
#include "Sound/SoundBase.h"
#include "Sound/SoundAttenuation.h"
#include "Sound/SoundConcurrency.h"

#include "Dom/JsonObject.h"

#include "ItemDataAsset.generated.h"


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

USTRUCT(BlueprintType)
struct FRotationSpeeds 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationSpeeds")
	float Slow = 0.01f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationSpeeds")
	float Medium = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RotationSpeeds")
	float Fast = 1.0f;

};

UENUM(BlueprintType)
enum class EPotionType : uint8
{
	_Health,
	_Mana,
	_DeathsDoor
};

UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API UItemDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UItemDataAsset();
	~UItemDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	FRotationSpeeds RotationSpeeds;

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

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PotionStaticMeshes")
	TSet<UStaticMesh*> PotionStaticMeshes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PotionLinearColours")
	TSet<FLinearColor> PotionColors;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light Attributes")
	bool UseSRGB = true;


public:

	//If you override a virtual function, always use a the override keyword
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

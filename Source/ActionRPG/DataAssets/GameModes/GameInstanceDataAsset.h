// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Sound/SoundClass.h"
#include "Sound/SoundMix.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "GameInstanceDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FLoadingValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading Data")
	float PlayTime = 3.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Loading Data")
	bool PlayUntilStopped = true;

};

USTRUCT(BlueprintType)
struct FVolumeThresholds
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VolumeThresholds")
	float Small = 0.001f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VolumeThresholds")
	float Zero = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "VolumeThresholds")
	float Max = 1.0f;
};

USTRUCT(BlueprintType)
struct FSoundMixClassOverride 
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundClass")
	float Pitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundClass")
	TArray<USoundClass*> SoundClasses;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundClass")
	USoundMix* SoundMix;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundClass")
	bool ApplyToChildren = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundClass")
	int UserIndex = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundClass")
	FString SlotName = "GlobalOptions";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SoundClass")
	FVolumeThresholds VolumeLevels;

};

UCLASS(BlueprintType)
class ACTIONRPG_API UGameInstanceDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

	UGameInstanceDataAsset();

	~UGameInstanceDataAsset();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Loading Logic")
	FSoundMixClassOverride SoundData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Loading Logic")
	FLoadingValues LoadingData;

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Level Loading Logic")
	bool IsAbsolute;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

	
};

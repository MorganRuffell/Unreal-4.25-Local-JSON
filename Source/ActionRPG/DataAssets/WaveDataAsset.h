// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"
#include "DataAssets/JSON/JsonDataAssetBase.h"
#include "JsonObjectConverter.h"
#include "Classes/GameplayTagContainer.h"
#include "WaveDataAsset.generated.h"


/**
 *
 */
class ARPGCharacterBase;

USTRUCT(BlueprintType)
struct FSpawnGroup
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave Data")
	TArray<TSubclassOf<ARPGCharacterBase>> Enemies;

	TSharedRef<FJsonObject> ToJson();

	void FromJson(TSharedRef<FJsonObject> json);
};

USTRUCT(BlueprintType)
struct FWaveData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave Data")
	TArray<FSpawnGroup> EnemiesGroups;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave Data")
	float WaveTime;
	
	TSharedRef<FJsonObject> ToJson();

	void FromJson(TSharedRef<FJsonObject> json);
};

UCLASS(BlueprintType)
class ACTIONRPG_API UWaveDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()


public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Wave Data")
	TArray<FWaveData> WaveData;

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;
};

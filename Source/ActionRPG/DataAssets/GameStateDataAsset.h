// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "GameStateDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FUpdateFrequencies
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network Update Frequencies")
	float NetUpdateFrequency = 10.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network Update Frequencies")
	float MinNetUpdateFrequency = 2.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Network Update Frequencies")
	float NetPriority = 1.0f;
};

USTRUCT(BlueprintType)
struct FNetworkDataState
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State Network Attributes")
	float ServerWorldTimeUpdateFrequency = 0.1f; 

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State Network Attributes")
	bool OnlyRelevantToOwner = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State Network Attributes")
	bool NetLoadOnClient = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State Network Attributes")
	bool NetUseOwnerRelevancy = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State Network Attributes")
	bool Replicates = true;

};

UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API UGameStateDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UGameStateDataAsset();
	~UGameStateDataAsset();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State Network Attributes")
	FNetworkDataState NetworkDataStates;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game State Network Attributes")
	FUpdateFrequencies NetworkUpdateFrequencies;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

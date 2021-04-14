// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "SoulDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType, Blueprintable)
struct FDelayValues
{
	GENERATED_BODY()
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Delay")
	float DelayFloor = 0.5f;
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Delay")
	float DelayCeiling = 1.0f;
};

UCLASS(BlueprintType)
class ACTIONRPG_API USoulDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public: 

	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Delay")
	FDelayValues DelayValuesData;

public:
	
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;
};

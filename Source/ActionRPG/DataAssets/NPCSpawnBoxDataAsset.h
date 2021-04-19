// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "NPCSpawnBoxDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UNPCSpawnBoxDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UNPCSpawnBoxDataAsset();


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Extent")
	float x = 64.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Extent")
	float y = 64.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Box Extent")
	float z = 64.0f;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;
};

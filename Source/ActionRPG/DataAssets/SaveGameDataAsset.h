// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSONDataAssetBase.h"
#include "SaveGameDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API USaveGameDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:

	USaveGameDataAsset();
	~USaveGameDataAsset();

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

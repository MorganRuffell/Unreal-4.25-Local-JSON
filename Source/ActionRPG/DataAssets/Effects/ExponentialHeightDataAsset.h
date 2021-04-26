// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "ExponentialHeightDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API UExponentialHeightDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:
	UExponentialHeightDataAsset();
	~UExponentialHeightDataAsset();

	
public:


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

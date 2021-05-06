// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//Headers for JSON object.
#include "Dom/JsonObject.h"

//Headers for Interface, remember to IWYU
#include "DataAssets/JSON/Interfaces/JSONDataAssetInterface.h"

#include "Engine/DataAsset.h"
#include "JSONDataAssetBase.generated.h"

/**
 *
 */
UCLASS()
class ACTIONRPG_API UJSONDataAssetBase : public UDataAsset, public IJSONDataAssetInterface
{
	GENERATED_BODY()

public:

	UJSONDataAssetBase();
	~UJSONDataAssetBase();

	UPROPERTY(EditAnywhere, Category = JSON)
	FString JSONKey;

	virtual TSharedPtr<FJsonObject> ToJson() override { return nullptr; }

	virtual bool FromJson(FJsonObject& jsonObject) override { return true; }

};




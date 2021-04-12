// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSONDataAssetBase.h"
#include "DecoratorDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UDecoratorDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:
	
	UDecoratorDataAsset();
	~UDecoratorDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float MinHealthPercentage;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

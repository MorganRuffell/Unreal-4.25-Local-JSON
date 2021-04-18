// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "UICommandDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UUICommandDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

	UUICommandDataAsset();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Console Commands")
	FString StatisticRHI = "stat RHI";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Console Commands")
	FString StatisticsUnit = "stat Unit";


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

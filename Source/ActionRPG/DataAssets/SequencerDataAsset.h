// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "SequencerDataAsset.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FTimeControls
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeControls")
	float StartTime = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeControls")
	float Duration = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeControls")
	float PlayRate = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeControls")
	bool DisableCameraCuts = false;

};


UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API USequencerDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	USequencerDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeControls")
	TArray<FTimeControls> TimeContols;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "TimeControls")
	int TimeControlIndex = 0;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

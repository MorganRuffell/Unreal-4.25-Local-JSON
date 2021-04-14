// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "TaskDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UTaskDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UTaskDataAsset();
	~UTaskDataAsset();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Go Around Target")
	float RadiusRange;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Is Target Surrounded")
	float AcceptableDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Is Target Surrounded")
	int32 minSurrounders;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;


};

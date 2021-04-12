// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSONDataAssetBase.h"
#include "ServiceDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UServiceDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:
	
	UServiceDataAsset();
	~UServiceDataAsset();

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "ClosestDistance")
	float ClosestDistance;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RandomMoveSpeed")
	float MinSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RandomMoveSpeed")
	float MaxSpeed;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;
	

};

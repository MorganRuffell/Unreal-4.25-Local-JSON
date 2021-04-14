// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "ServiceDataAsset.generated.h"

/**
 * 
 */

USTRUCT(BlueprintType)
struct FRandomMoveSpeed
{
	GENERATED_BODY()

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RandomMoveSpeed")
	float MinSpeed;

	UPROPERTY(BlueprintReadWrite, EditAnywhere, Category = "RandomMoveSpeed")
	float MaxSpeed;
};

USTRUCT(BlueprintType)
struct FNearestTarget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FindNearestTarget")
	float ClosestDistance;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FindNearestTarget")
	FString TargetTag;

};


UCLASS(BlueprintType)
class ACTIONRPG_API UServiceDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:
	
	UServiceDataAsset();
	~UServiceDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FindNearestTarget")
	FNearestTarget NearestTargetService;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "RandomMoveSpeed")
	FRandomMoveSpeed RandomMoveSpeedService;


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;
	

};

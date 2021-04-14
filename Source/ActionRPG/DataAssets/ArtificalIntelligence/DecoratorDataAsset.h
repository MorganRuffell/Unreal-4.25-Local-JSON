// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "DecoratorDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FCheckHealth
{
	GENERATED_BODY()
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckHealth")
	float MinHealthPercentage;

};

USTRUCT(BlueprintType)
struct FCheckItem
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckItem")
	int ItemSlotNumber = 0;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckItem")
	FString ItemKey = "None";

};


UCLASS(BlueprintType)
class ACTIONRPG_API UDecoratorDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:
	
	UDecoratorDataAsset();
	~UDecoratorDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckHealth")
	FCheckHealth CheckHealthDecorator;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "CheckHealth")
	FCheckItem CheckItemDecorator;


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

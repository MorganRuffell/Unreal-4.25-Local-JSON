// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "EnemyAnimationBlueprintDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UEnemyAnimationBlueprintDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:

	UEnemyAnimationBlueprintDataAsset();

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "EnemyAnimationMax")
	int AnimationIndexDiceRoll = 3;

public:
	
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;
	
};

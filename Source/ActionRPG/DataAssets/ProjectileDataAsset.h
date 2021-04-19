// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "ProjectileDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API UProjectileDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	

public:

	UProjectileDataAsset();
	~UProjectileDataAsset();

public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AttackDamage")
	float AttackDamage = 300.0f;


public:
	
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

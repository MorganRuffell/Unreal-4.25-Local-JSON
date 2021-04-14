// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "EnemyGlobalData.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSpawnVectorComponents
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bounding Box Values")
	float X = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bounding Box Values")
	float Y = 40.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Bounding Box Values")
	float Z = 40.0f;
};

USTRUCT(BlueprintType)
struct FSoulValues
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul Values")
	int SoulMin;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul Values")
	int SoulMax;

};

UCLASS(BlueprintType, Blueprintable)
class ACTIONRPG_API UEnemyGlobalData : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Soul Values")
	FSoulValues SoulAmounts_External;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "SpawnBoundingBox")
	FSpawnVectorComponents SpawnVectorValues;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Potion Drop Amounts")
	float PotionDropAmounts_External;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Time Bonus")
	float TimeBonusPerKill_External;
	
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category = "Time Bonus")
	FVector BoxExtent;

public:
	
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Materials/Material.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "ParticleSystemDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API UParticleSystemDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timing")
	float TimeDilation = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timing")
	float SecondsBeforeInactive = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Timing")
	bool AbsoluteScale = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recycling")
	bool AllowRecycling = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Recycling")
	bool ReturnMaterialOnMove = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Material1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Material2;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Material3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Materials")
	UMaterialInstance* Material4;


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;
	
};

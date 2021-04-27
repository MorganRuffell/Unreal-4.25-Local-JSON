// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "ExponentialHeightDataAsset.generated.h"

/**
 * 
 */

USTRUCT(Blueprintable)
struct FInscatteringColorData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InscatteringColorData")
	float Red = 0.792f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InscatteringColorData")
	float Blue = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InscatteringColorData")
	float Green = 0.66f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "InscatteringColorData")
	float Alpha = 1.0f;

};


UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API UExponentialHeightDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:
	UExponentialHeightDataAsset();
	~UExponentialHeightDataAsset();

	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Density & Scattering")
	float FogDensity = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Density & Scattering")
	float MaxOpacity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Density & Scattering")
	float InscatteringExponent = 4.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Density & Scattering")
	float StartDistance = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Density & Scattering")
	FInscatteringColorData ScatteringColorData;

	
public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

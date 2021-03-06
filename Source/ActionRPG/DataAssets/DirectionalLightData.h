// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Math/Color.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "DirectionalLightData.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ACTIONRPG_API UDirectionalLightData : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UDirectionalLightData();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emission Intensity")
	float Intensity = 0.1f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emission Intensity")
	float IndirectLightingIntensity = 1.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emission Intensity")
	float VolumetricScatteringIntensity = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emission Intensity")
	bool UseTemp = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Emission Intensity")
	bool CanCastShadows = true;

public:

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Light Color")
	FLinearColor DirectionalColor;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light Color")
	float Red = 255;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light Color")
	float Green = 255;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light Color")
	float Blue = 255;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing")
	bool RTRT_AffectGI = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing")
	bool RTRT_CastRaytracedShadow = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing")
	bool RTRT_AffectTransluenctLighting = true;




public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

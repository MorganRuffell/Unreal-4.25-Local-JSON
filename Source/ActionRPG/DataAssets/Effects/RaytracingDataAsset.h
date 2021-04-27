// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "RaytracingDataAsset.generated.h"

/**
 * 
 */
UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API URaytracingDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	URaytracingDataAsset();
	~URaytracingDataAsset();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Ambient Occclusion")
	bool IsPostProcessEnabled = true;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Ambient Occclusion")
	bool IsEnabled = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Reflections")
	bool IncludeTranslucents = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Reflections")
	bool CanUseRefractions = true;


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Ambient Occclusion")
	float Intensity = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Ambient Occlusion")
	float Radius = 200.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing")
	float MaxRoughness = 0.6f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing")
	float RIntensity = 0.5f;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Global Illumination")
	int SamplesPerPixelGI = 4;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Ambient Occlusion")
	int SamplesPerPixelAO = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Global Illumination")
	int MaxBounces = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing")
	int SamplesPerPixel = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing")
	int MaxBouncesGI = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Reflections")
	int SamplesPerPixelREF = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing")
	int MaxRefractionRays = 3;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Path Tracing")
	int Path_MaxBounces = 32;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Raytracing - Path Tracing")
	int Special_MaxBounces = 16384;


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

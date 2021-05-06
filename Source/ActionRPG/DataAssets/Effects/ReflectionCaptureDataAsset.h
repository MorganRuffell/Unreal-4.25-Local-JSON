// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "ReflectionCaptureDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType, Blueprintable)
class ACTIONRPG_API UReflectionCaptureDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:
	UReflectionCaptureDataAsset();
	~UReflectionCaptureDataAsset();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Capture Component")
	float InfluenceRadius = 1000.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Capture Component")
	float Brightness = 1.0f;


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;
	virtual bool FromJson(FJsonObject& jsonObject) override;

};

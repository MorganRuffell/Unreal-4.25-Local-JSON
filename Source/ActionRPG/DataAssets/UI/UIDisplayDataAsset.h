// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "UIDisplayDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FBaseSlateColor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Color")
	float Red = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Color")
	float Green = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Color")
	float Blue = 1.0f;

};


USTRUCT(BlueprintType)
struct FWarningColor
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Color")
	float Red = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Color")
	float Green = 0.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Color")
	float Blue = 0.0f;

};

USTRUCT(BlueprintType)
struct FPCHUD
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD")
	int UIDelay= 10.0f ;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Animation")
	float PlaybackSpeed = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Animation")
	bool RestoreState = false;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Animation")
	int NumberofLoopsToPlay = 1;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Color")
	FBaseSlateColor BaseColorComponents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD - Color")
	FWarningColor WarningColorComponents;

};

UCLASS(BlueprintType)
class ACTIONRPG_API UUIDisplayDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "PC HUD")
	FPCHUD PCHUDDisplayData;

public:

	UUIDisplayDataAsset();

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

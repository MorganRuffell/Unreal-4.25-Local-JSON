// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "JsonManagerDataAsset.generated.h"

/**
 * 
 */

struct FFileTypes;

UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API UJsonManagerDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileName")
	FString JSONFileName = "DataAssetsJsonData";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileName")
	FString CurveJSONFileName = "DataAssetsCurveJsonData";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileTypes")
	bool AllowOverwriting = true;

public:

	UJsonManagerDataAsset();
	~UJsonManagerDataAsset();


public:
	
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};



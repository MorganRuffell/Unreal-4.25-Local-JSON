// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "MainMenuData.generated.h"

/**
 * 
 */

//This is designed to be used in conjunction with a GameMode Data Asset

UCLASS(BlueprintType)
class ACTIONRPG_API UMainMenuData : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "ZOrder")
	int ZOrder = 0;


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

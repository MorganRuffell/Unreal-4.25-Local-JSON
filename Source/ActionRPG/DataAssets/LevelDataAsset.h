// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSONDataAssetBase.h"
#include "Sound/SoundBase.h"
#include "Engine/World.h"
#include "LevelDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API ULevelDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	ULevelDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelToLoad")
	TSet<FString> LevelToLoad;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "LevelToLoad")
	int LevelToLoadIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Sounds")
	USoundBase* AmbientMusic;


public:

	//If you override a virtual function, always use a the override keyword
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;


};

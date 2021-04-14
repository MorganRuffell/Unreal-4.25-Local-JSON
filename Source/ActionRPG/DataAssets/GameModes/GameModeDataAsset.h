// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Runtime/UMG/Public/UMG.h"
#include "Blueprint/UserWidget.h"
#include "GameFramework/HUD.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "GameModeDataAsset.generated.h"

/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UGameModeDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	//UGameModeDataAsset(FObjectInitializer& ObjectIntializer);

	UGameModeDataAsset();
	~UGameModeDataAsset();
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float EnemySpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	bool AutoBattleMode;	

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float WaveSpawnDelay;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float GlobalTimeDilation;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float BattleTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float PlayTimerStartTime;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game")
	FString PlayerName;

public:

	//If you override a virtual function, always use a the override keyword
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;


};

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"
#include "Engine/DataAsset.h"
#include "DataAssets/GameModes/MainMenuData.h"
#include "DataAssets/WaveDataAsset.h"
#include "DataAssets/GameModes/GameModeDataAsset.h"
#include "Containers/UnrealString.h"
#include "Containers/Set.h"
#include "Components/WidgetComponent.h"
#include "Math/UnrealMathUtility.h"
#include "DataAssets/JSON/JsonManagerDataAsset.h"
#include "GameFramework/GameModeBase.h"
#include "RPGGameModeBase.generated.h"

/** Base class for GameMode, should be blueprinted */
UCLASS(BlueprintType)
class ACTIONRPG_API ARPGGameModeBase : public AGameModeBase
{
	GENERATED_BODY()

public: 

	ARPGGameModeBase();

	UFUNCTION(BlueprintPure)
	void SelectWaveTablefromSet(TSet<UDataTable*> WaveTableSet, int CurrentWave, TArray<UDataTable*>& SelectedWaveTable, FName& RowName);

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "")
	TSet<TSoftObjectPtr<UWaveDataAsset>> SoftWaveDifficultyData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "")
	TSoftClassPtr<UUserWidget> WaveEndClass;


public:
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Game Mode External Data")
	UGameModeDataAsset* GameModeData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Mode External Data")
	UJsonManagerDataAsset* JSONManagerData;

};


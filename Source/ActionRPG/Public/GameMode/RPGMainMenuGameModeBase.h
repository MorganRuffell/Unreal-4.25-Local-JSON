// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/GameModes/MainMenuData.h"
#include "GameFramework/GameModeBase.h"
#include "DataAssets/GameModes/GameModeDataAsset.h"
#include "RPGMainMenuGameModeBase.generated.h"


/**
 * 
 */
UCLASS(BlueprintType)
class ACTIONRPG_API ARPGMainMenuGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
	
public:
	
	ARPGMainMenuGameModeBase();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Mode External Data")
	UMainMenuData* MainMenuDataAsset;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Mode Data Asset")
	UGameModeDataAsset* GameModeData;


};

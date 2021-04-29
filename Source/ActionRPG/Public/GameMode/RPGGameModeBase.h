// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"
#include "Engine/DataAsset.h"
#include "DataAssets/GameModes/MainMenuData.h"
#include "DataAssets/GameModes/GameModeDataAsset.h"
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

public:
	
	UPROPERTY(EditInstanceOnly, BlueprintReadWrite, Category = "Game Mode External Data")
	UGameModeDataAsset* GameModeData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Mode External Data")
	UJsonManagerDataAsset* JSONManagerData;

};


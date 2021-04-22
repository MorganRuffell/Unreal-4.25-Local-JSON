// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"
#include "GameFramework/GameStateBase.h"
#include "SaveGame/ActionRPGSaveGame.h"
#include "DataAssets/GameStateDataAsset.h"
#include "RPGGameStateBase.generated.h"

/** Base class for GameState, should be blueprinted */
UCLASS()
class ACTIONRPG_API ARPGGameStateBase : public AGameStateBase
{
	GENERATED_BODY()

public:
	

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Data Assets")
	UGameStateDataAsset* GameStateData;	


	/** Constructor */
	ARPGGameStateBase();


};


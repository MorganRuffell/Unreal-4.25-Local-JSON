// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "RPGMainMenuGameModeBase.h"
#include "RPGGameStateBase.h"
#include "RPGPlayerControllerBase.h"

ARPGMainMenuGameModeBase::ARPGMainMenuGameModeBase()
{
	GameStateClass = ARPGGameStateBase::StaticClass();
	PlayerControllerClass = ARPGPlayerControllerBase::StaticClass();
}
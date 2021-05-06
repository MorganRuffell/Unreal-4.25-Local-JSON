// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RPGGameModeBase.h"
#include "RPGGameStateBase.h"
#include "RPGPlayerControllerBase.h"

ARPGGameModeBase::ARPGGameModeBase()
{
	GameStateClass = ARPGGameStateBase::StaticClass();
	PlayerControllerClass = ARPGPlayerControllerBase::StaticClass();
}

void ARPGGameModeBase::SelectWaveTablefromSet(TSet<UDataTable*> WaveTableSet, int CurrentWave, TArray<UDataTable*>& SelectedWaveTable, FName& RowName)
{
	TArray<UDataTable*> DataTables = WaveTableSet.Array();
	FString WaveIntro = "Wave_";
	FString WaveIndex;

	RowName = FName(*WaveIntro);
	RowName = FName(WaveIndex.FromInt(CurrentWave));
}

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

void ARPGGameModeBase::GetWaveFromObject(UJsonManagerDataAsset* JSONManagerData, FWaveData& DaWayve)
{
	FStreamableManager StreamableManager;

	FSoftObjectPath WaveDataAssetAtIndex = SoftWaveDifficultyData[0].ToSoftObjectPath();

	TSharedPtr<FStreamableHandle> WaveDataStreamHandle;
	WaveDataStreamHandle = StreamableManager.RequestAsyncLoad(WaveDataAssetAtIndex);

	if (!WaveDataStreamHandle.IsValid()) { return; }

	if (WaveDataStreamHandle->HasLoadCompleted())
	{
		UWaveDataAsset* DataAssetContainer = NewObject<UWaveDataAsset>(this);

		UObject* WaveDataAssetResolved = WaveDataStreamHandle->GetLoadedAsset();
		WaveDataAssetResolved = Cast<UWaveDataAsset, UObject>(DataAssetContainer);
		//WaveDataAssetResolved = dynamic_cast<UWaveDataAsset*>(DataAssetContainer);

		for (int i = 0; i < SoftWaveDifficultyData.Num(); i++)
		{
			DaWayve = DataAssetContainer->WaveData[i];
		}

	}
}


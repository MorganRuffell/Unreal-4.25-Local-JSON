// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "GameModeDataAsset.h"

UGameModeDataAsset::UGameModeDataAsset()
{
	EnemySpawnDelay = 3.0f;
	AutoBattleMode = false;
	WaveSpawnDelay = 4.0f;
	GlobalTimeDilation = 0.25;

}

UGameModeDataAsset::~UGameModeDataAsset()
{

}


TSharedPtr<FJsonObject> UGameModeDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	
	jsonObject->SetBoolField("AutoBattleMode", AutoBattleMode);
	jsonObject->SetBoolField("UseJSONDifficultySystemExperimentalMode", UseJSONDifficultySystemExperimentalMode);

	jsonObject->SetNumberField("EnemySpawnDelay", EnemySpawnDelay);
	jsonObject->SetNumberField("WaveSpawnDelay", WaveSpawnDelay);
	jsonObject->SetNumberField("GlobalTimeDilation", GlobalTimeDilation);
	jsonObject->SetNumberField("BattleTime", BattleTime);
	jsonObject->SetNumberField("PlayTimerStartTime", PlayTimerStartTime);
	jsonObject->SetStringField("DefaultPlayerName", PlayerName);


	return jsonObject;
}

bool UGameModeDataAsset::FromJson(FJsonObject& jsonObject)
{
	// You can use try get fields to limit data issues

	AutoBattleMode = jsonObject.GetBoolField("AutoBattleMode");
	UseJSONDifficultySystemExperimentalMode = jsonObject.GetBoolField("UseJSONDifficultySystemExperimentalMode");

	EnemySpawnDelay = jsonObject.GetNumberField("EnemySpawnDelay");
	WaveSpawnDelay = jsonObject.GetNumberField("WaveSpawnDelay");
	GlobalTimeDilation = jsonObject.GetNumberField("GlobalTimeDilation");
	BattleTime = jsonObject.GetNumberField("BattleTime");
	PlayTimerStartTime = jsonObject.GetNumberField("PlayerTimerStartTime");
	PlayerName = jsonObject.GetStringField("DefaultPlayerName");


	return (true);
}

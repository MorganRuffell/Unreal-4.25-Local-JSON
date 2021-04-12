// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "EnemyDataAsset.h"

UEnemyDataAsset::UEnemyDataAsset()
{
	float _TimeBonusPerKill = 5.0f;
	int32 _MinSoulsDropped = 1;
	int32 _MaxSoulsDropped = 1;

	//Add in a field for potion drop chance.
}

UEnemyDataAsset::~UEnemyDataAsset()
{

}

TSharedPtr<FJsonObject> UEnemyDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("time_bonus_per_kill", _TimeBonusPerKill);
	jsonObject->SetNumberField("MinSoulsDropped", _MinSoulsDropped);
	jsonObject->SetNumberField("MaxSoulsDroppped", _MaxSoulsDropped);

	return jsonObject;
}

bool UEnemyDataAsset::FromJson(FJsonObject& jsonObject)
{

	_TimeBonusPerKill = jsonObject.GetNumberField("time_bonus_per_kill");
	_MinSoulsDropped = jsonObject.GetNumberField("MinSoulsDropped");
	_MaxSoulsDropped = jsonObject.GetNumberField("MaxSoulsDroppped");

	return(true);
	
}
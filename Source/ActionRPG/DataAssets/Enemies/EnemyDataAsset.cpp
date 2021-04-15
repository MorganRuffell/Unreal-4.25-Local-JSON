// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "EnemyDataAsset.h"

UEnemyDataAsset::UEnemyDataAsset()
{
	float _TimeBonusPerKill = 5.0f;
	int _MinSoulsDropped = 1;
	int _MaxSoulsDropped = 5;

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

	jsonObject->SetNumberField("EnemyJumpZVelocity", EnemyMovementData.EnemyJumpZVelocity);
	jsonObject->SetNumberField("EnemyMass", EnemyMovementData.EnemyMass);
	jsonObject->SetNumberField("EnemyMaxWalkSpeed", EnemyMovementData.EnemyMaxWalkSpeed);
	jsonObject->SetNumberField("EnemyGravityScale", EnemyMovementData.GravityScale);
	jsonObject->SetNumberField("EnemyMaxAcceleration", EnemyMovementData.MaxAcceleration);

	return jsonObject;
}

bool UEnemyDataAsset::FromJson(FJsonObject& jsonObject)
{

	_TimeBonusPerKill = jsonObject.GetNumberField("time_bonus_per_kill");
	_MinSoulsDropped = jsonObject.GetNumberField("MinSoulsDropped");
	_MaxSoulsDropped = jsonObject.GetNumberField("MaxSoulsDroppped");

	EnemyMovementData.EnemyJumpZVelocity = jsonObject.GetNumberField("EnemyJumpZVelocity");
	EnemyMovementData.EnemyMass = jsonObject.GetNumberField("EnemyMass");
	EnemyMovementData.EnemyMaxWalkSpeed = jsonObject.GetNumberField("EnemyMaxWalkSpeed");
	EnemyMovementData.GravityScale = jsonObject.GetNumberField("EnemyGravityScale");
	EnemyMovementData.MaxAcceleration = jsonObject.GetNumberField("EnemyMaxAcceleration");

	return(true);	
}
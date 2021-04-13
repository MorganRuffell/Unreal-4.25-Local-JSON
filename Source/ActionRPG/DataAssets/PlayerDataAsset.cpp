// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PlayerDataAsset.h"

UPlayerDataAsset::UPlayerDataAsset()
{

}

UPlayerDataAsset::~UPlayerDataAsset()
{
}

TSharedPtr<FJsonObject> UPlayerDataAsset::ToJson()
{
	//We may have a solution to the player problem
	//PlayerMaxHealth = ARPGCharacterBase.AttributeSet->MaxHealth;

	FetchCharacterDataFromStruct();

	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();
		
	jsonObject->SetNumberField("Attack_DelayCount", AttackDelayCount);
	jsonObject->SetNumberField("Attack_DelayTime", AttackDelayTime);
	jsonObject->SetBoolField("CanUseAnyAttack", bCanUseAnyAttack);
	jsonObject->SetNumberField("CameraZOffset", PlayerControllerAttr.CameraZOffsetMultiplier);

	return jsonObject;
}

void UPlayerDataAsset::FetchCharacterDataFromStruct()
{
	PlayerData.PlayerMaxHealth = ChracterData.GetMaxHealth();
	PlayerData.PlayerBaseLevel = ChracterData.GetCharacterLevel();
	PlayerData.PlayerMaxMana = ChracterData.GetMaxMana();
}

bool UPlayerDataAsset::FromJson(FJsonObject& jsonObject)
{
	AttackDelayCount = jsonObject.GetNumberField("Attack_DelayCount");
	AttackDelayCount = jsonObject.GetNumberField("Attack_DelayTime");
	AttackDelayCount = jsonObject.GetBoolField("CanUseAnyAttack");
	PlayerControllerAttr.CameraZOffsetMultiplier = jsonObject.GetNumberField("CameraZOffset");

	return true;
}

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
	//We can do this in blueprints though, so we just pass the values anyway as long as the BP logic exists.

	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();
		
	jsonObject->SetNumberField("Attack_DelayCount", AttackDelayCount);
	jsonObject->SetNumberField("Attack_DelayTime", AttackDelayTime);
	jsonObject->SetBoolField("CanUseAnyAttack", bCanUseAnyAttack);
	jsonObject->SetNumberField("CameraZOffset", PlayerControllerAttr.CameraZOffsetMultiplier);

	jsonObject->SetNumberField("PlayerMaxHealth", PlayerData.PlayerMaxHealth);
	jsonObject->SetNumberField("PlayerMaxMana", PlayerData.PlayerMaxMana);
	jsonObject->SetNumberField("PlayerMaxMovementSpeed", PlayerData.PlayerMovementSpeed);
	jsonObject->SetNumberField("PlayerBaseLevel", PlayerData.PlayerBaseLevel);

	return jsonObject;
}

bool UPlayerDataAsset::FromJson(FJsonObject& jsonObject)
{
	AttackDelayCount = jsonObject.GetNumberField("Attack_DelayCount");
	AttackDelayTime = jsonObject.GetNumberField("Attack_DelayTime");
	bCanUseAnyAttack = jsonObject.GetBoolField("CanUseAnyAttack");
	PlayerControllerAttr.CameraZOffsetMultiplier = jsonObject.GetNumberField("CameraZOffset");
	
	PlayerData.PlayerMaxHealth = jsonObject.GetNumberField("PlayerMaxHealth");
	PlayerData.PlayerMaxMana = jsonObject.GetNumberField("PlayerMaxMana");
	PlayerData.PlayerMovementSpeed = jsonObject.GetNumberField("PlayerMaxMovementSpeed");
	PlayerData.PlayerBaseLevel = jsonObject.GetNumberField("PlayerBaseLevel");

	

	return true;
}

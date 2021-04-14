// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "PlayerDataAsset.h"

UPlayerDataAsset::UPlayerDataAsset()
{
	CanRemoteActivate = true;
	bCanUseAnyAttack = true;
}

UPlayerDataAsset::~UPlayerDataAsset()
{
}

TSharedPtr<FJsonObject> UPlayerDataAsset::ToJson()
{
	//Back to square one with the player saving problem. We cannot do this in blueprints.

	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	if (jsonObject.IsUnique())
	{
		jsonObject->SetNumberField("Attack_DelayCount", AttackDelayCount);
		jsonObject->SetNumberField("Attack_DelayTime", AttackDelayTime);
		jsonObject->SetNumberField("CameraZOffset", PlayerControllerAttr.CameraZOffsetMultiplier);

		jsonObject->SetNumberField("PlayerMaxHealth", PlayerData.PlayerMaxHealth);
		jsonObject->SetNumberField("PlayerMaxMana", PlayerData.PlayerMaxMana);
		jsonObject->SetNumberField("PlayerMaxMovementSpeed", PlayerData.PlayerMovementSpeed);
		jsonObject->SetNumberField("PlayerBaseLevel", PlayerData.PlayerBaseLevel);

		jsonObject->SetBoolField("CanUseAnyAttack", bCanUseAnyAttack);
		jsonObject->SetBoolField("RemoteActivation", CanRemoteActivate);
	}

	return jsonObject;
}

bool UPlayerDataAsset::FromJson(FJsonObject& jsonObject)
{
	AttackDelayCount = jsonObject.GetNumberField("Attack_DelayCount");
	AttackDelayTime = jsonObject.GetNumberField("Attack_DelayTime");
	PlayerControllerAttr.CameraZOffsetMultiplier = jsonObject.GetNumberField("CameraZOffset");

	PlayerData.PlayerMaxHealth = jsonObject.GetNumberField("PlayerMaxHealth");
	PlayerData.PlayerMaxMana = jsonObject.GetNumberField("PlayerMaxMana");
	PlayerData.PlayerMovementSpeed = jsonObject.GetNumberField("PlayerMaxMovementSpeed");
	PlayerData.PlayerBaseLevel = jsonObject.GetNumberField("PlayerBaseLevel");

	bCanUseAnyAttack = jsonObject.GetBoolField("CanUseAnyAttack");
	CanRemoteActivate = jsonObject.GetBoolField("RemoteActivation");


	return true;
}



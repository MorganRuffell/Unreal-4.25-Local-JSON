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
		jsonObject->SetNumberField("Attack_DelayCount", AttackDelayData.AttackDelayCount);
		jsonObject->SetNumberField("Attack_HigherDelayTime", AttackDelayData.AttackDelayTime_Upper);
		jsonObject->SetNumberField("Attack_LowerDelayTime", AttackDelayData.AttackDelayTime_Lower);

		jsonObject->SetNumberField("CameraZOffset", PlayerControllerAttr.CameraZOffsetMultiplier);

		jsonObject->SetNumberField("PlayerMaxHealth", PlayerData.PlayerMaxHealth);
		jsonObject->SetNumberField("PlayerMaxMana", PlayerData.PlayerMaxMana);
		jsonObject->SetNumberField("PlayerMaxMovementSpeed", PlayerData.PlayerMovementSpeed);
		jsonObject->SetNumberField("PlayerBaseLevel", PlayerData.PlayerBaseLevel);

		jsonObject->SetBoolField("CanUseAnyAttack", bCanUseAnyAttack);
		jsonObject->SetBoolField("RemoteActivation", CanRemoteActivate);
		jsonObject->SetBoolField("CanUseHUD", CanUseHUD);
		jsonObject->SetBoolField("ForcePCUI", ForcePCUI);
		jsonObject->SetBoolField("ForceMobileUI", ForceMobileUI);
	}

	return jsonObject;
}

bool UPlayerDataAsset::FromJson(FJsonObject& jsonObject)
{
	PlayerControllerAttr.CameraZOffsetMultiplier = jsonObject.GetNumberField("CameraZOffset");

	AttackDelayData.AttackDelayCount = jsonObject.GetNumberField("Attack_DelayCount");
	AttackDelayData.AttackDelayTime_Upper = jsonObject.GetNumberField("Attack_HigherDelayTime");
	AttackDelayData.AttackDelayTime_Lower = jsonObject.GetNumberField("Attack_LowerDelayTime");

	PlayerData.PlayerMaxHealth = jsonObject.GetNumberField("PlayerMaxHealth");
	PlayerData.PlayerMaxMana = jsonObject.GetNumberField("PlayerMaxMana");
	PlayerData.PlayerMovementSpeed = jsonObject.GetNumberField("PlayerMaxMovementSpeed");
	PlayerData.PlayerBaseLevel = jsonObject.GetNumberField("PlayerBaseLevel");

	bCanUseAnyAttack = jsonObject.GetBoolField("CanUseAnyAttack");
	CanRemoteActivate = jsonObject.GetBoolField("RemoteActivation");
	CanUseHUD = jsonObject.GetBoolField("CanUseHUD");
	ForcePCUI = jsonObject.GetBoolField("ForcePCUI");
	ForceMobileUI = jsonObject.GetBoolField("ForceMobileUI");


	return true;
}



// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "AnimationNotifyStateDataAsset.h"

UAnimationNotifyStateDataAsset::UAnimationNotifyStateDataAsset()
{
	
}

UAnimationNotifyStateDataAsset::~UAnimationNotifyStateDataAsset()
{

}

TSharedPtr<FJsonObject> UAnimationNotifyStateDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("InnerRadius", AnimNotifyCameraData.InnerRadius);
	jsonObject->SetNumberField("OuterRadius", AnimNotifyCameraData.OuterRadius);
	jsonObject->SetNumberField("Falloff", AnimNotifyCameraData.Falloff);
	jsonObject->SetBoolField("OrientShakeToEpicentre", AnimNotifyCameraData.OrientShakeToEpicentre);

	jsonObject->SetNumberField("AttackDelayTime",AttackDelays.AttackDelayTime);
	jsonObject->SetNumberField("MaxAttackDelayCount", AttackDelays.MaxAttackDelayCount);

	jsonObject->SetBoolField("CanSweep",MoveForwardData.CanSweep);
	jsonObject->SetBoolField("CanTeleport", MoveForwardData.CanTeleport);
	jsonObject->SetNumberField("MoveForwardValue", MoveForwardData.MoveForwardValue);

	jsonObject->SetBoolField("ForceSlowMotion", SlowMotionData.bForceSlowMotion);
	jsonObject->SetNumberField("TimeDilation", SlowMotionData.TimeDilation);
	jsonObject->SetNumberField("EndSpeed", SlowMotionData.EndSpeed);
	jsonObject->SetNumberField("MotionSpeed", SlowMotionData.MotionSpeed);

	jsonObject->SetNumberField("AttackDelay",WeaponAttackNSData.AttackDelay);
	jsonObject->SetNumberField("MaxAttackDelayCount", WeaponAttackNSData.MaxAttackDelayCount);

	return jsonObject;
}

bool UAnimationNotifyStateDataAsset::FromJson(FJsonObject& jsonObject)
{
	AnimNotifyCameraData.InnerRadius = jsonObject.GetNumberField("InnerRadius");
	AnimNotifyCameraData.OuterRadius = jsonObject.GetNumberField("OuterRadius");
	AnimNotifyCameraData.Falloff = jsonObject.GetNumberField("Falloff");
	AnimNotifyCameraData.OrientShakeToEpicentre = jsonObject.GetBoolField("OrientShakeToEpicentre");

	AttackDelays.AttackDelayTime = jsonObject.GetNumberField("AttackDelayTime");
	AttackDelays.MaxAttackDelayCount = jsonObject.GetIntegerField("MaxAttackDelayCount");
	
	MoveForwardData.CanSweep = jsonObject.GetBoolField("CanSweep");
	MoveForwardData.CanTeleport = jsonObject.GetBoolField("CanTeleport");
	MoveForwardData.MoveForwardValue = jsonObject.GetNumberField("MoveForwardValue");

	SlowMotionData.bForceSlowMotion = jsonObject.GetBoolField("ForceSlowMotion");
	SlowMotionData.EndSpeed = jsonObject.GetNumberField("EndSpeed");
	SlowMotionData.MotionSpeed = jsonObject.GetNumberField("MotionSpeed");
	SlowMotionData.TimeDilation = jsonObject.GetNumberField("TimeDilation");

	WeaponAttackNSData.AttackDelay = jsonObject.GetNumberField("AttackDelay");
	WeaponAttackNSData.MaxAttackDelayCount = jsonObject.GetNumberField("MaxAttackDelayCount");

	return true;
}

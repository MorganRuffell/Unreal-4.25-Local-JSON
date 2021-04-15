// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "BossDataAsset.h"

UBossDataAsset::UBossDataAsset()
{

}

UBossDataAsset::~UBossDataAsset()
{

}

TSharedPtr<FJsonObject> UBossDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("DeathDelayTime", DeathDelayTime);
	jsonObject->SetNumberField("Animation Montage Index", AnimMontageSelection);

	jsonObject->SetNumberField("GravityScale", CharacterMovementData.GravityScale);
	jsonObject->SetNumberField("BossJumpZVelocity", CharacterMovementData.BossJumpZVelocity);
	jsonObject->SetNumberField("BossMass", CharacterMovementData.BossMass);
	jsonObject->SetNumberField("BossMaxAccleration", CharacterMovementData.BossMaxAcceleration);
	jsonObject->SetNumberField("BossMaxWalkSpeed", CharacterMovementData.BossMaxWalkSpeed);
	jsonObject->SetNumberField("BosMaxWalkSpeedCrouched", CharacterMovementData.BossMaxWalkSpeedCrouched);

	jsonObject->SetNumberField("NormalAnimationSpeed", AnimationSpeed.normal);
	jsonObject->SetNumberField("HalfAnimationSpeed", AnimationSpeed.Half);
	jsonObject->SetNumberField("QuarterAnimationSpeed", AnimationSpeed.Quarter);
	jsonObject->SetNumberField("FasterAnimationSpeed", AnimationSpeed.Faster);
	jsonObject->SetNumberField("FastestAnimationSpeed", AnimationSpeed.Fastest);

	return jsonObject;
}


bool UBossDataAsset::FromJson(FJsonObject& jsonObject)
{
	DeathDelayTime = jsonObject.GetNumberField("DeathDelayTime");
	AnimMontageSelection = jsonObject.GetNumberField("Animation Montage Index");

	CharacterMovementData.BossJumpZVelocity = jsonObject.GetNumberField("BossJumpZVelocity");
	CharacterMovementData.BossMass = jsonObject.GetNumberField("BossMass");
	CharacterMovementData.BossMaxAcceleration = jsonObject.GetNumberField("BossMaxAccleration");
	CharacterMovementData.BossMaxWalkSpeed= jsonObject.GetNumberField("BossMaxWalkSpeed");
	CharacterMovementData.BossMaxWalkSpeedCrouched = jsonObject.GetNumberField("BossMaxWalkSpeedCrouched");

	AnimationSpeed.normal = jsonObject.GetNumberField("NormalAnimationSpeed");
	AnimationSpeed.Half = jsonObject.GetNumberField("HalfAnimationSpeed");
	AnimationSpeed.Quarter = jsonObject.GetNumberField("QuarterAnimationSpeed");
	AnimationSpeed.Faster = jsonObject.GetNumberField("FasterAnimationSpeed");
	AnimationSpeed.Fastest = jsonObject.GetNumberField("FastestAnimationSpeed");

	return (true);
}



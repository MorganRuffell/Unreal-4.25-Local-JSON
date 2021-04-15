// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "TaskDataAsset.h"

UTaskDataAsset::UTaskDataAsset()
{
	MeleeAttackData.MeleeAttackDelay = 0.2f;
	AttackSkillData.SkillAttackDelay = 0.2f;
	

	GoAroundTargetTaskData.RadiusRange = 300.0f;
	TargetSurroundedData.AcceptableDistance = 300.0f;
	TargetSurroundedData.minSurrounders = 2;
}

UTaskDataAsset::~UTaskDataAsset()
{

}

TSharedPtr<FJsonObject> UTaskDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("MeleeAttackDelay", MeleeAttackData.MeleeAttackDelay);
	jsonObject->SetNumberField("SkillAttackDelay", AttackSkillData.SkillAttackDelay);
	
	jsonObject->SetNumberField("RadiusRange", GoAroundTargetTaskData.RadiusRange);
	
	jsonObject->SetNumberField("AcceptableDistance", TargetSurroundedData.AcceptableDistance);
	jsonObject->SetNumberField("minSurrounders", TargetSurroundedData.minSurrounders);

	jsonObject->SetBoolField("CanUseTeleportPhysics", StopAndRotateData.bTeleportPhysics);

	return jsonObject;
}

bool UTaskDataAsset::FromJson(FJsonObject& jsonObject)
{
	//Remember to create a solution that uses tryget fields

	MeleeAttackData.MeleeAttackDelay = jsonObject.GetNumberField("MeleeAttackDelay");
	AttackSkillData.SkillAttackDelay = jsonObject.GetNumberField("SkillAttackDelay");

	GoAroundTargetTaskData.RadiusRange = jsonObject.GetNumberField("RadiusRange");
	
	TargetSurroundedData.AcceptableDistance = jsonObject.GetNumberField("AcceptableDistance");
	TargetSurroundedData.minSurrounders = jsonObject.GetNumberField("minSurrounders");

	StopAndRotateData.bTeleportPhysics = jsonObject.GetBoolField("CanUseTeleportPhysics");

	return(true);

}
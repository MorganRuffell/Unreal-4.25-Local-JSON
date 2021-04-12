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

	AnimationSpeed.normal = jsonObject.GetNumberField("NormalAnimationSpeed");
	AnimationSpeed.Half = jsonObject.GetNumberField("HalfAnimationSpeed");
	AnimationSpeed.Quarter = jsonObject.GetNumberField("QuarterAnimationSpeed");
	AnimationSpeed.Faster = jsonObject.GetNumberField("FasterAnimationSpeed");
	AnimationSpeed.Fastest = jsonObject.GetNumberField("FastestAnimationSpeed");

	return (true);
}



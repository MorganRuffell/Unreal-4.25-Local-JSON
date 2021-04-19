// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ItemDataAsset.h"

UItemDataAsset::UItemDataAsset()
{

}

UItemDataAsset::~UItemDataAsset()
{

}

TSharedPtr<FJsonObject> UItemDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();


	jsonObject->SetNumberField("InteractionRadius", _InteractionRadius);
	jsonObject->SetNumberField("VolumeMultiplier", _SoundAttributes.VolumeMultiplier);
	jsonObject->SetNumberField("PitchMultiplier", _SoundAttributes.PitchMultiplier);
	jsonObject->SetNumberField("SoundStartTime", _SoundAttributes.SoundStartTime);

	jsonObject->SetNumberField("RotationSpeedSlow", RotationSpeeds.Slow);
	jsonObject->SetNumberField("RotationSpeedMedium", RotationSpeeds.Medium);
	jsonObject->SetNumberField("RotationSpeedFast", RotationSpeeds.Fast);

	jsonObject->SetBoolField("UseSRGB", UseSRGB);

	return jsonObject;
}


bool UItemDataAsset::FromJson(FJsonObject& JsonObject)
{

	_InteractionRadius = JsonObject.GetNumberField("InteractionRadius");

	_SoundAttributes.VolumeMultiplier = JsonObject.GetNumberField("VolumeMultiplier");
	_SoundAttributes.PitchMultiplier = JsonObject.GetNumberField("PitchMultiplier");
	_SoundAttributes.SoundStartTime = JsonObject.GetNumberField("SoundStartTime");


	UseSRGB = JsonObject.GetBoolField("UseSRGB");

	RotationSpeeds.Slow = JsonObject.GetNumberField("RotationSpeedSlow");
	RotationSpeeds.Medium = JsonObject.GetNumberField("RotationSpeedMedium");
	RotationSpeeds.Fast = JsonObject.GetNumberField("RotationSpeedFast");

	return (true);
}



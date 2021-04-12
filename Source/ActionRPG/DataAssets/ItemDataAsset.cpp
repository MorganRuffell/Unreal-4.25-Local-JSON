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

	jsonObject->SetNumberField("RotationSpeed", _RotationSpeed);
	jsonObject->SetNumberField("InteractionRadius", _InteractionRadius);
	jsonObject->SetNumberField("VolumeMultiplier", _SoundAttributes.VolumeMultiplier);
	jsonObject->SetNumberField("PitchMultiplier", _SoundAttributes.PitchMultiplier);
	jsonObject->SetNumberField("SoundStartTime", _SoundAttributes.SoundStartTime);

	//FJsonObjectConverter::UStructToJsonObject()?
	//Objects require different syntax?

	return jsonObject;
}


bool UItemDataAsset::FromJson(FJsonObject& JsonObject)
{
	_RotationSpeed = JsonObject.GetNumberField("RotationSpeed");
	_InteractionRadius = JsonObject.GetNumberField("InteractionRadius");
	_SoundAttributes.VolumeMultiplier = JsonObject.GetNumberField("VolumeMultiplier");
	_SoundAttributes.PitchMultiplier = JsonObject.GetNumberField("PitchMultiplier");
	_SoundAttributes.SoundStartTime = JsonObject.GetNumberField("SoundStartTime");

	return (true);
}



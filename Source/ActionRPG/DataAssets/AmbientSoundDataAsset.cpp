// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "AmbientSoundDataAsset.h"

UAmbientSoundDataAsset::UAmbientSoundDataAsset()
{
}

TSharedPtr<FJsonObject> UAmbientSoundDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();
	
	jsonObject->SetNumberField("PitchModulationMin", PitchModulationMin);
	jsonObject->SetNumberField("PitchModulationMax", PitchModulationMax);
	jsonObject->SetNumberField("VolumeModulationMin", VolumeModulationMin);
	jsonObject->SetNumberField("VolumeModulationMax", VolumeModulationMax);
	jsonObject->SetNumberField("VolumeMultiplier", VolumeMultiplier);
	jsonObject->SetNumberField("Priority", Priority);

	jsonObject->SetNumberField("bIsMusic", bIsMusic);
	jsonObject->SetNumberField("bAlwaysPlay", bAlwaysPlay);
	jsonObject->SetNumberField("bIgnoreForFlushing", bIgnoreForFlushing);

	return jsonObject;
}

bool UAmbientSoundDataAsset::FromJson(FJsonObject& jsonObject)
{
	PitchModulationMin = jsonObject.GetNumberField("PitchModulationMin");
	PitchModulationMax = jsonObject.GetNumberField("PitchModulationMax");
	VolumeModulationMin = jsonObject.GetNumberField("VolumeModulationMin");
	VolumeModulationMax = jsonObject.GetNumberField("VolumeModulationMax");
	VolumeMultiplier = jsonObject.GetNumberField("VolumeMultiplier");
	Priority = jsonObject.GetNumberField("Priority");
	
	bIsMusic = jsonObject.GetIntegerField("bIsMusic");
	bAlwaysPlay = jsonObject.GetIntegerField("bAlwaysPlay");
	bIgnoreForFlushing = jsonObject.GetIntegerField("bIgnoreForFlushing");
	
	return true;
}

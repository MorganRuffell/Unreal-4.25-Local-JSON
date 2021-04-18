// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "GameInstanceDataAsset.h"

UGameInstanceDataAsset::UGameInstanceDataAsset()
{
}

UGameInstanceDataAsset::~UGameInstanceDataAsset()
{
}

TSharedPtr<FJsonObject> UGameInstanceDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();
	
	jsonObject->SetBoolField("IsAbsolute", IsAbsolute);

	jsonObject->SetNumberField("SoundSystemGameInstance_Pitch", SoundData.Pitch);
	jsonObject->SetNumberField("SoundSystemGameInstance_UserIndex", SoundData.UserIndex);
	jsonObject->SetStringField("SoundSystemGameInstance_SlotName", SoundData.SlotName);
	jsonObject->SetBoolField("SoundSystemGameInstance_ApplyToChildren", SoundData.ApplyToChildren);
	
	jsonObject->SetNumberField("VolumeLevels_Zero", SoundData.VolumeLevels.Zero);
	jsonObject->SetNumberField("VolumeLevels_Small", SoundData.VolumeLevels.Small);
	jsonObject->SetNumberField("VolumeLevels_Max", SoundData.VolumeLevels.Max);

	jsonObject->SetNumberField("PlayTime",LoadingData.PlayTime);
	jsonObject->SetNumberField("PlayUntilStopped", LoadingData.PlayUntilStopped);

	return jsonObject;
}

bool UGameInstanceDataAsset::FromJson(FJsonObject& jsonObject)
{
	if (SoundData.UserIndex != 0)
	{
		return false;
	}

	SoundData.Pitch = jsonObject.GetNumberField("SoundSystemGameInstance_Pitch");
	SoundData.UserIndex = jsonObject.GetIntegerField("SoundSystemGameInstance_UserIndex");
	SoundData.SlotName = jsonObject.GetStringField("SoundSystemGameInstance_SlotName");
	SoundData.ApplyToChildren = jsonObject.GetBoolField("SoundSystemGameInstance_ApplyToChildren");
	
	SoundData.VolumeLevels.Zero = jsonObject.GetNumberField("VolumeLevels_Zero");
	SoundData.VolumeLevels.Small = jsonObject.GetNumberField("VolumeLevels_Small");
	SoundData.VolumeLevels.Max = jsonObject.GetNumberField("VolumeLevels_Max");
	
	LoadingData.PlayTime = jsonObject.GetNumberField("PlayTime");
	LoadingData.PlayUntilStopped = jsonObject.GetBoolField("PlayUntilStopped");

	return true;
}

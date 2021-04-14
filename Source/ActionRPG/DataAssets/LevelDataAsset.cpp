// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "LevelDataAsset.h"

ULevelDataAsset::ULevelDataAsset()
{

}

TSharedPtr<FJsonObject> ULevelDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	if (jsonObject.IsUnique())
	{
		jsonObject->SetNumberField("SceneIndex", LevelToLoadIndex);
	}

	return TSharedPtr<FJsonObject>();
}

bool ULevelDataAsset::FromJson(FJsonObject& jsonObject)
{
	LevelToLoadIndex = jsonObject.GetNumberField("SceneIndex");
	return true;
}

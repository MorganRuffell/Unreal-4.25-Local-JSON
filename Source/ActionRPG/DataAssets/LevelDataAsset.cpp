// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "LevelDataAsset.h"

ULevelDataAsset::ULevelDataAsset()
{

}

TSharedPtr<FJsonObject> ULevelDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("SceneIndex", LevelToLoadIndex);
	
	return jsonObject;
}

bool ULevelDataAsset::FromJson(FJsonObject& jsonObject)
{
	LevelToLoadIndex = jsonObject.GetNumberField("SceneIndex");

	return true;
}

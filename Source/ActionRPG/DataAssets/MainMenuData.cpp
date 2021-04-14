// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "MainMenuData.h"

TSharedPtr<FJsonObject> UMainMenuData::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();
	
	return jsonObject;

}

bool UMainMenuData::FromJson(FJsonObject& jsonObject)
{
	return false;
}

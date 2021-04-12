// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "SaveGameDataAsset.h"

USaveGameDataAsset::USaveGameDataAsset()
{

}

USaveGameDataAsset::~USaveGameDataAsset()
{

}

TSharedPtr<FJsonObject> USaveGameDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	//Could pass the FVector through here.

	return jsonObject;
}

bool USaveGameDataAsset::FromJson(FJsonObject& jsonObject)
{
	return (true);
}

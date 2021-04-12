// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "AICDataAsset.h"

UAICDataAsset::UAICDataAsset()
{
}

UAICDataAsset::~UAICDataAsset()
{
}

TSharedPtr<FJsonObject> UAICDataAsset::ToJson()
{
	return TSharedPtr<FJsonObject>();
}

bool UAICDataAsset::FromJson(FJsonObject& jsonObject)
{
	return false;
}

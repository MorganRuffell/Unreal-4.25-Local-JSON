// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "DirectionalLightData.h"

UDirectionalLightData::UDirectionalLightData()
{

}

TSharedPtr<FJsonObject> UDirectionalLightData::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();


	return jsonObject;
}

bool UDirectionalLightData::FromJson(FJsonObject& jsonObject)
{
	return true;
}

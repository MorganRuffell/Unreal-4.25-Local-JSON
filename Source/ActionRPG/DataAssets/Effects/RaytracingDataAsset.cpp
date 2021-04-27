// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "RaytracingDataAsset.h"

URaytracingDataAsset::URaytracingDataAsset()
{

}

URaytracingDataAsset::~URaytracingDataAsset()
{

}

TSharedPtr<FJsonObject> URaytracingDataAsset::ToJson()
{
	return TSharedPtr<FJsonObject>();
}

bool URaytracingDataAsset::FromJson(FJsonObject& jsonObject)
{
	return false;
}

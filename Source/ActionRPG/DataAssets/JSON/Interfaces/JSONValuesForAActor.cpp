
// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JSONValuesForAActor.h"

// Add default functionality here for any IJSONValuesForAActor functions that are not pure virtual.

bool IJSONValuesForAActor::GetJSONDataAssetData()
{
	return true;
}

bool IJSONValuesForAActor::GetJSONDataAssetData(UJSONDataAssetBase DataAsset) const
{
	return false;
}

bool IJSONValuesForAActor::GetJSONDataAssetData() const
{
	return false;
}

bool IJSONValuesForAActor::GetJSONDataAssetData(UJSONDataAssetBase DataAsset)
{
	return true;
}
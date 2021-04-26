// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ExponentialHeightDataAsset.h"


UExponentialHeightDataAsset::UExponentialHeightDataAsset()
{

}
UExponentialHeightDataAsset::~UExponentialHeightDataAsset()
{
}

TSharedPtr<FJsonObject> UExponentialHeightDataAsset::ToJson()
{
	return TSharedPtr<FJsonObject>();
}

bool UExponentialHeightDataAsset::FromJson(FJsonObject& jsonObject)
{
	return false;
}

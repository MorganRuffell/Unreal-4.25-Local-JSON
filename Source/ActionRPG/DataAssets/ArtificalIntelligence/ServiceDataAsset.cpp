// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ServiceDataAsset.h"

UServiceDataAsset::UServiceDataAsset()
{
	ClosestDistance = 9999.0f;
	MinSpeed = 300.0f;
	MaxSpeed = 600.0f;
}

UServiceDataAsset::~UServiceDataAsset()
{
	
}

TSharedPtr<FJsonObject> UServiceDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();	

	jsonObject->SetNumberField("ClosestDistance", ClosestDistance);
	jsonObject->SetNumberField("MinimumSpeed", MinSpeed);
	jsonObject->SetNumberField("MaximumSpeed", MaxSpeed);
	
	return jsonObject;
}

bool UServiceDataAsset::FromJson(FJsonObject& jsonObject)
{
	ClosestDistance = jsonObject.GetNumberField("ClosestDistance");
	MinSpeed = jsonObject.GetNumberField("MinimumSpeed");
	MaxSpeed = jsonObject.GetNumberField("MaximumSpeed");

	return true;
}

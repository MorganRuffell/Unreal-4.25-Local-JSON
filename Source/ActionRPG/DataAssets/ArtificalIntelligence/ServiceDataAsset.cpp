// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ServiceDataAsset.h"

UServiceDataAsset::UServiceDataAsset()
{
	NearestTargetService.ClosestDistance = 9999.0f;
	NearestTargetService.TargetTag = "Player";
	RandomMoveSpeedService.MinSpeed = 300.0f;
	RandomMoveSpeedService.MaxSpeed = 600.0f;
	
}

UServiceDataAsset::~UServiceDataAsset()
{

}

TSharedPtr<FJsonObject> UServiceDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("ClosestDistance", NearestTargetService.ClosestDistance);
	jsonObject->SetStringField("TargetTag", NearestTargetService.TargetTag);

	jsonObject->SetNumberField("MinimumSpeed", RandomMoveSpeedService.MinSpeed);
	jsonObject->SetNumberField("MaximumSpeed", RandomMoveSpeedService.MaxSpeed);

	return jsonObject;
}

bool UServiceDataAsset::FromJson(FJsonObject& jsonObject)
{
	NearestTargetService.ClosestDistance = jsonObject.GetNumberField("ClosestDistance");
	NearestTargetService.TargetTag = jsonObject.GetStringField("TargetTag");

	RandomMoveSpeedService.MinSpeed = jsonObject.GetNumberField("MinimumSpeed");
	RandomMoveSpeedService.MaxSpeed = jsonObject.GetNumberField("MaximumSpeed");

	return true;
}

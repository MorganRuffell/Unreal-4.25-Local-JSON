// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "TaskDataAsset.h"

UTaskDataAsset::UTaskDataAsset()
{
	RadiusRange = 300.0f;
	AcceptableDistance = 300.0f;
	minSurrounders = 2;
}

UTaskDataAsset::~UTaskDataAsset()
{

}

TSharedPtr<FJsonObject> UTaskDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("Radius_Range", RadiusRange);
	jsonObject->SetNumberField("AcceptableDist", AcceptableDistance);
	jsonObject->SetNumberField("Minimum_SurroundingEnemies", minSurrounders);

	return jsonObject;
}

bool UTaskDataAsset::FromJson(FJsonObject& jsonObject)
{
	//Remember to create a solution that uses tryget fields

	RadiusRange = jsonObject.GetNumberField("Radius_Range");
	AcceptableDistance = jsonObject.GetNumberField("AcceptableDist");
	minSurrounders = jsonObject.GetNumberField("Minimum_SurroundingEnemies");
	
	return(true);

}
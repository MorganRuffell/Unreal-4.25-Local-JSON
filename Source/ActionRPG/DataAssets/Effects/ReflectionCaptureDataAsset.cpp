// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ReflectionCaptureDataAsset.h"

UReflectionCaptureDataAsset::UReflectionCaptureDataAsset()
{


	
}

UReflectionCaptureDataAsset::~UReflectionCaptureDataAsset()
{


}

TSharedPtr<FJsonObject> UReflectionCaptureDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("InfluenceRadius", InfluenceRadius);
	jsonObject->SetNumberField("Brightness", Brightness);



	return jsonObject;
}

bool UReflectionCaptureDataAsset::FromJson(FJsonObject& jsonObject)
{
	InfluenceRadius = jsonObject.GetNumberField("InfluenceRadius");
	Brightness = jsonObject.GetNumberField("Brightness");

	return true;
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JsonManagerDataAsset.h"

UJsonManagerDataAsset::UJsonManagerDataAsset()
{
}

UJsonManagerDataAsset::~UJsonManagerDataAsset()
{
}

TSharedPtr<FJsonObject> UJsonManagerDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();
	
	jsonObject->SetStringField("JsonFileName", JSONFileName);
	jsonObject->SetStringField("CurveJsonFileName", CurveJSONFileName);

	jsonObject->SetBoolField("AllowOverwriting", AllowOverwriting);

	return jsonObject;
}

bool UJsonManagerDataAsset::FromJson(FJsonObject& jsonObject)
{
	JSONFileName = jsonObject.GetStringField("JsonFileName");
	CurveJSONFileName = jsonObject.GetStringField("CurveJsonFileName");

	AllowOverwriting = jsonObject.GetBoolField("AllowOverwriting");

	return true;
}
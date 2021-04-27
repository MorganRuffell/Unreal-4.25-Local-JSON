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
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("_FogDensity", FogDensity);
	jsonObject->SetNumberField("_MaxOpacity", MaxOpacity);
	jsonObject->SetNumberField("_InscatteringExp", InscatteringExponent);
	jsonObject->SetNumberField("_StartDistance", StartDistance);

	jsonObject->SetNumberField("ColorDataRed", ScatteringColorData.Red);
	jsonObject->SetNumberField("ColorDataBlue", ScatteringColorData.Blue);
	jsonObject->SetNumberField("ColorDataGreen", ScatteringColorData.Green);
	jsonObject->SetNumberField("ColorDataAlpha", ScatteringColorData.Alpha);

	return jsonObject;
}

bool UExponentialHeightDataAsset::FromJson(FJsonObject& jsonObject)
{
	FogDensity = jsonObject.GetNumberField("_FogDensity");
	MaxOpacity = jsonObject.GetNumberField("_MaxOpacity");
	InscatteringExponent = jsonObject.GetNumberField("_InscatteringExp");
	StartDistance = jsonObject.GetNumberField("_StartDistance");

	ScatteringColorData.Red = jsonObject.GetNumberField("ColorDataRed");
	ScatteringColorData.Green = jsonObject.GetNumberField("ColorDataGreen");
	ScatteringColorData.Blue = jsonObject.GetNumberField("ColorDataBlue");
	ScatteringColorData.Alpha = jsonObject.GetNumberField("ColorDataAlpha");

	return true;
}

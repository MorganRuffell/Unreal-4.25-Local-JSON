// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "DirectionalLightData.h"

UDirectionalLightData::UDirectionalLightData()
{
	
}

TSharedPtr<FJsonObject> UDirectionalLightData::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject-> SetNumberField("_LightIntensity" , Intensity);
	jsonObject-> SetNumberField("_IndirectLightingIntensity", IndirectLightingIntensity);
	jsonObject-> SetNumberField("_VolumentricScatteringIntensity", VolumetricScatteringIntensity);
	jsonObject-> SetBoolField("_CanUseTemperature", UseTemp);
	jsonObject -> SetBoolField ("_CanCastShadows", CanCastShadows);

	jsonObject->SetNumberField("RedComponent", Red);
	jsonObject->SetNumberField("GreenComponent", Green);
	jsonObject->SetNumberField("BlueComponent", Blue);

	return jsonObject;
}

bool UDirectionalLightData::FromJson(FJsonObject& jsonObject)
{
	Intensity = jsonObject.GetNumberField("_LightIntensity");
	IndirectLightingIntensity = jsonObject.GetNumberField("_IndirectLightingIntensity");
	VolumetricScatteringIntensity = jsonObject.GetNumberField("_VolumentricScatteringIntensity");

	Red = jsonObject.GetNumberField("RedComponent");
	Green = jsonObject.GetNumberField("GreenComponent");
	Blue = jsonObject.GetNumberField("BlueComponent");

	return true;
}

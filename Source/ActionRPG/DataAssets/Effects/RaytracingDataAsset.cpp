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
	TSharedPtr<FJsonObject> RaytracingData = MakeShared<FJsonObject>();

	RaytracingData->SetNumberField("Intensity_AO", Intensity);
	RaytracingData->SetNumberField("Radius_AO", Radius);
	RaytracingData->SetNumberField("MaxRoughness", MaxRoughness);
	RaytracingData->SetNumberField("RaytracingIntensity", RIntensity);

	RaytracingData->SetBoolField("IsPostProcessEnabled", IsPostProcessEnabled);
	RaytracingData->SetBoolField("IsAOEnabled", IsEnabled);
	RaytracingData->SetBoolField("CanIncludeTranslucents", IncludeTranslucents);
	RaytracingData->SetBoolField("IsAOEnabled", CanUseRefractions);

	return RaytracingData;
}

bool URaytracingDataAsset::FromJson(FJsonObject& jsonObject)
{
	Intensity = jsonObject.GetNumberField("IntensityAO");
	Radius = jsonObject.GetNumberField("Radius_AO");
	MaxRoughness = jsonObject.GetNumberField("MaxRoughness");
	RIntensity = jsonObject.GetNumberField("RaytracingIntensity");

	IsPostProcessEnabled = jsonObject.GetBoolField("IsPostProcessEnabled");
	IsEnabled = jsonObject.GetBoolField("IsAOEnabled");
	IncludeTranslucents = jsonObject.GetBoolField("CanIncludeTranslucents");
	CanUseRefractions = jsonObject.GetBoolField("IsAOEnabled");

	return true;
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "UIDisplayDataAsset.h"

UUIDisplayDataAsset::UUIDisplayDataAsset()
{

}

TSharedPtr<FJsonObject> UUIDisplayDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("UI_Delay",PCHUDDisplayData.UIDelay);
	jsonObject->SetNumberField("UI_Delay_PlaybackSpeed", PCHUDDisplayData.PlaybackSpeed);
	jsonObject->SetNumberField("UI_Delay_NumberofLoops", PCHUDDisplayData.NumberofLoopsToPlay);
	jsonObject->SetBoolField("RestoreState", PCHUDDisplayData.RestoreState);

	jsonObject->SetNumberField("BaseColor_Red", PCHUDDisplayData.BaseColorComponents.Red);
	jsonObject->SetNumberField("BaseColor_Green", PCHUDDisplayData.BaseColorComponents.Green);
	jsonObject->SetNumberField("BaseColor_Blue", PCHUDDisplayData.BaseColorComponents.Blue);

	jsonObject->SetNumberField("WarningColor_Red", PCHUDDisplayData.WarningColorComponents.Red);
	jsonObject->SetNumberField("WarningColor_Green", PCHUDDisplayData.WarningColorComponents.Green);
	jsonObject->SetNumberField("WarningColor_Blue", PCHUDDisplayData.WarningColorComponents.Blue);

	return jsonObject; 
}

bool UUIDisplayDataAsset::FromJson(FJsonObject& jsonObject)
{
	PCHUDDisplayData.UIDelay = jsonObject.GetNumberField("UI_Delay");
	PCHUDDisplayData.PlaybackSpeed = jsonObject.GetNumberField("UI_Delay_PlaybackSpeed");
	PCHUDDisplayData.PlaybackSpeed = jsonObject.GetNumberField("UI_Delay_NumberofLoops");
	PCHUDDisplayData.RestoreState = jsonObject.GetBoolField("RestoreState");

	PCHUDDisplayData.BaseColorComponents.Red = jsonObject.GetNumberField("BaseColor_Red");
	PCHUDDisplayData.BaseColorComponents.Green = jsonObject.GetNumberField("BaseColor_Green");
	PCHUDDisplayData.BaseColorComponents.Blue = jsonObject.GetNumberField("BaseColor_Blue");

	PCHUDDisplayData.WarningColorComponents.Red = jsonObject.GetNumberField("WarningColor_Red");
	PCHUDDisplayData.WarningColorComponents.Green = jsonObject.GetNumberField("WarningColor_Green");
	PCHUDDisplayData.WarningColorComponents.Blue = jsonObject.GetNumberField("WarningColor_Blue");


	return true;
}

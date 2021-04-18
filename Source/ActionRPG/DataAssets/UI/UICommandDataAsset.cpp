// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "UICommandDataAsset.h"

UUICommandDataAsset::UUICommandDataAsset()
{
}

TSharedPtr<FJsonObject> UUICommandDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();
	
	jsonObject->SetStringField("UI_StatisticsCommand",StatisticsUnit);
	jsonObject->SetStringField("UI_StatisticsRHICommand", StatisticRHI);

	
	return jsonObject;
}

bool UUICommandDataAsset::FromJson(FJsonObject& jsonObject)
{
	StatisticsUnit = jsonObject.GetStringField(StatisticsUnit);
	StatisticRHI = jsonObject.GetStringField(StatisticRHI);

	return true;
}


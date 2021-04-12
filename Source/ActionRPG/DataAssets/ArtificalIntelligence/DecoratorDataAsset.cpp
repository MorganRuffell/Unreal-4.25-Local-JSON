// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "DecoratorDataAsset.h"

UDecoratorDataAsset::UDecoratorDataAsset()
{
	MinHealthPercentage = 0.25f;
}

UDecoratorDataAsset::~UDecoratorDataAsset()
{
	
}

TSharedPtr<FJsonObject> UDecoratorDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("Dec_MinHealthPercentage", MinHealthPercentage);

	return jsonObject;
}

bool UDecoratorDataAsset::FromJson(FJsonObject& jsonObject)
{
	MinHealthPercentage = jsonObject.GetNumberField("Dec_MinHealthPercentage");

	return true;
}

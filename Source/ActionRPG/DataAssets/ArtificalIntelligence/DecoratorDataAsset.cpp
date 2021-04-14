// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "DecoratorDataAsset.h"

UDecoratorDataAsset::UDecoratorDataAsset()
{
	CheckHealthDecorator.MinHealthPercentage = 0.25f;
}

UDecoratorDataAsset::~UDecoratorDataAsset()
{
	
}

TSharedPtr<FJsonObject> UDecoratorDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("Dec_MinHealthPercentage", CheckHealthDecorator.MinHealthPercentage);

	jsonObject->SetNumberField("Dec_ItemSlotNumber", CheckItemDecorator.ItemSlotNumber);
	jsonObject->SetStringField("Dec_ItemKey", CheckItemDecorator.ItemKey);

	return jsonObject;
}

bool UDecoratorDataAsset::FromJson(FJsonObject& jsonObject)
{
	CheckHealthDecorator.MinHealthPercentage = jsonObject.GetNumberField("Dec_MinHealthPercentage");

	CheckItemDecorator.ItemSlotNumber = jsonObject.GetIntegerField("Dec_ItemSlotNumber");
	CheckItemDecorator.ItemKey = jsonObject.GetStringField("Dec_ItemKey");

	return true;
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "SoulDataAsset.h"

TSharedPtr<FJsonObject> USoulDataAsset::ToJson()
{
    TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

    jsonObject->SetNumberField("DelayFloor", DelayValuesData.DelayFloor);
	jsonObject->SetNumberField("DelayCeiling", DelayValuesData.DelayCeiling);

    return jsonObject;
}

bool USoulDataAsset::FromJson(FJsonObject& jsonObject)
{
    DelayValuesData.DelayCeiling = jsonObject.GetNumberField("DelayCeiling");
	DelayValuesData.DelayFloor= jsonObject.GetNumberField("DelayFloor");

    return true;
}

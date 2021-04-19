// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "NPCSpawnBoxDataAsset.h"

UNPCSpawnBoxDataAsset::UNPCSpawnBoxDataAsset()
{

}

TSharedPtr<FJsonObject> UNPCSpawnBoxDataAsset::ToJson()
{
    TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

    jsonObject->SetNumberField("BoxExtendX", x);
    jsonObject->SetNumberField("BoxExtendY", y);
    jsonObject->SetNumberField("BoxExtendZ", z);

    return jsonObject;
}

bool UNPCSpawnBoxDataAsset::FromJson(FJsonObject& jsonObject)
{
    x = jsonObject.GetNumberField("BoxExtendX");
    y = jsonObject.GetNumberField("BoxExtendY");
    z = jsonObject.GetNumberField("BoxExtendZ");

    return true;
}

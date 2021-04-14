// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "EnemyGlobalData.h"

TSharedPtr<FJsonObject> UEnemyGlobalData::ToJson()
{
    TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

    jsonObject->SetNumberField("BoundingBox_X", SpawnVectorValues.X);
	jsonObject->SetNumberField("BoundingBox_Y", SpawnVectorValues.Y);
	jsonObject->SetNumberField("BoundingBox_Z", SpawnVectorValues.Z);

    jsonObject->SetNumberField("SoulSpawnCount_Minimum", SoulAmounts_External.SoulMin);
	jsonObject->SetNumberField("SoulSpawnCount_Maximum", SoulAmounts_External.SoulMax);

    jsonObject->SetNumberField("PotionDropAmounts", PotionDropAmounts_External);
    jsonObject->SetNumberField("TimeBonusPerKill",TimeBonusPerKill_External);

    return jsonObject;
}

bool UEnemyGlobalData::FromJson(FJsonObject& jsonObject)
{
    SpawnVectorValues.X = jsonObject.GetNumberField("BoundingBox_X");
	SpawnVectorValues.Y = jsonObject.GetNumberField("BoundingBox_Y");
	SpawnVectorValues.Z = jsonObject.GetNumberField("BoundingBox_Z");

    SoulAmounts_External.SoulMin = jsonObject.GetNumberField("SoulSpawnCount_Minimum");
	SoulAmounts_External.SoulMax = jsonObject.GetNumberField("SoulSpawnCount_Maximum");

    PotionDropAmounts_External = jsonObject.GetNumberField("PotionDropAmounts");
    TimeBonusPerKill_External = jsonObject.GetNumberField("TimeBonusPerKill");

    return true;
}


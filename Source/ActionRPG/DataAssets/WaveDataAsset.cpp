// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "WaveDataAsset.h"

#include "Serialization/JsonReader.h"
#include "Serialization/JsonSerializer.h"

#include "Serialization/JsonWriter.h"

#pragma optimize("", off)

TSharedRef<FJsonObject> FSpawnGroup::ToJson()
{
	TSharedRef<FJsonObject> outJson = MakeShared<FJsonObject>();
	FJsonObjectConverter::UStructToJsonObject(FSpawnGroup::StaticStruct(), this, outJson, 0, 0);
	return outJson;
}

void FSpawnGroup::FromJson(TSharedRef<FJsonObject> json)
{
	FJsonObjectConverter::JsonObjectToUStruct(json, FSpawnGroup::StaticStruct(), this, 0, 0);
}

TSharedRef<FJsonObject> FWaveData::ToJson()
{
	TSharedRef<FJsonObject> outJson = MakeShared<FJsonObject>();
	outJson->SetNumberField("WaveTime", WaveTime);

	TArray<TSharedPtr<FJsonValue>> objects = TArray<TSharedPtr<FJsonValue>>();

	for (int i = 0; i < EnemiesGroups.Num(); i++)
	{
		TSharedPtr<FJsonObject> jsonObject = EnemiesGroups[i].ToJson();
		TSharedPtr<FJsonValueObject> jsonValueObject = MakeShared<FJsonValueObject>(FJsonValueObject(jsonObject));
		objects.Add(jsonValueObject);
	}

	outJson->SetArrayField("EnemiesGroups", objects);

	return outJson;
}

void FWaveData::FromJson(TSharedRef<FJsonObject> json)
{
	WaveTime = json->GetNumberField("WaveTime");

	EnemiesGroups.Empty();
	const TArray<TSharedPtr<FJsonValue>> valueArray = json->GetArrayField("EnemiesGroups");
	for (int i = 0; i < valueArray.Num(); i++)
	{
		FSpawnGroup group = FSpawnGroup();
		group.FromJson(valueArray[i]->AsObject().ToSharedRef());
		EnemiesGroups.Add(group);
	}
}

TSharedPtr<FJsonObject> UWaveDataAsset::ToJson()
{
	TSharedRef<FJsonObject> outJson = MakeShared<FJsonObject>();
	TArray<TSharedPtr<FJsonValue>> objects = TArray<TSharedPtr<FJsonValue>>();

	for (int i = 0; i < WaveData.Num(); i++)
	{
		TSharedPtr<FJsonObject> jsonObject = WaveData[i].ToJson();
		TSharedPtr<FJsonValueObject> jsonValueObject = MakeShared<FJsonValueObject>(FJsonValueObject(jsonObject));
		objects.Add(jsonValueObject);
	}

	outJson->SetArrayField("WaveData", objects);
	return outJson;
}

bool UWaveDataAsset::FromJson(FJsonObject& jsonObject)
{
	WaveData.Empty();
	const TArray<TSharedPtr<FJsonValue>> valueArray = jsonObject.GetArrayField("WaveData");
	for (int i = 0; i < valueArray.Num(); i++)
	{
		FWaveData wave = FWaveData();
		wave.FromJson(valueArray[i]->AsObject().ToSharedRef());
		WaveData.Add(wave);
	}
	return true;
}

#pragma optimize("", on)
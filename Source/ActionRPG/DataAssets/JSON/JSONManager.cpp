// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Templates/SharedPointer.h"
#include "JSONManager.h"
#include "JSONDataAssetBase.h"

AJSONManager::AJSONManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AJSONManager::BeginPlay()
{
	Super::BeginPlay();

}

TSharedPtr<FJsonObject> AJSONManager::GetJsonFromString(const FString& jsonString)
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonString);
	FJsonSerializer::Deserialize(reader, jsonObject);

	return jsonObject;
}

FString AJSONManager::GetStringFromJson(TSharedRef<FJsonObject> jsonObject)
{
	FString output;

	TSharedRef<TJsonWriter<TCHAR>> writer = TJsonWriterFactory<TCHAR>::Create(&output);
	FJsonSerializer::Serialize(jsonObject, writer);

	return output;
}

//On validate eqv. 
void AJSONManager::PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName propertyName = PropertyChangedEvent.Property->GetFName();

	if (propertyName == GET_MEMBER_NAME_CHECKED(AJSONManager, bFromJson))
	{
		bFromJson = false;

		TSharedPtr<FJsonObject> LocalJSONObject = GetJsonFromString(JsonInput);

		for (TPair<FString, TSharedPtr<FJsonValue>> pair : LocalJSONObject->Values)
		{
			for (UJSONDataAssetBase* AssetBase : JsonDataAssets)
			{
				if (AssetBase->JSONKey == pair.Key)
				{
					TSharedPtr<FJsonObject> AssetJSON = pair.Value->AsObject();
					AssetBase->FromJson(*AssetJSON.Get());
				}
			}

		}

		CurveTableProcessingFromJson();
	}

	if (propertyName == GET_MEMBER_NAME_CHECKED(AJSONManager, bToJson))
	{
		bToJson = false;

		ObjectsToJSON.Empty();

		if (JsonDataAssets.Num() > 0)
		{
			TSharedPtr<FJsonObject> LocalJSONObject = MakeShared<FJsonObject>();

			for (UJSONDataAssetBase* AssetBase : JsonDataAssets)
			{
				LocalJSONObject->SetObjectField(AssetBase->JSONKey, AssetBase->ToJson());
				ObjectsToJSON.Add(AssetBase);
			}

			JsonOutput = GetStringFromJson(LocalJSONObject.ToSharedRef());

			CurveTableProcessingToJson();
		}
	}
}

void AJSONManager::CurveTableProcessingToJson()
{
	if (CurveTableJsonOutput.IsEmpty() == true)
	{
		for (UCurveTable* CurveTable : CurveTables)
		{
			CurveTableJsonOutput.Append(CurveTable->GetTableAsJSON());
		}
	}
	else
	{
		CurveTableJsonOutput.Reset();

		for (UCurveTable* CurveTable : CurveTables)
		{
			CurveTableJsonOutput.Append(CurveTable->GetTableAsJSON());
		}
	}

}

void AJSONManager::CurveTableProcessingFromJson()
{
	if (CurveTableJsonOutput.IsEmpty() == false)
	{
		//TSharedRef<UCurveTable> LocalCurveTable = MakeShared<UCurveTable>();
		
		//for (TPair<FString, TSharedPtr<UCurveTable>> pair : LocalCurveTable->)
		//{
		//	//Make table from this?
		//}
	}
	else
	{

	}
}

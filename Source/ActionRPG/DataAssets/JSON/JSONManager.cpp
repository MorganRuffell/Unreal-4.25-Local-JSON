// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JSONManager.h"

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

		//Ignore the map approach. Do it as a whole JSON string. We'll figure maps out later.

		TSharedPtr<FJsonObject> LocalJSONObject = GetJsonFromString(JsonInput);

		for (TPair<FString, TSharedPtr<FJsonValue>> pair : LocalJSONObject->Values)
		{
			for (UJSONDataAssetBase* AssetBase : JsonDataAssets)
			{
				if (AssetBase->JSONKey == pair.Key)
				{
					TSharedPtr<FJsonObject> AssetJSON = pair.Value->AsObject();
					AssetBase->FromJson(*AssetJSON.Get());

					//Goes over all of the assets and you have to manually ensure that this is unique.
				}
			}
		}
	}

	if (propertyName == GET_MEMBER_NAME_CHECKED(AJSONManager, bToJson))
	{
		bToJson = false;

		if (JsonDataAssets.Num() > 0)
		{
			TSharedPtr<FJsonObject> LocalJSONObject = MakeShared<FJsonObject>();

			for (UJSONDataAssetBase* AssetBase : JsonDataAssets)
			{
				LocalJSONObject->SetObjectField(AssetBase->JSONKey, AssetBase->ToJson());
			}

			JsonOutput = GetStringFromJson(LocalJSONObject.ToSharedRef());
		}
	}

}




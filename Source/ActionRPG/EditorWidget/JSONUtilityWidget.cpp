// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "JSONUtilityWidget.h"



UJSONUtilityWidget::UJSONUtilityWidget()
{

}

UJSONUtilityWidget::~UJSONUtilityWidget()
{
}

void UJSONUtilityWidget::PushToJSON()
{
	TSharedPtr<FJsonObject> LocalJSONObject = MakeShared<FJsonObject>();

	for (UJSONDataAssetBase* AssetBase : JsonDataAssets)
	{
		LocalJSONObject->SetObjectField(AssetBase->JSONKey, AssetBase->ToJson());
	}

	JsonOutput = GetStringFromJson(LocalJSONObject.ToSharedRef());
	JsonInput = JsonOutput;
}

void UJSONUtilityWidget::PullFromJSON()
{
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
}

void UJSONUtilityWidget::SaveToLocal()
{
	SaveToLocalDirectory(JsonOutput, ".json", ManagerData->JSONFileName, FileContents, ManagerData->AllowOverwriting, ManagerData->_directory);
	SaveToLocalDirectory(JsonOutput, ".xml", ManagerData->JSONFileName, FileContents, ManagerData->AllowOverwriting, ManagerData->_directory);
	SaveToLocalDirectory(JsonOutput, ".csv", ManagerData->JSONFileName, FileContents, ManagerData->AllowOverwriting, ManagerData->_directory);
}

void UJSONUtilityWidget::SaveToLocalDirectory(FString JSONOutputString, FString FileType, FString FileName, TArray<FString> _FileContents, bool AllowOverwriting, FString FileDirectoryToLoadFrom) const
{
	if (CanSaveToLocalDirectory)
	{
		if (AllowOverwriting)
		{
			FString SaveDirectory = "";

			_FileContents.Add(JSONOutputString);
			SaveDirectory = FPaths::ProjectDir().Append(FileDirectoryToLoadFrom);

			FileName.Append(FileType);

			UUTextFileManager::SaveArrayText(SaveDirectory, FileName, _FileContents, AllowOverwriting);
		}

		else
		{
			FString SaveDirectory = "";

			_FileContents.Add(JSONOutputString);
			SaveDirectory = FPaths::ProjectDir().Append(FileDirectoryToLoadFrom);

			FileName.Append(FileType);

			UUTextFileManager::SaveArrayText(SaveDirectory, FileName, _FileContents, AllowOverwriting);
		}

	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("This client does not have the required permissions to perform this action."));
	}
}

TSharedPtr<FJsonObject> UJSONUtilityWidget::GetJsonFromString(const FString& jsonString)
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	TSharedRef<TJsonReader<TCHAR>> reader = TJsonReaderFactory<TCHAR>::Create(jsonString);
	FJsonSerializer::Deserialize(reader, jsonObject);

	return jsonObject;
}

FString UJSONUtilityWidget::GetStringFromJson(TSharedRef<FJsonObject> jsonObject)
{
	FString output;

	TSharedRef<TJsonWriter<TCHAR>> writer = TJsonWriterFactory<TCHAR>::Create(&output);
	FJsonSerializer::Serialize(jsonObject, writer);

	return output;
}

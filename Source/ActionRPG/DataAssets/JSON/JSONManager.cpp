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


	CollectJSONData(ManagerData,_FileTypes);
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
			WaveProgressionDataToJSON();
		}
	}
}

void AJSONManager::WaveProgressionDataToJSON()
{
	if (WaveProgressionString.IsEmpty() == true)
	{
		for (UDataTable* DataTable : WaveProgressionData)
		{
			WaveProgressionString.Append(DataTable->GetTableAsJSON());
		}
	}
	else
	{
		WaveProgressionData.Reset();

		for (UDataTable* DataTable : WaveProgressionData)
		{
			WaveProgressionString.Append(DataTable->GetTableAsJSON());
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
		/*for (UCurveTable* CurveTable : CurveTables)
		{
		}*/
	}
	else
	{

	}
}

void AJSONManager::CollectJSONData(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileType)
{
	SaveToLocalDirectory(JsonOutput, FileType.JSON, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(JsonOutput, FileType.XML, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(JsonOutput, FileType.CSV, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(JsonOutput, FileType.TEXT, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);

	SaveToLocalDirectory(CurveTableJsonOutput, FileType.TEXT, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(CurveTableJsonOutput, FileType.XML, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(CurveTableJsonOutput, FileType.CSV, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(CurveTableJsonOutput, FileType.JSON, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);

	SaveToLocalDirectory(WaveProgressionString, FileType.TEXT, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(WaveProgressionString, FileType.XML, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(WaveProgressionString, FileType.CSV, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(WaveProgressionString, FileType.JSON, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);

}

void AJSONManager::SaveToLocalDirectory(FString JSONOutputString, FString FileType, FString FileName, TArray<FString> _FileContents, bool AllowOverwriting, FString FileDirectoryToLoadFrom)
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
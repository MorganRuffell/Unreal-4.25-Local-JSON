// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Templates/SharedPointer.h"
#include "JSONManager.h"
#include "JSONDataAssetBase.h"
#include <UnrealString.h>

#pragma optimize("",off)

AJSONManager::AJSONManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AJSONManager::BeginPlay()
{
	if (HasAuthority() && CanSaveToLocalDirectory)
	{
		CollectJSONData(ManagerData, _FileTypes);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("This client does not have authority and cannot complete this operation"));
	}
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
	if (!HasAuthority()) { return; }

	Super::PostEditChangeProperty(PropertyChangedEvent);

	FName propertyName = PropertyChangedEvent.Property->GetFName();

	if (propertyName == GET_MEMBER_NAME_CHECKED(AJSONManager, bFromJson))
	{
		bFromJson = false;

		TSharedPtr<FJsonObject> LocalJSONObject = GetJsonFromString(JsonOutput);

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

			CreateJSONDataAssetCollection(ObjectsFromJSON);
		}

		WaveProgressionDataFromJson();
		CurveTableProcessingFromJson();
	}

	if (propertyName == GET_MEMBER_NAME_CHECKED(AJSONManager, bToJson))
	{
		bToJson = false;

		ObjectsToJSON.Empty();

		if (JsonDataAssets.Num() > 0 && DifficultyJsonDataAssets.Num())
		{
			TSharedPtr<FJsonObject> LocalJSONObject = MakeShared<FJsonObject>();
			TSharedPtr<FJsonObject> DifficultyJSONObject = MakeShared<FJsonObject>();


			for (UJSONDataAssetBase* AssetBase : JsonDataAssets)
			{
				LocalJSONObject->SetObjectField(AssetBase->JSONKey, AssetBase->ToJson());
			}

			for (UJSONDataAssetBase* DifficultyData : DifficultyJsonDataAssets)
			{
				LocalJSONObject->SetObjectField(DifficultyData->JSONKey, DifficultyData->ToJson());
				DifficultyJSONObject->SetObjectField(DifficultyData->JSONKey, DifficultyData->ToJson());
			}

			for (UJSONDataAssetBase* AssetBase : JsonDataAssets)
			{
				FString OutputString;

				TSharedPtr<FJsonObject> IndividualDataAsset = MakeShared<FJsonObject>();

				TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);

				FJsonSerializer::Serialize(IndividualDataAsset.ToSharedRef(), Writer);

				IndividualDataAsset->SetObjectField(AssetBase->JSONKey, AssetBase->ToJson());
				OutputString = GetStringFromJson(IndividualDataAsset.ToSharedRef());
				ObjectsToJSON.Add(AssetBase, OutputString);
			}

			for (UJSONDataAssetBase* AssetBase : DifficultyJsonDataAssets)
			{
				FString OutputString;

				TSharedPtr<FJsonObject> IndividualDataAsset = MakeShared<FJsonObject>();

				TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);

				FJsonSerializer::Serialize(IndividualDataAsset.ToSharedRef(), Writer);

				IndividualDataAsset->SetObjectField(AssetBase->JSONKey, AssetBase->ToJson());
				OutputString = GetStringFromJson(IndividualDataAsset.ToSharedRef());
				ObjectsToJSON.Add(AssetBase, OutputString);
			}

			JsonOutput = GetStringFromJson(LocalJSONObject.ToSharedRef());

			JsonDifficultyOutput = GetStringFromJson(DifficultyJSONObject.ToSharedRef());

			CurveTableProcessingToJson();
			WaveProgressionDataToJSON();
		}
	}
}

void AJSONManager::CreateJSONDataAssetCollection(TMap<UJSONDataAssetBase*, FString> Collection)
{
	if (CollectionControls.CanCreateJSONCollection == false) { return; }

	for (UJSONDataAssetBase* AssetBase : JsonDataAssets)
	{
		FString OutputString;

		TSharedPtr<FJsonObject> IndividualDataAsset = MakeShared<FJsonObject>();

		TSharedRef<TJsonWriter<>> Writer = TJsonWriterFactory<>::Create(&OutputString);

		FJsonSerializer::Serialize(IndividualDataAsset.ToSharedRef(), Writer);

		IndividualDataAsset->SetObjectField(AssetBase->JSONKey, AssetBase->ToJson());
		OutputString = GetStringFromJson(IndividualDataAsset.ToSharedRef());
		Collection.Add(AssetBase, OutputString);
	}
}


void AJSONManager::CreateWaveDataTableCollection(TMap<UDataTable*, FString> Collection)
{
	if (!CollectionControls.CanCreateDataTableCollection) { return; }

	for (UDataTable* DataTable : WaveProgressionData)
	{
		FString OutputString;

		OutputString = DataTable->GetTableAsJSON(EDataTableExportFlags::UsePrettyPropertyNames);

		Collection.Add(DataTable, OutputString);
	}
}


void AJSONManager::CreateAttributeTableCollection(TMap<UCurveTable*, FString> Collection)
{
	if (CollectionControls.CanCreateCurveCollection == false) { return; }

	for (UCurveTable* CurveTable : CurveTables)
	{
		FString OutputString;

		OutputString = CurveTable->GetTableAsJSON();

		Collection.Add(CurveTable, OutputString);
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
		WaveProgressionString.Empty();

		for (UDataTable* DataTable : WaveProgressionData)
		{
			WaveProgressionString.Append(DataTable->GetTableAsJSON());
		}
	}

	CreateWaveDataTableCollection(WaveProgressionToJSON);

}

void AJSONManager::CurveTableProcessingToJson()
{
	if (CollectionControls.CanCreateCurveCollection == true)
	{
		CreateAttributeTableCollection(CurvesToJSON);
	}

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
	for (UCurveTable* CurveTable : CurveTables)
	{
		FString OutputString;

		OutputString = CurveTable->GetTableAsJSON();

		CurvesFromJSON.Add(CurveTable, OutputString);
	}

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

void AJSONManager::WaveProgressionDataFromJson()
{
	for (UDataTable* DataTable : WaveProgressionData)
	{
		FString OutputString;

		OutputString = DataTable->GetTableAsJSON(EDataTableExportFlags::UsePrettyPropertyNames);

		WaveProgressionFromJSON.Add(DataTable, OutputString);
	}
}

void AJSONManager::CollectJSONData(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileType) const
{
	if (CanSaveToLocalDirectory)
	{
		SaveJSONAssetsToLocalDirectory(ManagerDataAsset, FileType);
		SaveCurvetablesToLocalDirectory(ManagerDataAsset, FileType);
		SaveDataTablesToLocalDirectory(ManagerDataAsset, FileType);
	}
	else
	{
		UE_LOG(LogTemp, Warning, TEXT("Saving To local directory is disabled"));

	}
}

void AJSONManager::SaveJSONAssetsToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const
{
	if (LocalFileControls.CanSaveJSONData)
	{
		SaveToLocalDirectory(JsonOutput, FileTypes.JSON, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(JsonOutput, FileTypes.XML, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(JsonOutput, FileTypes.CSV, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(JsonOutput, FileTypes.TEXT, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);

		if (LocalFileControls.CanSaveJSONDifficultyData)
		{
			SaveToLocalDirectory(JsonDifficultyOutput, FileTypes.JSON, ManagerDataAsset->JSONDifficultyFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
			SaveToLocalDirectory(JsonDifficultyOutput, FileTypes.XML, ManagerDataAsset->JSONDifficultyFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
			SaveToLocalDirectory(JsonDifficultyOutput, FileTypes.CSV, ManagerDataAsset->JSONDifficultyFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
			SaveToLocalDirectory(JsonDifficultyOutput, FileTypes.TEXT, ManagerDataAsset->JSONDifficultyFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		}
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Saving JSON Data Locally is disabled, cannot save!"));
	}
}

void AJSONManager::SaveCurvetablesToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const
{
	if (LocalFileControls.CanSaveAttributeData)
	{
		SaveToLocalDirectory(CurveTableJsonOutput, FileTypes.TEXT, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(CurveTableJsonOutput, FileTypes.XML, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(CurveTableJsonOutput, FileTypes.CSV, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(CurveTableJsonOutput, FileTypes.JSON, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Saving Attribute JSON data locally is disabled, cannot save!"));
	}
}

void AJSONManager::SaveDataTablesToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const
{
	if (LocalFileControls.CanSaveWaveData)
	{
		SaveToLocalDirectory(WaveProgressionString, FileTypes.TEXT, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(WaveProgressionString, FileTypes.XML, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(WaveProgressionString, FileTypes.CSV, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
		SaveToLocalDirectory(WaveProgressionString, FileTypes.JSON, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	}
	else
	{
		UE_LOG(LogTemp, Error, TEXT("Saving wave data locally is disabled, cannot save!"));

	}	
}

void AJSONManager::SaveToLocalDirectory(FString JSONOutputString, FString FileType, FString FileName, TArray<FString> _FileContents, bool AllowOverwriting, FString FileDirectoryToLoadFrom) const
{
	if (HasAuthority() && CanSaveToLocalDirectory)
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

#pragma optimize("",on)

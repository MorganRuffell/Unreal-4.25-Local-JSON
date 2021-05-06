// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Templates/SharedPointer.h"
#include "JSONManager.h"
#include "JSONDataAssetBase.h"

#pragma optimize("",off)

AJSONManager::AJSONManager()
{
	PrimaryActorTick.bCanEverTick = true;
}

void AJSONManager::BeginPlay()
{
	Super::BeginPlay();

	if (HasAuthority())
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
			JsonInput = JsonOutput;

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

void AJSONManager::CollectJSONData(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileType) const
{
	SaveJSONAssetsToLocalDirectory(ManagerDataAsset, FileType);
	SaveCurvetablesToLocalDirectory(ManagerDataAsset, FileType);
	SaveDataTablesToLocalDirectory(ManagerDataAsset, FileType);
}

void AJSONManager::SaveJSONAssetsToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const
{
	SaveToLocalDirectory(JsonOutput, FileTypes.JSON, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(JsonOutput, FileTypes.XML, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(JsonOutput, FileTypes.CSV, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(JsonOutput, FileTypes.TEXT, ManagerDataAsset->JSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
}

void AJSONManager::SaveCurvetablesToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const
{
	SaveToLocalDirectory(CurveTableJsonOutput, FileTypes.TEXT, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(CurveTableJsonOutput, FileTypes.XML, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(CurveTableJsonOutput, FileTypes.CSV, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(CurveTableJsonOutput, FileTypes.JSON, ManagerDataAsset->CurveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
}

void AJSONManager::SaveDataTablesToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const
{
	SaveToLocalDirectory(WaveProgressionString, FileTypes.TEXT, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(WaveProgressionString, FileTypes.XML, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(WaveProgressionString, FileTypes.CSV, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
	SaveToLocalDirectory(WaveProgressionString, FileTypes.JSON, ManagerDataAsset->WaveJSONFileName, FileContents, ManagerDataAsset->AllowOverwriting, ManagerDataAsset->_directory);
}

void AJSONManager::SaveToLocalDirectory(FString JSONOutputString, FString FileType, FString FileName, TArray<FString> _FileContents, bool AllowOverwriting, FString FileDirectoryToLoadFrom) const
{
	if (HasAuthority())
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

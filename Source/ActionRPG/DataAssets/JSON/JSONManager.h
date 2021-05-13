// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"

//
#include "DataAssets/JSON/JsonManagerDataAsset.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"

//Different Data storage systems
#include "Engine/CurveTable.h"
#include "Engine/DataTable.h"

//File path controllers
#include "Misc/Paths.h"
#include "LocalFileOperations/UTextFileManager.h"

#include "Containers/Map.h"

//IWYU - Include what you use, JSON classes
#include "Serialization/JsonReader.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"


#include <UnrealString.h>
#include "JsonObjectConverter.h"

#include "JSONManager.generated.h"
USTRUCT(BlueprintType, Blueprintable)
struct FCollectionControls
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON - Collections")
	bool CanCreateJSONCollection = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON - Collections")
	bool CanCreateCurveCollection = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON - Collections")
	bool CanCreateDataTableCollection = true;

};

USTRUCT(BlueprintType, Blueprintable)
struct FLocalFileControls
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON - Collections")
	bool CanSaveJSONData = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON - Collections")
	bool CanSaveAttributeData = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON - Collections")
	bool CanSaveWaveData = true;

};

USTRUCT(Blueprintable, BlueprintType)
struct FFileTypes
{
	GENERATED_BODY()

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LocalFile")
	FString JSON = ".json";

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LocalFile")
	FString CSV = ".csv";

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LocalFile")
	FString TEXT = ".txt";

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = "LocalFile")
	FString XML = ".xml";
};

UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API AJSONManager : public AActor
{
	GENERATED_BODY()

public:
	AJSONManager();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "")
	UJsonManagerDataAsset* ManagerData;

	
public:

	// Fields for the new section that will allow me to prase multiple JSON Objects

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON")
	bool bFromJson;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON")
	bool bToJson;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON")
	bool CanSaveToLocalDirectory = true;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON")
	bool UseDifficultyDataAssets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "_Control JSON")
	TArray<FString> FileContents;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON")
	FCollectionControls CollectionControls;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "_Control JSON")
	FLocalFileControls LocalFileControls;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
	TSet<UJSONDataAssetBase*> JsonDataAssets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON - Difficulty")
	TSet<UJSONDataAssetBase*> DifficultyJsonDataAssets;


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JSON Output")
	FString JsonOutput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JSON Output")
	FString JsonDifficultyOutput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JSON Input")
	FString JsonInput;


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local File")
	FFileTypes _FileTypes;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local File")
	FString JSONFileName = "DataAssetsJSONData";

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Local File")
		FString CurveFileName = "CurvetablesJSONData";

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve Tables")
	TSet<UCurveTable*> CurveTables;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve Tables")
		FString CurveTableJsonOutput;

	void CurveTableProcessingToJson();

	void CurveTableProcessingFromJson();

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Progression Data")
	TSet<UDataTable*> WaveProgressionData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WaveProgressionData")
	FString WaveProgressionString;

	void WaveProgressionDataToJSON();


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Inputs")
	TMap<UJSONDataAssetBase*, FString> ObjectsToJSON;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Outputs")
	TMap<UJSONDataAssetBase*, FString> ObjectsFromJSON;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Inputs")
	TMap<UCurveTable*, FString> CurvesToJSON;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Outputs")
	TMap<UCurveTable*, FString> CurvesFromJSON;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Inputs")
	TMap<UDataTable*, FString> WaveProgressionToJSON;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Outputs")
	TMap<UDataTable*, FString> WaveProgressionFromJSON;


public:

	UFUNCTION()
	void CollectJSONData(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileType) const;

	UFUNCTION()
	void SaveToLocalDirectory(FString JSONOutputString, FString FileType, FString FileName, TArray<FString> _FileContents, bool AllowOverwriting, FString FileDirectoryToLoadFrom)  const;

	//These are for saving each of the tables individually.
	UFUNCTION()
	void SaveJSONAssetsToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const;

	UFUNCTION()
	void SaveCurvetablesToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const;

	UFUNCTION()
	void SaveDataTablesToLocalDirectory(UJsonManagerDataAsset* ManagerDataAsset, FFileTypes FileTypes) const;

public:

	UFUNCTION()
	void CreateJSONDataAssetCollection(TMap<UJSONDataAssetBase*, FString> Collection);

	UFUNCTION()
	void CreateWaveDataTableCollection(TMap<UDataTable*, FString> Collection);

	UFUNCTION()
	void CreateAttributeTableCollection(TMap<UCurveTable*, FString> Collection);

public:

	UFUNCTION()
	void WaveProgressionDataFromJson();


public:

	TSharedPtr<FJsonObject> GetJsonFromString(const FString& jsonString);

	FString GetStringFromJson(TSharedRef<FJsonObject> jsonObject);

protected:

	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void BeginPlay() override;

};




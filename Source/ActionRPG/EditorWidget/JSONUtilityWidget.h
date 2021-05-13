// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONManager.h"
#include "EditorUtilityWidget.h"
#include "JSONUtilityWidget.generated.h"

/**
 * 
 */

UCLASS()
class ACTIONRPG_API UJSONUtilityWidget : public UEditorUtilityWidget
{
	GENERATED_BODY()

public:

	UJSONUtilityWidget();
	~UJSONUtilityWidget();


public:
	
	//Now do what you wanna do... 
	//Remember the IWYU model

	UFUNCTION(BlueprintCallable)
	void PushToJSON();

	UFUNCTION(BlueprintCallable)
	void PullFromJSON();

	UFUNCTION(BlueprintCallable)
	void SaveToLocal();

	UFUNCTION()
	void SaveToLocalDirectory(FString JSONOutputString, FString FileType, FString FileName, TArray<FString> _FileContents, bool AllowOverwriting, FString FileDirectoryToLoadFrom) const;
	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "")
	UJsonManagerDataAsset* ManagerData;


public:

	//Sets of Data to be saved

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
	TSet<UJSONDataAssetBase*> JsonDataAssets;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Wave Progression Data")
	TSet<UDataTable*> WaveProgressionData;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Curve Tables")
	TSet<UCurveTable*> CurveTables;

public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
	bool CanSaveToLocalDirectory;



	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JSON Output")
	FString JsonOutput;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JSON Input")
	FString JsonInput;

public:


	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "_Control JSON")
	TArray<FString> FileContents;


public:

	TSharedPtr<FJsonObject> GetJsonFromString(const FString& jsonString);

	FString GetStringFromJson(TSharedRef<FJsonObject> jsonObject);

};

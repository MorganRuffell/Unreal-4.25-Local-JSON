// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "JsonManagerDataAsset.generated.h"

/**
 * 
 */

struct FFileTypes;

UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API UJsonManagerDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	//The file name of the JSON String made by the JSON Data Assets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileName")
	FString JSONFileName = "DataAssetsJsonData";

	//The file name of the JSON String made by the JSON Data Assets
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileName")
	FString JSONDifficultyFileName = "DataAssetsDifficultyData";

	//The file name of the JSON String made by the Curve Tables of character data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileName")
	FString CurveJSONFileName = "DataAssetsCurveJsonData";

	//The file name of the JSON String made by the Curve Tables of character data
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileName")
	FString WaveJSONFileName = "WaveProgressionJSONData";

	//The directory (Local to the project) where these files are stored.
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileName")
	FString _directory = "JSONStrings";

	//Whether we are allowing overwriting
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "FileTypes")
	bool AllowOverwriting = true;

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSONDifficultySystem")
	bool UseJSONDifficultySystem;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSONDifficultySystem")
	int JSONDifficultyIndex;


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "WaveDataTables")
	TSet<UDataTable*> LocalWaveProgressionData;


public:

	UJsonManagerDataAsset();
	~UJsonManagerDataAsset();


public:
	
	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};



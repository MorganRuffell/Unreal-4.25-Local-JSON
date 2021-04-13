// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSONDataAssetBase.h"
#include "Dom/JsonObject.h"
#include "SaveGameDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FSaveSlots
{
	GENERATED_BODY()

	FString SlotOne = "Slot One";
	FString SlotTwo = "Slot Two";
	FString SlotThree = "Slot Three";
};

USTRUCT(BlueprintType)
struct FGameSavedData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save System Data")
	int SaveGameIndex;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save System Data")
	FString SaveSlotOne;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save System Data")
	FString SaveSlotTwo;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Save System Data")
	FString SaveSlotThree;
};

USTRUCT(BlueprintType)
struct FPlayerSavedData
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Save Data")
	FVector PlayerLocation;

};

UCLASS(BlueprintType)
class ACTIONRPG_API USaveGameDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:

	USaveGameDataAsset();
	~USaveGameDataAsset();

public:

	UPROPERTY()
	FSaveSlots SaveSlotsStruct;


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Player Data")
	FPlayerSavedData PlayerData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Game Data")
	FGameSavedData GameData;


	UPROPERTY(VisibleAnywhere, Category = "Game Data")
	double MaximumAmountofSaveGames;


public:
	
	void SetupSlots();

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

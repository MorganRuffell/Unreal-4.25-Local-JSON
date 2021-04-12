// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Containers/Map.h"
#include "GameFramework/Actor.h"
#include "DataAssets/JSONDataAssetBase.h"


//IWYU - Include what you use, JSON classes
#include "Serialization/JsonReader.h"
#include "Serialization/JsonWriter.h"
#include "Serialization/JsonSerializer.h"

#include "JSONManager.generated.h"

UCLASS(Blueprintable, BlueprintType)
class ACTIONRPG_API AJSONManager : public AActor
{
	GENERATED_BODY()

public:
	AJSONManager();

public:

// Fields for the new section that will allow me to prase multiple JSON Objects

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JSON Editor")
	FString JsonInput;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
	bool bFromJson;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
	bool bToJson;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON")
	TSet<UJSONDataAssetBase*> JsonDataAssets;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "JSON")
	FString JsonOutput;


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Inputs")
	TMap<UJSONDataAssetBase*, FString> ObjectsToJSON;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Outputs")
	TMap<UJSONDataAssetBase*, FString> ObjectsFromJSON;

public:

	TSharedPtr<FJsonObject> GetJsonFromString(const FString& jsonString);

	FString GetStringFromJson(TSharedRef<FJsonObject> jsonObject);

protected:


	virtual void PostEditChangeProperty(FPropertyChangedEvent& PropertyChangedEvent) override;

	virtual void BeginPlay() override;

};




// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "Misc/Paths.h"
#include "CoreMisc.h"
#include "Runtime/Core/Public/Misc/FileHelper.h"
#include "UTextFileManager.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API UUTextFileManager : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()
	
public:
	
	UFUNCTION(BlueprintCallable, Category = "File I/O")
	static FString LoadFileToString(FString SystemDesignData);

	//Saves the FString as a text array
	UFUNCTION(BlueprintCallable, Category = "ToLocal", meta = (Keywords = "Save"))
	static bool SaveArrayText(FString SaveDir, FString FileName, TArray<FString> SaveText, bool AllowOverwriting);

};





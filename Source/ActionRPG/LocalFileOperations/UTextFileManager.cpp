// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "UTextFileManager.h"


FString UUTextFileManager::LoadFileToString(FString SystemDesignData)
{
	FString directory = FPaths::ProjectDir();
	FString result;
	
	IPlatformFile& file = FPlatformFileManager::Get().GetPlatformFile();

	if (file.CreateDirectory(*directory))
	{
		FString myFile = directory + "/" + SystemDesignData;
		FFileHelper::LoadFileToString(result, *myFile);	
	}

	return result;
}

bool UUTextFileManager::SaveArrayText(FString SaveDir, FString FileName, TArray<FString> SaveText, bool AllowOverwriting = false)
{
	// Set complete file path
	SaveDir += "\\";
	SaveDir += FileName;

	if (!AllowOverwriting)
	{
		if (FPlatformFileManager::Get().GetPlatformFile().FileExists(*SaveDir))
		{
			return false;
		}
	}
	
	FString FinalString = "";
	for (FString& Each : SaveText)
	{
		FinalString += Each;
		FinalString += LINE_TERMINATOR;
	}
	
	return FFileHelper::SaveStringToFile(FinalString, *SaveDir);
}




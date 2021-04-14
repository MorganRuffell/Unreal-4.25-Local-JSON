// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "Misc/FileHelper.h"
#include "HAL/PlatformFilemanager.h"
#include "UTextFileManager.h"

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




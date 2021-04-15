// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "SaveGameDataAsset.h"

USaveGameDataAsset::USaveGameDataAsset()
{
	SetupSlots();
	
}

USaveGameDataAsset::~USaveGameDataAsset()
{

}

void USaveGameDataAsset::SetupSlots()
{
	GameData.SaveSlotOne = SaveSlotsStruct.SlotOne;
	GameData.SaveSlotTwo = SaveSlotsStruct.SlotTwo;
	GameData.SaveSlotThree = SaveSlotsStruct.SlotThree;
}


TSharedPtr<FJsonObject> USaveGameDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("SaveGameIndex", GameData.SaveGameIndex);
	jsonObject->SetStringField("SaveGameSlot1", GameData.SaveSlotOne);
	jsonObject->SetStringField("SaveGameSlot2", GameData.SaveSlotTwo);
	jsonObject->SetStringField("SaveGameSlot3", GameData.SaveSlotThree);

	
	return jsonObject;
}

bool USaveGameDataAsset::FromJson(FJsonObject& jsonObject)
{
	if (jsonObject.TryGetNumberField("SaveGameIndex",MaximumAmountofSaveGames) == true)
	{
		GameData.SaveGameIndex = jsonObject.GetNumberField("SaveGameIndex");
		GameData.SaveSlotOne = jsonObject.GetStringField("SaveGameSlot1");
		GameData.SaveSlotTwo = jsonObject.GetStringField("SaveGameSlot2");
		GameData.SaveSlotThree = jsonObject.GetStringField("SaveGameSlot3");

		return(true);
	}
	else
	{
		return(false);
	}
}






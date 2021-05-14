// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "GameStateDataAsset.h"

UGameStateDataAsset::UGameStateDataAsset()
{

}

UGameStateDataAsset::~UGameStateDataAsset()
{

}

TSharedPtr<FJsonObject> UGameStateDataAsset::ToJson()
{

	TSharedPtr<FJsonObject> JsonObject = MakeShared<FJsonObject>();

	if (JsonObject != nullptr)
	{
		JsonObject->SetBoolField("OnlyRelevantToOwner", NetworkDataStates.OnlyRelevantToOwner);
		JsonObject->SetBoolField("NetLoadOnClient", NetworkDataStates.NetLoadOnClient);
		JsonObject->SetBoolField("NetUseOwnerRelevancy", NetworkDataStates.NetUseOwnerRelevancy);
		JsonObject->SetBoolField("Replicates", NetworkDataStates.Replicates);
		JsonObject->SetNumberField("ServerWorldTimeUpdateFrequency", NetworkDataStates.ServerWorldTimeUpdateFrequency);

		JsonObject->SetNumberField("NetUpdateFrequency", NetworkUpdateFrequencies.NetUpdateFrequency);
		JsonObject->SetNumberField("MinNetUpdateFrequency", NetworkUpdateFrequencies.MinNetUpdateFrequency);
		JsonObject->SetNumberField("NetPriority", NetworkUpdateFrequencies.NetPriority);
	}

	return JsonObject;
}

bool UGameStateDataAsset::FromJson(FJsonObject& jsonObject)
{

	NetworkDataStates.OnlyRelevantToOwner = jsonObject.GetBoolField("OnlyRelevantToOwner");
	NetworkDataStates.NetLoadOnClient = jsonObject.GetBoolField("NetLoadOnClient");
	NetworkDataStates.NetUseOwnerRelevancy = jsonObject.GetBoolField("NetUseOwnerRelevancy");
	NetworkDataStates.Replicates = jsonObject.GetBoolField("Replicates");
	NetworkDataStates.ServerWorldTimeUpdateFrequency = jsonObject.GetNumberField("ServerWorldTimeUpdateFrequency");

	NetworkUpdateFrequencies.MinNetUpdateFrequency = jsonObject.GetNumberField("MinNetUpdateFrequency");
	NetworkUpdateFrequencies.NetPriority = jsonObject.GetNumberField("NetPriority");
	NetworkUpdateFrequencies.NetUpdateFrequency = jsonObject.GetNumberField("NetUpdateFrequency");
	
	return true;
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "AICDataAsset.h"

UAICDataAsset::UAICDataAsset()
{
}

UAICDataAsset::~UAICDataAsset()
{
}

TSharedPtr<FJsonObject> UAICDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("BehaviorTreeIndex", BehaviorTreeIndex);
	jsonObject->SetNumberField("BehaviorTreeIndexLower", BehaviorTreeIndexLower);
	jsonObject->SetNumberField("BehaviorTreeIndexUpper", BehaviorTreeIndexUpper);

	jsonObject->SetBoolField("UseRandomBehaviorTree", UseRandomBehaviorTree);

	return jsonObject;
}

bool UAICDataAsset::FromJson(FJsonObject& jsonObject)
{
	BehaviorTreeIndex = jsonObject.GetIntegerField("BehaviorTreeIndex");
	BehaviorTreeIndexUpper = jsonObject.GetIntegerField("BehaviorTreeIndexUpper");
	BehaviorTreeIndexLower = jsonObject.GetIntegerField("BehaviorTreeIndexLower");

	UseRandomBehaviorTree = jsonObject.GetBoolField("UseRandomBehaviorTree");

	return true;
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ParticleSystemDataAsset.h"

TSharedPtr<FJsonObject> UParticleSystemDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("_TimeDilation", TimeDilation);
	jsonObject->SetNumberField("_SecondsBeforeInactive",SecondsBeforeInactive);

	jsonObject->SetBoolField("UsingAbsoluteScale", AbsoluteScale);
	jsonObject->SetBoolField("AllowRecycling", AllowRecycling);
	jsonObject->SetBoolField("_ReturnMaterialOnMove", ReturnMaterialOnMove);

	return jsonObject;
}

bool UParticleSystemDataAsset::FromJson(FJsonObject& jsonObject)
{
	TimeDilation = jsonObject.GetNumberField("_TimeDilation");
	SecondsBeforeInactive = jsonObject.GetNumberField("_SecondsBeforeInactive");

	AbsoluteScale = jsonObject.GetBoolField("UsingAbsoluteScale");
	AllowRecycling = jsonObject.GetBoolField("AllowRecycling");
	ReturnMaterialOnMove = jsonObject.GetBoolField("_ReturnMaterialOnMove");

	return true;
}


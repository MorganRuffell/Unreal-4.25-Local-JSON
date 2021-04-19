// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ProjectileDataAsset.h"

UProjectileDataAsset::UProjectileDataAsset()
{

}

UProjectileDataAsset::~UProjectileDataAsset()
{

}

TSharedPtr<FJsonObject> UProjectileDataAsset::ToJson()
{
	TSharedPtr<FJsonObject> jsonObject = MakeShared<FJsonObject>();

	jsonObject->SetNumberField("UpperProjectileDamage", UpperAttackDamage);
	jsonObject->SetNumberField("LowerProjectileDamage", LowerAttackDamage);

	return jsonObject;
}

bool UProjectileDataAsset::FromJson(FJsonObject& jsonObject)
{
	UpperAttackDamage = jsonObject.GetNumberField("UpperProjectileDamage");
	LowerAttackDamage = jsonObject.GetNumberField("LowerProjectileDamage");

	return true;
}

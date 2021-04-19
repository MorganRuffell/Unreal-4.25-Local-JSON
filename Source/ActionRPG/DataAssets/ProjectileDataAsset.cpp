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

	jsonObject->SetNumberField("Projectile Damage", AttackDamage);

	return jsonObject;
}

bool UProjectileDataAsset::FromJson(FJsonObject& jsonObject)
{
	AttackDamage = jsonObject.GetNumberField("Projectile Damage");

	return true;
}

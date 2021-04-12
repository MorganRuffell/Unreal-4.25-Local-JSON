// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/RPGItem.h"
#include "RPGWeaponItem.generated.h"

/** Native structure for weapons*/
USTRUCT(BlueprintType)
struct ACTIONRPG_API FRPGWeaponItemStruct : public FRPGItemStruct
{
	GENERATED_BODY()

public:
	/** Constructor */
	FRPGWeaponItemStruct()
		: FRPGItemStruct()
	{
		ItemType = ERPGItemType::Weapon;
	}

	/** Weapon actor to spawn */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Weapon)
	TSubclassOf<AActor> WeaponActor;
};
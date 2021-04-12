// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/RPGItem.h"
#include "RPGPotionItem.generated.h"

/** Native structure for potions*/
USTRUCT(BlueprintType)
struct ACTIONRPG_API FRPGPotionItemStruct : public FRPGItemStruct
{
	GENERATED_BODY()

public:
	/** Constructor */
	FRPGPotionItemStruct()
		: FRPGItemStruct()			
	{
		ItemType = ERPGItemType::Potion;
	}
};
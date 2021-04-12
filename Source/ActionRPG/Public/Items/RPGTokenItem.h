// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/RPGItem.h"
#include "RPGTokenItem.generated.h"

/** Native structure for tokens*/
USTRUCT(BlueprintType)
struct ACTIONRPG_API FRPGTokenItemStruct : public FRPGItemStruct
{
	GENERATED_BODY()

public:
	/** Constructor */
	FRPGTokenItemStruct()
		: FRPGItemStruct()
	{
		ItemType = ERPGItemType::Token;
		MaxCount = 0; // Infinite
	}
};
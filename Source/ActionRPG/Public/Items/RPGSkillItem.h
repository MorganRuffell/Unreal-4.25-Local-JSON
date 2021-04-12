// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "Items/RPGItem.h"
#include "RPGSkillItem.generated.h"

/** Native structure for skills*/
USTRUCT(BlueprintType)
struct ACTIONRPG_API FRPGSkillItemStruct : public FRPGItemStruct
{
	GENERATED_BODY()

public:
	/** Constructor */
	FRPGSkillItemStruct()
		: FRPGItemStruct()
	{
		ItemType = ERPGItemType::Skill;
	}
};
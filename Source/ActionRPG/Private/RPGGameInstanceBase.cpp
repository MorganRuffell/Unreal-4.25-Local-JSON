// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "RPGGameInstanceBase.h"
#include "Items/RPGItem.h"
#include "Kismet/GameplayStatics.h"

// LA -
// Prevents code optimisation which is useful for stepping through as it means
// each line accurately matches where we are in execution
// Although it MUST be turned back on at the end of the file
// See: https://docs.microsoft.com/en-us/cpp/preprocessor/optimize?view=msvc-160
#pragma optimize("", off)

URPGGameInstanceBase::URPGGameInstanceBase()
{}

bool URPGGameInstanceBase::ItemExists(FString ItemKey, ERPGItemType ItemType) const
{
	switch (ItemType)
	{
	case ERPGItemType::Potion:
		return Potions.Contains(ItemKey);
	case ERPGItemType::Skill:
		return Skills.Contains(ItemKey);
	case ERPGItemType::Token:
		return Tokens.Contains(ItemKey);
	case ERPGItemType::Weapon:
		return Weapons.Contains(ItemKey);
	}
	return false;
}

bool URPGGameInstanceBase::TryGetPotion(FString PotionKey, FRPGPotionItemStruct& outPotion) const
{
	const FRPGPotionItemStruct* ptr = Potions.Find(PotionKey);
	if (ptr != nullptr)
	{
		outPotion = *ptr;
		return true;
	}
	outPotion = FRPGPotionItemStruct();
	return false;
}

FRPGPotionItemStruct URPGGameInstanceBase::GetPotion(FString PotionKey) const
{
	const FRPGPotionItemStruct* ptr = Potions.Find(PotionKey);
	if (ptr != nullptr)
	{
		return *ptr;
	}
	return FRPGPotionItemStruct();
}

bool URPGGameInstanceBase::TryGetSkill(FString SkillKey, FRPGSkillItemStruct& outSkill) const
{
	const FRPGSkillItemStruct* ptr = Skills.Find(SkillKey);
	if (ptr != nullptr)
	{
		outSkill = *ptr;
		return true;
	}
	outSkill = FRPGSkillItemStruct();
	return false;
}

FRPGSkillItemStruct URPGGameInstanceBase::GetSkill(FString SkillKey) const
{
	const FRPGSkillItemStruct* ptr = Skills.Find(SkillKey);
	if (ptr != nullptr)
	{
		return *ptr;
	}
	return FRPGSkillItemStruct();
}

bool URPGGameInstanceBase::TryGetToken(FString TokenKey, FRPGTokenItemStruct& outToken) const
{
	const FRPGTokenItemStruct* ptr = Tokens.Find(TokenKey);
	if (ptr != nullptr)
	{
		outToken = *ptr;
		return true;
	}
	outToken = FRPGTokenItemStruct();
	return false;
}

FRPGTokenItemStruct URPGGameInstanceBase::GetToken(FString TokenKey) const
{
	const FRPGTokenItemStruct* ptr = Tokens.Find(TokenKey);
	if (ptr != nullptr)
	{
		return *ptr;
	}
	return FRPGTokenItemStruct();
}

bool URPGGameInstanceBase::TryGetWeapon(FString WeaponKey, FRPGWeaponItemStruct& outWeapon) const
{
	const FRPGWeaponItemStruct* ptr = Weapons.Find(WeaponKey);
	if (ptr != nullptr)
	{
		outWeapon = *ptr;
		return true;
	}
	outWeapon = FRPGWeaponItemStruct();
	return false;
}

FRPGWeaponItemStruct URPGGameInstanceBase::GetWeapon(FString WeaponKey) const
{
	const FRPGWeaponItemStruct* ptr = Weapons.Find(WeaponKey);
	if (ptr != nullptr)
	{
		return *ptr;
	}
	return FRPGWeaponItemStruct();
}

bool URPGGameInstanceBase::TryGetBaseItemData(FString ItemKey, ERPGItemType ItemType, FRPGItemStruct& outItem) const
{
	switch (ItemType)
	{
	case ERPGItemType::Potion:
	{
		FRPGItemStruct* ptr = (FRPGItemStruct*)Potions.Find(ItemKey);
		if (ptr != nullptr) outItem = *ptr;
		return ptr != nullptr;
	}		
	case ERPGItemType::Skill:
	{
		FRPGItemStruct* ptr = (FRPGItemStruct*)Skills.Find(ItemKey);
		if (ptr != nullptr) outItem = *ptr;
		return ptr != nullptr;
	}
	case ERPGItemType::Token:
	{
		FRPGItemStruct* ptr = (FRPGItemStruct*)Tokens.Find(ItemKey);
		if (ptr != nullptr) outItem = *ptr;
		return ptr != nullptr;
	}
	case ERPGItemType::Weapon:
	{
		FRPGItemStruct* ptr = (FRPGItemStruct*)Weapons.Find(ItemKey);
		if (ptr != nullptr) outItem = *ptr;
		return ptr != nullptr;
	}
	case ERPGItemType::Undefined:
		ERPGItemType itemType;
		bool found = FindItem(ItemKey, itemType, outItem);
		return found;
	}
	outItem = FRPGItemStruct();
	return false;
}

FRPGItemStruct URPGGameInstanceBase::GetBaseItemData(FString ItemKey, ERPGItemType ItemType) const
{
	switch (ItemType)
	{
	case ERPGItemType::Potion:
	{
		FRPGItemStruct* ptr = (FRPGItemStruct*)Potions.Find(ItemKey);
		if (ptr != nullptr) return *ptr;
		else return FRPGItemStruct();
	}
	case ERPGItemType::Skill:
	{
		FRPGItemStruct* ptr = (FRPGItemStruct*)Skills.Find(ItemKey);
		if (ptr != nullptr) return *ptr;
		else return FRPGItemStruct();
	}
	case ERPGItemType::Token:
	{
		FRPGItemStruct* ptr = (FRPGItemStruct*)Tokens.Find(ItemKey);
		if (ptr != nullptr) return *ptr;
		else return FRPGItemStruct();
	}
	case ERPGItemType::Weapon:
	{
		FRPGItemStruct* ptr = (FRPGItemStruct*)Weapons.Find(ItemKey);
		if (ptr != nullptr) return *ptr;
		else return FRPGItemStruct();
	}
	case ERPGItemType::Undefined:
	{
		ERPGItemType itemType;
		FRPGItemStruct itemData;
		FindItem(ItemKey, itemType, itemData);
		return itemData;
	}
	}
	return FRPGItemStruct();
}

bool URPGGameInstanceBase::FindItem(FString ItemKey, ERPGItemType& OutItemType, FRPGItemStruct& OutItemData) const
{
	FRPGItemStruct* ptr = (FRPGItemStruct*)Potions.Find(ItemKey);
	if (ptr != nullptr)
	{
		OutItemType = ERPGItemType::Potion;
		OutItemData = *ptr;
		return true;
	}
	ptr = (FRPGItemStruct*)Skills.Find(ItemKey);
	if (ptr != nullptr)
	{
		OutItemType = ERPGItemType::Skill;
		OutItemData = *ptr;
		return true;
	}
	ptr = (FRPGItemStruct*)Tokens.Find(ItemKey);
	if (ptr != nullptr)
	{
		OutItemType = ERPGItemType::Token;
		OutItemData = *ptr;
		return true;
	}
	ptr = (FRPGItemStruct*)Weapons.Find(ItemKey);
	if (ptr != nullptr)
	{
		OutItemType = ERPGItemType::Weapon;
		OutItemData = *ptr;
		return true;
	}
	OutItemType = ERPGItemType::Undefined;
	OutItemData = FRPGItemStruct();
	return false;
}

void URPGGameInstanceBase::GetItemsBaseInfo(ERPGItemType ItemType, TMap<FString, FRPGItemStruct>& OutItems) const
{
	OutItems = TMap<FString, FRPGItemStruct>();
	switch (ItemType)
	{
	case ERPGItemType::Potion:
	{
		for (TPair<FString, FRPGPotionItemStruct> pair : Potions)
		{
			OutItems.Add(pair.Key, (FRPGItemStruct)pair.Value);
		}
		break;
	}
	case ERPGItemType::Skill:
	{
		for (TPair<FString, FRPGSkillItemStruct> pair : Skills)
		{
			OutItems.Add(pair.Key, (FRPGItemStruct)pair.Value);
		}
		break;
	}
	case ERPGItemType::Token:
	{
		for (TPair<FString, FRPGTokenItemStruct> pair : Tokens)
		{
			OutItems.Add(pair.Key, (FRPGItemStruct)pair.Value);
		}
		break;
	}
	case ERPGItemType::Weapon:
	{
		for (TPair<FString, FRPGWeaponItemStruct> pair : Weapons)
		{
			OutItems.Add(pair.Key, (FRPGItemStruct)pair.Value);
		}
		break;
	}
	case ERPGItemType::Undefined:
	{
		for (TPair<FString, FRPGPotionItemStruct> pair : Potions)
		{
			OutItems.Add(pair.Key, (FRPGItemStruct)pair.Value);
		}
		for (TPair<FString, FRPGSkillItemStruct> pair : Skills)
		{
			OutItems.Add(pair.Key, (FRPGItemStruct)pair.Value);
		}
		for (TPair<FString, FRPGTokenItemStruct> pair : Tokens)
		{
			OutItems.Add(pair.Key, (FRPGItemStruct)pair.Value);
		}
		for (TPair<FString, FRPGWeaponItemStruct> pair : Weapons)
		{
			OutItems.Add(pair.Key, (FRPGItemStruct)pair.Value);
		}
		break;
	}
	}
}

bool URPGGameInstanceBase::IsValidItemSlot(FRPGItemSlot ItemSlot) const
{
	if (ItemSlot.IsValid())
	{
		const int32* FoundCount = SlotsPerItemType.Find(ItemSlot.ItemType);

		if (FoundCount)
		{
			return ItemSlot.SlotNumber < *FoundCount;
		}
	}
	return false;
}

void URPGGameInstanceBase::Init()
{
	Super::Init();
}

#pragma optimize("", on)
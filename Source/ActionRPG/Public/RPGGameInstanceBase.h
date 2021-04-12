// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "ActionRPG.h"

#include "Items/RPGItem.h"

#include "Items/RPGPotionItem.h"
#include "Items/RPGSkillItem.h"
#include "Items/RPGTokenItem.h"
#include "Items/RPGWeaponItem.h"

#include "Engine/GameInstance.h"
#include "RPGGameInstanceBase.generated.h"

class URPGItem;
class URPGSaveGame;

/**
 * Base class for GameInstance, should be blueprinted
 * Most games will need to make a game-specific subclass of GameInstance
 * Once you make a blueprint subclass of your native subclass you will want to set it to be the default in project settings
 */
UCLASS()
class ACTIONRPG_API URPGGameInstanceBase : public UGameInstance
{
	GENERATED_BODY()
public:
	// Constructor
	URPGGameInstanceBase();		

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<FString, FRPGPotionItemStruct> Potions;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<FString, FRPGSkillItemStruct> Skills;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<FString, FRPGTokenItemStruct> Tokens;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<FString, FRPGWeaponItemStruct> Weapons;

	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory)
	TMap<FString, FRPGItemData> DefaultInventoryItems;

	/** Number of slots for each type of item */
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = Inventory, DisplayName = "Item Slots Per Type")
	TMap<ERPGItemType, int32> SlotsPerItemType;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool ItemExists(FString ItemKey, ERPGItemType ItemType) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool TryGetPotion(FString PotionKey, FRPGPotionItemStruct& outPotion) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	FRPGPotionItemStruct GetPotion(FString PotionKey) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool TryGetSkill(FString SkillKey, FRPGSkillItemStruct& outSkill) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	FRPGSkillItemStruct GetSkill(FString SkillKey) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool TryGetToken(FString TokenKey, FRPGTokenItemStruct& outToken) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	FRPGTokenItemStruct GetToken(FString TokenKey) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool TryGetWeapon(FString WeaponKey, FRPGWeaponItemStruct& outWeapon) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	FRPGWeaponItemStruct GetWeapon(FString WeaponKey) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool TryGetBaseItemData(FString ItemKey, ERPGItemType ItemType, FRPGItemStruct& outItem) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	FRPGItemStruct GetBaseItemData(FString ItemKey, ERPGItemType ItemType) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool FindItem(FString ItemKey, ERPGItemType& OutItemType, FRPGItemStruct& OutItemData) const;

	UFUNCTION(BlueprintCallable, Category = Inventory)
	void GetItemsBaseInfo(ERPGItemType ItemType, TMap<FString, FRPGItemStruct>& OutItems) const;

	/** Returns true if this is a valid inventory slot */
	UFUNCTION(BlueprintCallable, Category = Inventory)
	bool IsValidItemSlot(FRPGItemSlot ItemSlot) const;	

	virtual void Init() override;
};
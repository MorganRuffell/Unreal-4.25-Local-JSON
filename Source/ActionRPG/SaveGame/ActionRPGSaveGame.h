// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Abilities/RPGAttributeSet.h"
#include "AbilitySystemComponent.h"
#include "Abilities/RPGGameplayAbility.h"
#include "GameFramework/SaveGame.h"
#include "ActionRPGSaveGame.generated.h"

USTRUCT(BlueprintType)
struct FCharacterStats
{
	GENERATED_BODY()

//	Section for character attributes and Data

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterLevelData)
	int32 CharacterLevel;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterLevelData)
	int32 CharacterLevelSaved;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterAttrData)
	float PlayerCurrentHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterAttrData)
	float PlayerMaxHealth;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterAttrData)
	float PlayerMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterAttrData)
	float PlayerMaxMana;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack&DefensePower")
	float PlayerAttackPower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterAttrData)
	float PlayerDefensePower;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterAttrData)
	FGameplayAttributeData MoveSpeed;


//Section for gameplay abilities

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterGameplayAbilities)
	TArray<TSubclassOf<URPGGameplayAbility>> GameplayAbilities;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = CharacterGameplayAbilities)
	TMap<FRPGItemSlot, FGameplayAbilitySpecHandle> SlottedAbilities;

// Section for the players (F)transform

	UPROPERTY(EditAnywhere, Category = PlayerLocation)
	FVector PlayerLocation;
	
	UPROPERTY(EditAnywhere, Category = PlayerLocation)
	FRotator PlayerRotation;

};

UCLASS()
class ACTIONRPG_API UActionRPGSaveGame : public USaveGame
{	
	GENERATED_BODY()
	
	
public:	

	UActionRPGSaveGame();
	~UActionRPGSaveGame();


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	FString PlayerName;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	int UserIndex;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Basic)
	FCharacterStats CharacterData;

};

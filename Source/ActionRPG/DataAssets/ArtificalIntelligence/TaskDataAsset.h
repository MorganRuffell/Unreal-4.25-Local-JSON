// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "TaskDataAsset.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FAttackMelee
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Melee Attack Delay")
	float MeleeAttackDelay;
};

USTRUCT(BlueprintType)
struct FAttackSkill
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Skill Delay")
	float SkillAttackDelay;
};

USTRUCT(BlueprintType)
struct FGoAroundTarget
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Go Around Target")
	float RadiusRange;
};

USTRUCT(BlueprintType)
struct FTargetSurrounded
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Surrounders")
	float AcceptableDistance;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Surroundeder")
	int minSurrounders = 0;
};

USTRUCT(BlueprintType)
struct FStopAndRotate
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Surrounders")
	bool bTeleportPhysics = false;

};

UCLASS(BlueprintType)
class ACTIONRPG_API UTaskDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UTaskDataAsset();
	~UTaskDataAsset();
	

public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Melee Task")
	FAttackMelee MeleeAttackData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attack Skill")
	FAttackSkill AttackSkillData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Go Around Target Task")
	FGoAroundTarget GoAroundTargetTaskData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Target Surround Data")
	FTargetSurrounded TargetSurroundedData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Stop and Rotate Data")
	FStopAndRotate StopAndRotateData;


public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

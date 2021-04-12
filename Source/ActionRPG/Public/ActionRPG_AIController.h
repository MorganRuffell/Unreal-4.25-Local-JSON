// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/ArtificalIntelligence/AICDataAsset.h"
#include "AIController.h"
#include "ActionRPG_AIController.generated.h"

/**
 * 
 */

UCLASS(BlueprintType)
class ACTIONRPG_API AActionRPG_AIController : public AAIController
{
	GENERATED_BODY()

public:
	
	AActionRPG_AIController();
	~AActionRPG_AIController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data Assets")
	UAICDataAsset* DataAsset;

};

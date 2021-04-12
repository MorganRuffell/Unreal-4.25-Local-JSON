// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/AnimationNotify/AnimationNotifyStateDataAsset.h"
#include "Animation/AnimNotifies/AnimNotify.h"
#include "ActionRPGAnimNotify.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API UActionRPGAnimNotify : public UAnimNotify
{
	GENERATED_BODY()

public:
	
	UActionRPGAnimNotify();
	~UActionRPGAnimNotify();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "AnimNotifyDataAsset")
	UAnimationNotifyStateDataAsset* AnimationNotifyDataAsset;


};

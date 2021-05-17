// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/AmbientSoundDataAsset.h"
#include "Sound/AmbientSound.h"
#include "ARPGAmbientSound.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API AARPGAmbientSound : public AAmbientSound
{
	GENERATED_BODY()
	
public:

	AARPGAmbientSound();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Data")
	UAmbientSoundDataAsset* AmbientSoundData;




};

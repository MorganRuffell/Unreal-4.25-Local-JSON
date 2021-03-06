// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/JSON/JSONDataAssetBase.h"
#include "AmbientSoundDataAsset.generated.h"

/**
 * 
 */
UCLASS()
class ACTIONRPG_API UAmbientSoundDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()
	
public:

	UAmbientSoundDataAsset();


	/** If true, this sound will not be stopped when flushing the audio device. */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
	int bIgnoreForFlushing = 1;

	/** Whether to artificially prioritize the component to play */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
	int bAlwaysPlay = 1;

	/** Whether or not this audio component is a music clip */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
	int bIsMusic = 1;


public:


	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Modulation)
	float PitchModulationMin;

	/** The upper bound to use when randomly determining a pitch multiplier */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Modulation)
	float PitchModulationMax;

	/** The lower bound to use when randomly determining a volume multiplier */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Modulation)
	float VolumeModulationMin;

	/** The upper bound to use when randomly determining a volume multiplier */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Modulation)
	float VolumeModulationMax;

	/** A volume multiplier to apply to sounds generated by this component */
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound)
	float VolumeMultiplier;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = Sound, meta = (ClampMin = "0.0", UIMin = "0.0", EditCondition = "bOverridePriority"))
	float Priority;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};

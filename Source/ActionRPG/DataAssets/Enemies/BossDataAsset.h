// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Animation/AnimMontage.h"
#include "DataAssets/JSONDataAssetBase.h"
#include "BossDataAsset.generated.h"
/**
 * 
 */

USTRUCT(BlueprintType)
struct FAnimationSpeeds
{
	GENERATED_BODY()

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float normal = 1.0f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Half = 0.5f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Quarter = 0.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Faster = 1.25f;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
	float Fastest = 1.5f;
};

UCLASS(BlueprintType)
class ACTIONRPG_API UBossDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:

	UBossDataAsset();
	~UBossDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Attributes")
	float DeathDelayTime;

	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Attributes")
	int AnimMontageSelection;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadWrite, Category = "Animation")
	FAnimationSpeeds AnimationSpeed;

	//Animation Montages

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* SpiderAnimationMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Animation")
	UAnimMontage* SpiderHitAnimationMontage;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

public:

	void ToJsonAnimationSpeeds(TSharedPtr<FJsonObject*> jsonObject);
	void FromJsonAnimationSpeeds();

};






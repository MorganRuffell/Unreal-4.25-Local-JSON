// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"

//We are no longer building this on a UDatAsset now they are on a JSON data asset
#include "DataAssets/JSON/JSONDataAssetBase.h"

#include "BehaviorTree/BlackboardData.h"
#include "BehaviorTree/BehaviorTree.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "AICDataAsset.generated.h"

/**
 *
 */
UCLASS(BlueprintType)
class ACTIONRPG_API UAICDataAsset : public UJSONDataAssetBase
{
	GENERATED_BODY()

public:

	UAICDataAsset();
	~UAICDataAsset();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Artifical Intelligence")
	TSet<UBehaviorTree*> Behaviour_tree;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Artifical Intelligence")
	class UBlackboardData* BlackboardData;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Artifical Intelligence")
	class UBlackboardComponent* blackboardComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Artifical Intelligence")
	int BehaviorTreeIndex = 0;

public:

	virtual TSharedPtr<FJsonObject> ToJson() override;

	virtual bool FromJson(FJsonObject& jsonObject) override;

};
 
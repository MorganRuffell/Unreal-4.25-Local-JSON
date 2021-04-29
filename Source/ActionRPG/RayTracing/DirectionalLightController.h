// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "DataAssets/DirectionalLightData.h"
#include "Engine/DirectionalLight.h"
#include "GameFramework/Actor.h"
#include "DirectionalLightController.generated.h"

UCLASS()
class ACTIONRPG_API ADirectionalLightController : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ADirectionalLightController();

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
	UDirectionalLightComponent* _DirectionalLightComponent;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "Light")
	UDirectionalLightData* DirectionalLightData;


protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Engine/SphereReflectionCapture.h"
#include "DataAssets/Effects/ReflectionCaptureDataAsset.h"
#include "ARPGSphereReflectionCapture.generated.h"

/**
 * 
 */

//Taking standard syntax that only you know what it is, stereotypically macros are not good things. 
//They hide a lot of functionality. 
// #define CAKE = &;

UCLASS()
class ACTIONRPG_API AARPGSphereReflectionCapture : public ASphereReflectionCapture
{
	GENERATED_BODY()
	
public:

	AARPGSphereReflectionCapture();

	void BeginPlay() override;


public:

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "JSON Data")
	UReflectionCaptureDataAsset* ReflectionCaptureData; 

	/** Sphere component used to visualize the capture radius */
	UPROPERTY()
	UDrawSphereComponent* _DrawCaptureRadius;

public:

#if WITH_EDITOR
	//~ Begin AActor Interface.
	virtual void EditorApplyScale(const FVector& DeltaScale, const FVector* PivotLocation, bool bAltDown, bool bShiftDown, bool bCtrlDown) override;
	//~ End AActor Interface.
#endif

};

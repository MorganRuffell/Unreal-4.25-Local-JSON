// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "RaytracingController.h"

// Sets default values
ARaytracingController::ARaytracingController()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void ARaytracingController::BeginPlay()
{
	Super::BeginPlay();
	RaytracingSystem->bEnabled = true;
	GetJSONDataAssetData();
}

// Called every frame
void ARaytracingController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

bool ARaytracingController::GetJSONDataAssetData()
{
	if (RaytracingSystem->bEnabled == true)
	{
		RaytracingData->Intensity = RaytracingSystem->Settings.AmbientOcclusionIntensity;
		RaytracingData->Radius = RaytracingSystem->Settings.AmbientOcclusionRadius;
		RaytracingData->IsEnabled = RaytracingSystem->Settings.RayTracingAO;
		RaytracingData->SamplesPerPixelAO = RaytracingSystem->Settings.RayTracingAOSamplesPerPixel;
		RaytracingData->MaxRoughness = RaytracingSystem->Settings.bOverride_RayTracingReflectionsMaxRoughness;
		RaytracingData->MaxBounces = RaytracingSystem->Settings.PathTracingMaxBounces;
		RaytracingData->SamplesPerPixel = RaytracingSystem->Settings.PathTracingSamplesPerPixel;
		RaytracingData->CanUseRefractions = RaytracingSystem->Settings.bOverride_RayTracingReflectionsTranslucency;
		
		return true;
	}
	else
	{
		return false;
	}
}


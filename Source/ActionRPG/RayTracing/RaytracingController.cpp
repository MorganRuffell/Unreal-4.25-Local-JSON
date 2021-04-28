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
	

	GetJSONDataAssetData();


}

// Called every frame
void ARaytracingController::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

bool ARaytracingController::GetJSONDataAssetData()
{
	
	

	throw std::logic_error("The method or operation is not implemented.");
}

//bool ARaytracingController::GetJSONDataAssetData(UJSONDataAssetBase DataAsset)
//{
//	throw std::logic_error("The method or operation is not implemented.");
//}


// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ARPGSoul.h"

// Sets default values
AARPGSoul::AARPGSoul()
{
	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AARPGSoul::BeginPlay()
{
	Super::BeginPlay();

	ResolveSoftObject();
}

void AARPGSoul::ResolveSoftObject()
{
	FTimerHandle TimerHandle;
	FStreamableManager UnloadingManager;
	FSoftObjectPath SoulDataPath = SoulSoftDataAsset.ToSoftObjectPath();

	TSharedPtr<FStreamableHandle> Handle;


	UnloadingManager.RequestAsyncLoad(SoulDataPath, [=]() {

		UObject* ResolvedSoulData = SoulDataPath.ResolveObject();
		USoulDataAsset* SoulData = Cast<USoulDataAsset>(ResolvedSoulData);

		if (SoulData == nullptr) { return; }

		Min = SoulData->DelayValuesData.DelayCeiling;
		Max = SoulData->DelayValuesData.DelayFloor;
	});

	Final = FMath::RandRange(Min, Max);

	GetWorldTimerManager().SetTimer(TimerHandle,this,&AARPGSoul::PostDelay,Final);
}

void AARPGSoul::PostDelay()
{
	SoulCollider->SetSimulatePhysics(CanSimulatePhysics);
	InitalActorLocation = GetActorLocation();
}

// Called every frame
void AARPGSoul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}


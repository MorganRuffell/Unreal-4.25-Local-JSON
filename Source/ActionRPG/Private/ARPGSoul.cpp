// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ARPGSoul.h"



// Sets default values
AARPGSoul::AARPGSoul()
{
	PrimaryActorTick.bCanEverTick = true;

	SoulShape = CreateDefaultSubobject<USphereComponent>(TEXT("Sphere Collider"));
	SummonParticleSystem = CreateDefaultSubobject<UParticleSystemComponent>(TEXT("ParticleSystem"));

	Timeline = CreateDefaultSubobject<UTimelineComponent>(TEXT("Movement Timeline"));
	InterpFunction.BindUFunction(this, FName("TimelineFloatReturn"));
	TimelineFinished.BindUFunction(this, FName("OnTimelineFinished"));
}

// Called every frame
void AARPGSoul::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (Timeline != nullptr)
	{
		Timeline->TickComponent(DeltaTime, ELevelTick::LEVELTICK_TimeOnly, NULL);
	}

}


// Called when the game starts or when spawned
void AARPGSoul::BeginPlay()
{
	Super::BeginPlay();

	if (fSoulCurve != nullptr)
	{
		Timeline->AddInterpFloat(fSoulCurve, InterpFunction, FName("Alpha"));
		Timeline->SetTimelineFinishedFunc(TimelineFinished);

		Timeline->SetLooping(false);
		Timeline->SetIgnoreTimeDilation(false);
	}
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
	GetWorldTimerManager().SetTimer(TimerHandle, this, &AARPGSoul::PostDelay, Final);
	Timeline->Play();
}

void AARPGSoul::TimelineFloatReturn(float value)
{
	Container = GetWorld()->GetFirstPlayerController()->GetPawn()->GetActorLocation();
	Container = FMath::Lerp(InitalActorLocation, Container, 0);
}

void AARPGSoul::OnTimelineFinished()
{
	
}

void AARPGSoul::FinishCollectItem()
{

}

void AARPGSoul::PostDelay()
{
	SoulShape->SetSimulatePhysics(CanSimulatePhysics);
	InitalActorLocation = GetActorLocation();
}


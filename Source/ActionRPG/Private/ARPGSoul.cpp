// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ARPGSoul.h"


// Sets default values
AARPGSoul::AARPGSoul()
{
	static ConstructorHelpers::FObjectFinder<UCurveFloat> Curve(TEXT("/Game/Curves/C_MyCurve"));

	PrimaryActorTick.bCanEverTick = true;

	SoulCurve = Curve.Object;
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

	if (SoulCurve != nullptr)
	{
		FOnTimelineFloat TimelineCallback;
		FOnTimelineEventStatic TimelineFinishedCallback;


		Timeline = NewObject<UTimelineComponent>(this, FName("TimelineAnimation"));
		Timeline->CreationMethod = EComponentCreationMethod::UserConstructionScript;
		this->BlueprintCreatedComponents.Add(Timeline);

		Timeline->SetPropertySetObject(this);
		Timeline->SetDirectionPropertyName(FName("TimeLineDirection"));
		Timeline->SetLooping(CanLoop);
		Timeline->SetTimelineLength(TimelineDuration);
		Timeline->SetTimelineLengthMode(ETimelineLengthMode::TL_LastKeyFrame);
		Timeline->SetPlaybackPosition(0.0f, false, false);
		Timeline->AddInterpFloat(SoulCurve, TimelineCallback);


		TimelineCallback.BindUFunction(this, FName("PlayTimeline"));
		TimelineFinishedCallback.BindUFunction(this, FName{ TEXT("SetState") });

		Timeline->RegisterComponent();
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
}

void AARPGSoul::PlayTimeline()
{
	if (true)
	{

	}

}

void AARPGSoul::PostDelay()
{
	SoulCollider->SetSimulatePhysics(CanSimulatePhysics);
	InitalActorLocation = GetActorLocation();




}


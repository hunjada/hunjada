// Fill out your copyright notice in the Description page of Project Settings.

#include "OpenDoor.h"
#include "Engine/World.h"



// Sets default values for this component's properties
UOpenDoor::UOpenDoor()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UOpenDoor::BeginPlay()
{
	Super::BeginPlay();

	// ...
	Owner = GetOwner();	

	pUserActor = GetWorld()->GetFirstPlayerController()->GetPawn();

	
}


// Called every frame
void UOpenDoor::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...

	if (pTriggerVolume->IsOverlappingActor(pUserActor))
	{
		OpenDoor();
		LastOpenDoor = GetWorld()->GetTimeSeconds();
	}
	
	if( GetWorld()->GetTimeSeconds() - LastOpenDoor > CloseDelayTime)
	{
		CloseDoor();
	}
}


void UOpenDoor::OpenDoor()
{		
	check(Owner);
	Owner->SetActorRotation(FRotator(0.f, OpenAngle, 0.f));
}


void UOpenDoor::CloseDoor()
{
	
	check(Owner);
	Owner->SetActorRotation(FRotator(0.f, 0.f, 0.f));
}
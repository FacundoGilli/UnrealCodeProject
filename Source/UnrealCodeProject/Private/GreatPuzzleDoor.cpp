// Fill out your copyright notice in the Description page of Project Settings.


#include "GreatPuzzleDoor.h"

// Sets default values
AGreatPuzzleDoor::AGreatPuzzleDoor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	DoorRight = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorRight"));
	RootComponent = DoorRight;

	DoorLeft = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("DoorLeft"));
	RootComponent = DoorLeft;

	TargetPitch = 50;

}

void AGreatPuzzleDoor::Interact_Implementation(APawn* CharacterPawn)
{
	IGameplayinterface::Interact_Implementation(CharacterPawn);
	DoorRight->SetRelativeLocation(FVector(TargetPitch, 0, 0));
	DoorLeft->SetRelativeLocation(FVector(-TargetPitch, 0, 0));
	
}



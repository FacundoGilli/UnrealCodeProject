// Fill out your copyright notice in the Description page of Project Settings.


#include "ItemChest.h"



// Sets default values
AItemChest::AItemChest()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	BaseMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("BaseMesh"));
	RootComponent = BaseMesh;

	OpenMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("OpenMesh"));
	OpenMesh ->SetupAttachment(BaseMesh);

	TargetPitch = 110;
}

void AItemChest::Interact_Implementation(APawn* CharacterPawn)
{
	IGameplayinterface::Interact_Implementation(CharacterPawn);
	OpenMesh->SetRelativeRotation(FRotator(TargetPitch,0,0));
}


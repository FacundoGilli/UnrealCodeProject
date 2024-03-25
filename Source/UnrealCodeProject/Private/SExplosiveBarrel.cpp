// Fill out your copyright notice in the Description page of Project Settings.


#include "SExplosiveBarrel.h"
#include "PhysicsEngine/RadialForceComponent.h"
#include "GameFramework/Actor.h"
#include "Components/StaticMeshComponent.h"
#include "Math/UnitConversion.h"
// Sets default values
ASExplosiveBarrel::ASExplosiveBarrel()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;
	BarrelMesh = CreateDefaultSubobject<UStaticMeshComponent>("BarrelMesh");
	RootComponent = BarrelMesh;
	BarrelMesh->SetSimulatePhysics(true);

	Explosion = CreateDefaultSubobject<URadialForceComponent>("Explosion");
	Explosion->SetupAttachment(BarrelMesh);

	Explosion->Radius = 750.0f;
	Explosion->ImpulseStrength = 2500.0f;
	Explosion->bImpulseVelChange = true;

	//Default constructor of components already adds 4 object types to affect,excluding worlddynamic
	Explosion->AddCollisionChannelToAffect(ECC_WorldDynamic);
}

void ASExplosiveBarrel::PostInitializeComponents()
{
	//Dont forget to call a parent function
	Super::PostInitializeComponents();

	BarrelMesh->OnComponentHit.AddDynamic(this, &ASExplosiveBarrel::OnActorHit);
}

void ASExplosiveBarrel::OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	Explosion->FireImpulse();

	//Logging example to make sure we reached the event
	UE_LOG(LogTemp, Log, TEXT("OnActorHit reached (ExplosiveBarrel)"));
}






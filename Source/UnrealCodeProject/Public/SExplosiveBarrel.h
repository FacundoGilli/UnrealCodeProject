// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "SExplosiveBarrel.generated.h"

class UStaticMeshComponent;
class URadialForceComponent;


UCLASS()
class ASExplosiveBarrel : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	ASExplosiveBarrel();

protected:
	
UPROPERTY(VisibleAnywhere)
	UStaticMeshComponent* BarrelMesh;

UPROPERTY(VisibleAnywhere)
	URadialForceComponent* Explosion;

virtual void PostInitializeComponents() override;

//We use UFUNCTION in order to "bind" the event
UFUNCTION()	
void OnActorHit(UPrimitiveComponent* HitComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);
	
};

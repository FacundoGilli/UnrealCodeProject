// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ActorExplote.generated.h"


UCLASS()
class UNREALCODEPROJECT_API AActorExplote : public AActor
{
	GENERATED_BODY()
	
public:
	
	UStaticMeshComponent<BaseMesh>;
	


protected:
	
	
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:
	//Sets default values for this actor's properties
	AActorExplote();
};

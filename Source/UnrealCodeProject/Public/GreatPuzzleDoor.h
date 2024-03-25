// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplayinterface.h"
#include "GameFramework/Actor.h"
#include "GreatPuzzleDoor.generated.h"


class UStaticMeshComponent;

UCLASS()
class UNREALCODEPROJECT_API AGreatPuzzleDoor : public AActor, public IGameplayinterface
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	float TargetPitch;

	UFUNCTION(BlueprintCallable)
	void Interact_Implementation(APawn* CharacterPawn) override;

protected:
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent>DoorRight;
	
	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent>DoorLeft;

public:
	// Sets default values for this actor's properties
	AGreatPuzzleDoor();

};

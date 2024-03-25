// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Gameplayinterface.h"
#include "GameFramework/Actor.h"
#include "ItemChest.generated.h"

class UStaticMeshComponent;

UCLASS()
class UNREALCODEPROJECT_API AItemChest : public AActor, public IGameplayinterface
{
	GENERATED_BODY()

public:
	UPROPERTY(EditAnywhere)
	float TargetPitch;
	
	void Interact_Implementation(APawn* CharacterPawn) override;

protected:

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> BaseMesh;

	UPROPERTY(VisibleAnywhere)
	TObjectPtr<UStaticMeshComponent> OpenMesh;

public:	

	// Sets default values for this actor's properties
	AItemChest();

};

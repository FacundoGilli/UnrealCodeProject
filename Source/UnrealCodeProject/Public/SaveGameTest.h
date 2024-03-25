// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/SaveGame.h"
#include "SaveGameTest.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCODEPROJECT_API USaveGameTest : public USaveGame
{
	GENERATED_BODY()
	
public:
	UPROPERTY(EditAnywhere)
	FVector GetRelativeLocation;
	
};

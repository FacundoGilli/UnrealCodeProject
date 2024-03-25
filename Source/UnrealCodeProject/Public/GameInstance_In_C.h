// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "GameInstance_In_C.generated.h"

/**
 * 
 */
UCLASS()
class UNREALCODEPROJECT_API UGameInstance_In_C : public UGameInstance
{
	GENERATED_BODY()

	void Init() override;

	FString SaveSlot = "GameData";

	class UMySaveGame* gamedata;

public:
	UFUNCTION(BlueprintCallable)
	void SaveGameData(FVector PlayerLocation, int32 Score);

	UFUNCTION(BlueprintCallable)
	void LoadGameData(FString GameData, int index, ACharacter* character);
	
};

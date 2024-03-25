// Fill out your copyright notice in the Description page of Project Settings.


#include "GameInstance_In_C.h"
#include "MySaveGame.h"
#include "Engine.h"

void UGameInstance_In_C :: Init()
{
	//check if there is a game data to load it
	//or create a new one if the game is just starting
	gamedata = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(SaveSlot, 0));

	if(!gamedata)
	{
		//create a new game data
		gamedata = Cast<UMySaveGame>(UGameplayStatics::
			CreateSaveGameObject(UMySaveGame::StaticClass()));

		gamedata->PlayerLocation = FVector(0, 0, 0);
		gamedata->Score = 0;

		UGameplayStatics::SaveGameToSlot(gamedata, SaveSlot, 0);
	}
}

void UGameInstance_In_C::SaveGameData(FVector PlayerLocation, int32 Score)
{
	if (gamedata)
	{
		gamedata->PlayerLocation = PlayerLocation;
		gamedata->Score = Score;

		UGameplayStatics::SaveGameToSlot(gamedata, SaveSlot, 0);
	}
}

void UGameInstance_In_C::LoadGameData(FString GameData, int index, ACharacter* character)
{
	UMySaveGame* SaveGame = Cast<UMySaveGame>(UGameplayStatics::LoadGameFromSlot(GameData, index));
	character->SetActorLocation(SaveGame->PlayerLocation);
}

// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.


#include "ActionRPGSaveGame.h"

UActionRPGSaveGame::UActionRPGSaveGame()
{
	PlayerName = TEXT("Developer");
	UserIndex = 0;
	
	SetupPostion(CharacterData.PlayerLocation);
	SetupPostion(CharacterData.PlayerRotation);

	CharacterData.PlayerRotation = FRotator(0.0f,0.0f,0.0f);
	CharacterData.PlayerLocation = FVector(0.0f, 0.0f, 0.0f);

}

UActionRPGSaveGame::~UActionRPGSaveGame()
{

}

template<class T>
inline T UActionRPGSaveGame::SetupPostion(T Position)
{
	return T();
}

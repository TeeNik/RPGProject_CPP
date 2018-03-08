// Copyright 1998-2017 Epic Games, Inc. All Rights Reserved.

#include "PRGProject_CPPGameMode.h"
#include "PRGProject_CPPCharacter.h"
#include "UObject/ConstructorHelpers.h"

APRGProject_CPPGameMode::APRGProject_CPPGameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/Eve"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

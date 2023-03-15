// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDENG02_UECHAL2GameMode.h"
#include "GDENG02_UECHAL2Character.h"
#include "UObject/ConstructorHelpers.h"

AGDENG02_UECHAL2GameMode::AGDENG02_UECHAL2GameMode()
	: Super()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnClassFinder(TEXT("/Game/FirstPerson/Blueprints/BP_FirstPersonCharacter"));
	DefaultPawnClass = PlayerPawnClassFinder.Class;

}

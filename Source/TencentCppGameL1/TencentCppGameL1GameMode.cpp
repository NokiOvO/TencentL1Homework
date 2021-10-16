// Copyright Epic Games, Inc. All Rights Reserved.

#include "TencentCppGameL1GameMode.h"
#include "TencentCppGameL1Character.h"
#include "UObject/ConstructorHelpers.h"

ATencentCppGameL1GameMode::ATencentCppGameL1GameMode()
{
	// set default pawn class to our Blueprinted character
	static ConstructorHelpers::FClassFinder<APawn> PlayerPawnBPClass(TEXT("/Game/ThirdPersonCPP/Blueprints/ThirdPersonCharacter"));
	if (PlayerPawnBPClass.Class != NULL)
	{
		DefaultPawnClass = PlayerPawnBPClass.Class;
	}
}

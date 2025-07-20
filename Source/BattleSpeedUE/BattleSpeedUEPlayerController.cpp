// Copyright Epic Games, Inc. All Rights Reserved.


#include "BattleSpeedUEPlayerController.h"
#include "EnhancedInputSubsystems.h"
#include "Engine/LocalPlayer.h"
#include "InputMappingContext.h"
#include "BattleSpeedUECameraManager.h"

ABattleSpeedUEPlayerController::ABattleSpeedUEPlayerController()
{
	// set the player camera manager class
	PlayerCameraManagerClass = ABattleSpeedUECameraManager::StaticClass();
}

void ABattleSpeedUEPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();

	// Add Input Mapping Context
	if (UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer()))
	{
		for (UInputMappingContext* CurrentContext : DefaultMappingContexts)
		{
			Subsystem->AddMappingContext(CurrentContext, 0);
		}
	}
}

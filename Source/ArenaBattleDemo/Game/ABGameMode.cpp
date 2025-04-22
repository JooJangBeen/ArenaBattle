// Fill out your copyright notice in the Description page of Project Settings.


#include "ABGameMode.h"

AABGameMode::AABGameMode()
{
	//static ConstructorHelpers::FClassFinder<APawn> ThirdPersonCharacterRef(
	//	TEXT("/Game/ThirdPerson/Blueprints/BP_ThirdPersonCharacter.BP_ThirdPersonCharacter_C"));

	static ConstructorHelpers::FClassFinder<APawn> DefaultCharacterRef(
		TEXT("/Game/ArenaBattle/Blueprint/BP_ABCharacter.BP_ABCharacter_C"));
	
	if (DefaultCharacterRef.Class)
	{
		DefaultPawnClass = DefaultCharacterRef.Class;
	}
	
	//PlayerControllerClass.
	static ConstructorHelpers::FClassFinder<APlayerController> PlayerControllerClassRef(
		TEXT("/Script/ArenaBattleDemo.ABPlayerController"));
	if (PlayerControllerClassRef.Class)
	{
		PlayerControllerClass = PlayerControllerClassRef.Class;
	}
	//PlayerControllerClassRef = AABPlayerController::StaticClass();
}

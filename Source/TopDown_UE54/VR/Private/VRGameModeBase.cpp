// Fill out your copyright notice in the Description page of Project Settings.


#include "VRGameModeBase.h"
#include "HeadMountedDisplayFunctionLibrary.h"
#include "GameFramework/PlayerState.h"

AVRGameModeBase::AVRGameModeBase()
{
	UWorld* World = GetWorld();
	UWorld* GGWorld = GWorld;

	{
		ConstructorHelpers::FClassFinder<APawn> Asset(TEXT("/Script/Engine.Blueprint'/Game/Player/BPVR_Pawn.BPVR_Pawn_C'"));
		check(Asset.Class);
		VRPawnClass = Asset.Class;
	}

	{
		ConstructorHelpers::FClassFinder<APlayerController> Asset(
			TEXT("/Script/Engine.Blueprint'/Game/Player/BP_VRPlayerController.BP_VRPlayerController_C'"));
		check(Asset.Class);
		VRPlayerControllerClass = Asset.Class;
	}

	{
		ConstructorHelpers::FClassFinder<APawn> Asset(TEXT("/Script/Engine.Blueprint'/Game/Player/BP_GASCharacter.BP_GASCharacter_C'"));
		check(Asset.Class);
		GASCharacterClass = Asset.Class;
	}

	{
		ConstructorHelpers::FClassFinder<APlayerController> Asset(
			TEXT("/Script/Engine.Blueprint'/Game/Player/BP_GASPC.BP_GASPC_C'"));
		check(Asset.Class);
		GASPlayerControllerClass = Asset.Class;
	}

	{
		ConstructorHelpers::FClassFinder<APlayerState> Asset(
			TEXT("/Script/Engine.Blueprint'/Game/Player/BP_GASPlayerState.BP_GASPlayerState_C'"));
		check(Asset.Class);
		GASPlayerStateClass = Asset.Class;
	}
}

APlayerController* AVRGameModeBase::Login(UPlayer* NewPlayer, ENetRole InRemoteRole, const FString& Portal, const FString& Options, const FUniqueNetIdRepl& UniqueId, FString& ErrorMessage)
{
	const bool bVR = UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled();
	if (bVR)
	{
		DefaultPawnClass = VRPawnClass;
		PlayerControllerClass = VRPlayerControllerClass;
	}
	else
	{
		DefaultPawnClass = GASCharacterClass;
		PlayerControllerClass = GASPlayerControllerClass;
		PlayerStateClass = GASPlayerStateClass;
	}
	return Super::Login(NewPlayer, InRemoteRole, Portal, Options, UniqueId, ErrorMessage);
}

void AVRGameModeBase::BeginPlay()
{
	Super::BeginPlay();

	UWorld* World = GetWorld();
	UWorld* GGWorld = GWorld;
}

void AVRGameModeBase::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	Super::EndPlay(EndPlayReason);
}
// Fill out your copyright notice in the Description page of Project Settings.


#include "VRGameModeBase.h"
#include "HeadMountedDisplayFunctionLibrary.h"

AVRGameModeBase::AVRGameModeBase()
{
	{
		ConstructorHelpers::FClassFinder<APawn> Asset(TEXT("/Script/Engine.Blueprint'/Game/Player/BPVR_Pawn.BPVR_Pawn_C'"));
		check(Asset.Class);
		VRPawnClass = Asset.Class;
	}

	{
		ConstructorHelpers::FClassFinder<APawn> Asset(TEXT("/Script/Engine.Blueprint'/Game/Player/BP_GASCharacter.BP_GASCharacter_C'"));
		check(Asset.Class);
		GASCharacterClass = Asset.Class;
	}
}

FString AVRGameModeBase::InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal)
{
	const bool bVR = UHeadMountedDisplayFunctionLibrary::IsHeadMountedDisplayEnabled();
	if (bVR)
	{
		DefaultPawnClass = VRPawnClass;
	}
	else
	{
		DefaultPawnClass = GASCharacterClass;
	}
	return Super::InitNewPlayer(NewPlayerController, UniqueId, Options, Portal);
}
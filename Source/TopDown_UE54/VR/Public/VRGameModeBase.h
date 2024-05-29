// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/GameModeBase.h"
#include "VRGameModeBase.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN_UE54_API AVRGameModeBase : public AGameModeBase
{
	GENERATED_BODY()
public:
	AVRGameModeBase();
protected:
	virtual FString InitNewPlayer(APlayerController* NewPlayerController, const FUniqueNetIdRepl& UniqueId, const FString& Options, const FString& Portal = TEXT("")) override;

private:
	UClass* VRPawnClass = nullptr;
	UClass* GASCharacterClass = nullptr;
};

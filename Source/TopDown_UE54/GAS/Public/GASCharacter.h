// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GASCharacterBase.h"
#include "GASCharacter.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN_UE54_API AGASCharacter : public AGASCharacterBase
{
	GENERATED_BODY()
public:
	AGASCharacter();
	virtual void PossessedBy(AController* NewController) override;
	virtual void OnRep_PlayerState() override;
private:
	void InitAbilityActorInfo();
};

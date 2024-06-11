// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "GASCharacterBase.generated.h"

UCLASS(Abstract)
class TOPDOWN_UE54_API AGASCharacterBase : public ACharacter
{
	GENERATED_BODY()

public:
	AGASCharacterBase();

protected:
	virtual void BeginPlay() override;

};

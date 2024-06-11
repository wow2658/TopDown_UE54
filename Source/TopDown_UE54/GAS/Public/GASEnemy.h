// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GASCharacterBase.h"
#include "GASEnemyInterface.h"
#include "GASEnemy.generated.h"

/**
 * 
 */
UCLASS()
class TOPDOWN_UE54_API AGASEnemy : public AGASCharacterBase, public IGASEnemyInterface
{
	GENERATED_BODY()

public:
	AGASEnemy();
	virtual void HighlightActor() override;
	virtual void UnHighlightActor() override;
	
	UPROPERTY(BlueprintReadOnly)
	bool bHighlighted = false;
};

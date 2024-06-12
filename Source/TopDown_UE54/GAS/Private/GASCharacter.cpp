// Fill out your copyright notice in the Description page of Project Settings.


#include "GASCharacter.h"

#include "AbilitySystemComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GASPlayerState.h"
//#include "GASAttributeSet.h"

AGASCharacter::AGASCharacter()
{
	GetCharacterMovement()->bOrientRotationToMovement = true;
	GetCharacterMovement()->RotationRate = FRotator(0.f, 400.f, 0.f);
	GetCharacterMovement()->bConstrainToPlane = true;
	GetCharacterMovement()->bSnapToPlaneAtStart = true;

	bUseControllerRotationPitch = false;
	bUseControllerRotationRoll = false;
	bUseControllerRotationYaw = false;
}

void AGASCharacter::PossessedBy(AController* NewController)
{
	Super::PossessedBy(NewController);

	InitAbilityActorInfo();

}

void AGASCharacter::OnRep_PlayerState()
{
	Super::OnRep_PlayerState();

	InitAbilityActorInfo();

}

void AGASCharacter::InitAbilityActorInfo()
{
	AGASPlayerState* GASPS = GetPlayerState<AGASPlayerState>();
	check(GASPS);
	GASPS->GetAbilitySystemComponent()->InitAbilityActorInfo(GASPS, this);
	ASC = GASPS->GetAbilitySystemComponent();
	AttributeSet = GASPS->GetAttributeSet();
	//const UGASAttributeSet* CurrentAttributeSet = ASC->GetSet<UGASAttributeSet>();
}

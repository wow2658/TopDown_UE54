// Fill out your copyright notice in the Description page of Project Settings.


#include "GASPlayerState.h"

#include "GASAbilitySystemComponent.h"
#include "GASAttributeSet.h"

AGASPlayerState::AGASPlayerState()
{
	ASC = CreateDefaultSubobject<UGASAbilitySystemComponent>("AbilitySystemComponent");
	ASC->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UGASAttributeSet>("AttributeSet");

	NetUpdateFrequency = 100.f;
}

UAbilitySystemComponent* AGASPlayerState::GetAbilitySystemComponent() const
{
	return ASC;
}

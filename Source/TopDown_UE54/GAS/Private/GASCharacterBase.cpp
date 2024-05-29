// Fill out your copyright notice in the Description page of Project Settings.


#include "GASCharacterBase.h"
#include "Components/CapsuleComponent.h"
AGASCharacterBase::AGASCharacterBase()
{
	PrimaryActorTick.bCanEverTick = false;
	
	GetMesh()->SetRelativeLocationAndRotation(FVector(0.0,0.0, -GetCapsuleComponent()->GetScaledCapsuleHalfHeight()),FRotator(0.0,270.0,0.0) );
}

void AGASCharacterBase::BeginPlay()
{
	Super::BeginPlay();
}


// Fill out your copyright notice in the Description page of Project Settings.


#include "GASEnemy.h"

#include "GASAbilitySystemComponent.h"
#include "GASAttributeSet.h"

AGASEnemy::AGASEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);

	ASC = CreateDefaultSubobject<UGASAbilitySystemComponent>("AbilitySystemComponent");
	ASC->SetIsReplicated(true);

	AttributeSet = CreateDefaultSubobject<UGASAttributeSet>("AttributeSet");
}

void AGASEnemy::HighlightActor()
{
	//bHighlighted = true;
	GetMesh()->SetRenderCustomDepth(true);
	GetMesh()->SetCustomDepthStencilValue(250.f);
}

void AGASEnemy::UnHighlightActor()
{
	//bHighlighted = false;
	GetMesh()->SetRenderCustomDepth(false);
}

void AGASEnemy::BeginPlay()
{
	Super::BeginPlay();

	ASC->InitAbilityActorInfo(this, this);
}

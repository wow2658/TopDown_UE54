// Fill out your copyright notice in the Description page of Project Settings.


#include "GASEnemy.h"

AGASEnemy::AGASEnemy()
{
	GetMesh()->SetCollisionResponseToChannel(ECC_Visibility, ECR_Block);
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

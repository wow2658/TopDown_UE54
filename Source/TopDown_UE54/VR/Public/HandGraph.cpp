// Fill out your copyright notice in the Description page of Project Settings.


#include "TopDown_UE54/VR/Public/HandGraph.h"

UHandGraph::UHandGraph()
{
	PrimaryComponentTick.bCanEverTick = true;

}


void UHandGraph::BeginPlay()
{
	Super::BeginPlay();

	
}


void UHandGraph::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

}
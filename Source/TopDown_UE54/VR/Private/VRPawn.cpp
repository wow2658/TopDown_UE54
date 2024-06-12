// Fill out your copyright notice in the Description page of Project Settings.


#include "VRPawn.h"

#include "Components/CapsuleComponent.h"
#include "Camera/CameraComponent.h"
#include "MotionControllerComponent.h"
#include "Components/WidgetInteractionComponent.h"
#include "HandGraph.h"
#include "VRHandSkeletalMeshComponent.h"
#include "Components/WidgetComponent.h"

AVRPawn::AVRPawn()
{
	PrimaryActorTick.bCanEverTick = true;

	CapsuleComponent = CreateDefaultSubobject<UCapsuleComponent>(TEXT("CapsuleComponent"));
	CapsuleComponent->InitCapsuleSize(34.0f, 88.0f);
	//CapsuleComponent->SetCollisionProfileName(UCollisionProfile::Pawn_ProfileName);
	RootComponent = CapsuleComponent;

	VRCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("VRCamera"));
	VRCamera->SetupAttachment(GetRootComponent());

	MotionControllerLeft = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerLeft"));
	MotionControllerRight = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerRight"));

	MotionControllerLeftAim = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerLeftAim"));
	MotionControllerRightAim = CreateDefaultSubobject<UMotionControllerComponent>(TEXT("MotionControllerRightAim"));
	WidgetInteractionLeft = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionLeft"));
	WidgetInteractionRight = CreateDefaultSubobject<UWidgetInteractionComponent>(TEXT("WidgetInteractionRight"));

	MotionControllerLeft->SetTrackingMotionSource(LeftGrip);
	MotionControllerRight->SetTrackingMotionSource(RightGrip);
	MotionControllerLeft->SetupAttachment(GetRootComponent());
	MotionControllerRight->SetupAttachment(GetRootComponent());
	{
		MotionControllerLeftAim->SetTrackingMotionSource(LeftAim);
		MotionControllerRightAim->SetTrackingMotionSource(RightAim);
		MotionControllerLeftAim->SetupAttachment(GetRootComponent());
		MotionControllerRightAim->SetupAttachment(GetRootComponent());
		WidgetInteractionLeft->SetupAttachment(MotionControllerLeftAim);
		WidgetInteractionLeft->PointerIndex = 1;
		WidgetInteractionLeft->InteractionDistance = 1000.f;
		WidgetInteractionLeft->bShowDebug = true;
		WidgetInteractionLeft->TraceChannel = ECollisionChannel::ECC_GameTraceChannel6;
		WidgetInteractionRight->SetupAttachment(MotionControllerRightAim);
		WidgetInteractionRight->PointerIndex = 2;
		WidgetInteractionRight->InteractionDistance = 1000.f;
		WidgetInteractionRight->bShowDebug = true;
		WidgetInteractionRight->TraceChannel = ECollisionChannel::ECC_GameTraceChannel6;
	}

	HandGraphLeft = CreateDefaultSubobject<UHandGraph>(TEXT("HandGraphLeft"));
	HandGraphRight = CreateDefaultSubobject<UHandGraph>(TEXT("HandGraphRight"));

	LeftHand = CreateDefaultSubobject<UVRHandSkeletalMeshComponent>(TEXT("LeftHand"));
	LeftHand->SetupAttachment(MotionControllerLeft);

	{
		LeftHandWidget = CreateDefaultSubobject<UWidgetComponent>(TEXT("LeftHandWidget"));
		LeftHandWidget->SetupAttachment(MotionControllerLeft);

		FTransform Transform = FTransform(
			FRotator(58.7, 180.0, 0.0),
			FVector(20.0, -12.0, -1.8),
			FVector(0.05, 0.05, 0.05));
		LeftHandWidget->SetRelativeTransform(Transform);
		LeftHandWidget->SetDrawSize(FVector2D(800.0, 800.0));
	}

	RightHand = CreateDefaultSubobject<UVRHandSkeletalMeshComponent>(TEXT("RightHand"));
	RightHand->SetupAttachment(MotionControllerRight);

	{
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> Asset(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/MannequinsXR/Meshes/SKM_MannyXR_right.SKM_MannyXR_right'"));
		RightHand->SetSkeletalMeshAsset(Asset.Object);

		const FTransform Transform = FTransform(FRotator(25.0, 0.0, 90.0), FVector(-2.98, 3.5, 4.56));
		RightHand->SetRelativeTransform(Transform);
		//RightHand->SetAnimClass(AnimClass.Class);
	}
	{
		static ConstructorHelpers::FObjectFinder<USkeletalMesh> Asset(TEXT("/Script/Engine.SkeletalMesh'/Game/Assets/MannequinsXR/Meshes/SKM_MannyXR_left.SKM_MannyXR_left'"));
		LeftHand->SetSkeletalMeshAsset(Asset.Object);

		const FTransform Transform = FTransform(FRotator(-25.0, 180.0, 90.0), FVector(-2.98, -3.5, 4.56));
		LeftHand->SetRelativeTransform(Transform);
		LeftHand->bMirror = true;
		//LeftHand->SetAnimClass(AnimClass.Class);
	}
}

void AVRPawn::PreInitializeComponents()
{
}

void AVRPawn::BeginPlay()
{
	Super::BeginPlay();

}

void AVRPawn::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AVRPawn::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

void AVRPawn::OnMove(const FInputActionValue& InputActionValue)
{
}

void AVRPawn::OnGrabStarted(UMotionControllerComponent* MotionControllerComponent, const bool bLeft, const FInputActionValue& InputActionValue)
{
}

void AVRPawn::OnGrabCompleted(UMotionControllerComponent* MotionControllerComponent, const bool bLeft, const FInputActionValue& InputActionValue)
{
}


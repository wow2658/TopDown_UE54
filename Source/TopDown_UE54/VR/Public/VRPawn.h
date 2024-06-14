// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "InputActionValue.h"

#include "VRPawn.generated.h"

class UCapsuleComponent;
class UCameraComponent;
class UMotionControllerComponent;
class UWidgetInteractionComponent;
class UWidgetComponent;
class UVRHandSkeletalMeshComponent;
class UHandGraph;
class UFloatingPawnMovement;

static inline const FName LeftGrip = TEXT("LeftGrip");
static inline const FName LeftAim = TEXT("LeftAim");
static inline const FName RightGrip = TEXT("RightGrip");
static inline const FName RightAim = TEXT("RightAim");

static inline FName PhysicsActor = TEXT("PhysicsActor");
//static inline FName Player = TEXT("Player");
static inline FName PlayerDetect = TEXT("PlayerDetect");
static inline FName PlayerProjectile = TEXT("PlayerProjectile");
static inline FName Enemy = TEXT("Enemy");

UCLASS()
class TOPDOWN_UE54_API AVRPawn : public APawn
{
	GENERATED_BODY()

public:
	AVRPawn();

protected:
	virtual void PreInitializeComponents() override;
	virtual void BeginPlay() override;

public:
	virtual void Tick(float DeltaTime) override;
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

protected:
	void OnMove(const FInputActionValue& InputActionValue);

	void OnGrabLeftStarted(const FInputActionValue& InputActionValue) { OnGrabStarted(MotionControllerLeft, true, InputActionValue); }
	void OnGrabRightStarted(const FInputActionValue& InputActionValue) { OnGrabStarted(MotionControllerRight, false, InputActionValue); }
	void OnGrabStarted(UMotionControllerComponent* MotionControllerComponent, const bool bLeft, const FInputActionValue& InputActionValue);

	void OnGrabLeftCompleted(const FInputActionValue& InputActionValue) { OnGrabCompleted(MotionControllerLeft, true, InputActionValue); }
	void OnGrabRightCompleted(const FInputActionValue& InputActionValue) { OnGrabCompleted(MotionControllerRight, false, InputActionValue); }
	void OnGrabCompleted(UMotionControllerComponent* MotionControllerComponent, const bool bLeft, const FInputActionValue& InputActionValue);

protected:

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UCapsuleComponent> CapsuleComponent;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UCameraComponent> VRCamera;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UMotionControllerComponent> MotionControllerLeft;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UMotionControllerComponent> MotionControllerRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UMotionControllerComponent> MotionControllerLeftAim;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UMotionControllerComponent> MotionControllerRightAim;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetInteractionComponent> WidgetInteractionLeft;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetInteractionComponent> WidgetInteractionRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UVRHandSkeletalMeshComponent> LeftHand;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UWidgetComponent> LeftHandWidget;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UVRHandSkeletalMeshComponent> RightHand;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UHandGraph> HandGraphLeft;
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UHandGraph> HandGraphRight;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	TObjectPtr<UPawnMovementComponent> MovementComponent;

};

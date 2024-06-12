// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MotionControllerComponent.h"
#include "VRHandSkeletalMeshComponent.h"
#include "Components/ActorComponent.h"
#include "InputMappingContext.h"
#include "HandGraph.generated.h"

UCLASS()
class TOPDOWN_UE54_API UBasicInputDataConfig : public UObject
{
	GENERATED_BODY()

public:
	UBasicInputDataConfig();
	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

public:
	TObjectPtr<UInputAction> Move = nullptr;
	TObjectPtr<UInputAction> Look = nullptr;
};

UCLASS()
class TOPDOWN_UE54_API UVRHandsAnimationInputDataConfig : public UObject
{
	GENERATED_BODY()

public:
	UVRHandsAnimationInputDataConfig();

	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

public:
	TObjectPtr<UInputAction> IA_Grab_Left = nullptr;
	TObjectPtr<UInputAction> IA_Grab_Right = nullptr;

	TObjectPtr<UInputAction> IA_Point_Left = nullptr;
	TObjectPtr<UInputAction> IA_Point_Right = nullptr;

	TObjectPtr<UInputAction> IA_IndexCurl_Left = nullptr;
	TObjectPtr<UInputAction> IA_IndexCurl_Right = nullptr;

	TObjectPtr<UInputAction> IA_Thumb_Left = nullptr;
	TObjectPtr<UInputAction> IA_Thumb_Right = nullptr;
};

UCLASS()
class TOPDOWN_UE54_API UVRHandsInputDataConfig : public UObject
{
	GENERATED_BODY()

public:
	UVRHandsInputDataConfig();

	TObjectPtr<UInputMappingContext> InputMappingContext = nullptr;

public:
	TObjectPtr<UInputAction> IA_Grab_Left = nullptr;
	TObjectPtr<UInputAction> IA_Grab_Right = nullptr;

	TObjectPtr<UInputAction> IA_Trigger_Left = nullptr;
	TObjectPtr<UInputAction> IA_Trigger_Right = nullptr;

	/*TObjectPtr<UInputAction> IA_Point_Left = nullptr;
	TObjectPtr<UInputAction> IA_Point_Right = nullptr;

	TObjectPtr<UInputAction> IA_IndexCurl_Left = nullptr;
	TObjectPtr<UInputAction> IA_IndexCurl_Right = nullptr;

	TObjectPtr<UInputAction> IA_Thumb_Left = nullptr;
	TObjectPtr<UInputAction> IA_Thumb_Right = nullptr;*/
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class TOPDOWN_UE54_API UHandGraph : public UActorComponent
{
	GENERATED_BODY()

	enum EHandType
	{
		Left,
		Right
	};

public:
	void SetupPlayerInputComponent(UMotionControllerComponent* InMotionControllerComponent, UEnhancedInputComponent* InputComponent);
	void OnGrabTriggered(const FInputActionValue& InputActionValue);
	void OnGrabCompleted(const FInputActionValue& InputActionValue);

	void OnPointStarted(const FInputActionValue& InputActionValue);
	void OnPointCompleted(const FInputActionValue& InputActionValue);

	void OnIndexCurlTriggered(const FInputActionValue& InputActionValue);
	void OnIndexCurlCompleted(const FInputActionValue& InputActionValue);

	void OnThumbStarted(const FInputActionValue& InputActionValue);
	void OnThumbCompleted(const FInputActionValue& InputActionValue);

	TObjectPtr<UMotionControllerComponent> MotionControllerComponent = nullptr;
	//UVRHandAnimInstance* VRHandAnimInstance = nullptr;
	EHandType HandType = (EHandType)-1;
};

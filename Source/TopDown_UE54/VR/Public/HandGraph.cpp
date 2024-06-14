// Fill out your copyright notice in the Description page of Project Settings.


#include "HandGraph.h"
#include "InputMappingContext.h"
#include "InputAction.h"
#include "EnhancedInputComponent.h"

UBasicInputDataConfig::UBasicInputDataConfig()
{
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Player/Input/IMC_WASDContext.IMC_WASDContext'") };
		check(Asset.Succeeded());
		InputMappingContext = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_Move.IA_Move'") };
		check(Asset.Succeeded());
		Move = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_LookMouse.IA_LookMouse'") };
		check(Asset.Succeeded());
		Look = Asset.Object;
	}
}

UVRHandsAnimationInputDataConfig::UVRHandsAnimationInputDataConfig()
{
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Player/Input/IMC_HandsContext.IMC_HandsContext'") };
		check(Asset.Object);
		InputMappingContext = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_Grab_Left.IA_Grab_Left'") };
		check(Asset.Object);
		IA_Grab_Left = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_Grab_Right.IA_Grab_Right'") };
		check(Asset.Object);
		IA_Grab_Right = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_Point_Left.IA_Point_Left'") };
		check(Asset.Object);
		IA_Point_Left = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_Point_Right.IA_Point_Right'") };
		check(Asset.Object);
		IA_Point_Right = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_IndexCurl_Left.IA_IndexCurl_Left'") };
		check(Asset.Object);
		IA_IndexCurl_Left = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_IndexCurl_Right.IA_IndexCurl_Right'") };
		check(Asset.Object);
		IA_IndexCurl_Right = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_Thumb_Left.IA_Thumb_Left'") };
		check(Asset.Object);
		IA_Thumb_Left = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/IA_Thumb_Right.IA_Thumb_Right'") };
		check(Asset.Object);
		IA_Thumb_Right = Asset.Object;
	}
}

UVRHandsInputDataConfig::UVRHandsInputDataConfig()
{
	{
		static ConstructorHelpers::FObjectFinder<UInputMappingContext> Asset
		{ TEXT("/Script/EnhancedInput.InputMappingContext'/Game/Player/Input/HandsInput/IMC_HandsInputContext.IMC_HandsInputContext'") };
		check(Asset.Object);
		InputMappingContext = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/HandsInput/IA_Grab_Left_Input.IA_Grab_Left_Input'") };
		check(Asset.Object);
		IA_Grab_Left = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/HandsInput/IA_Grab_Right_Input.IA_Grab_Right_Input'") };
		check(Asset.Object);
		IA_Grab_Right = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/HandsInput/IA_Trigger_Left_Input.IA_Trigger_Left_Input'") };
		check(Asset.Object);
		IA_Trigger_Left = Asset.Object;
	}
	{
		static ConstructorHelpers::FObjectFinder<UInputAction> Asset
		{ TEXT("/Script/EnhancedInput.InputAction'/Game/Player/Input/HandsInput/IA_Trigger_Right_Input.IA_Trigger_Right_Input'") };
		check(Asset.Object);
		IA_Trigger_Right = Asset.Object;
	}
}

void UHandGraph::SetupPlayerInputComponent(UMotionControllerComponent* InMotionControllerComponent, UEnhancedInputComponent* InputComponent)
{

}

void UHandGraph::OnGrabTriggered(const FInputActionValue& InputActionValue)
{
}

void UHandGraph::OnGrabCompleted(const FInputActionValue& InputActionValue)
{
}

void UHandGraph::OnPointStarted(const FInputActionValue& InputActionValue)
{
}

void UHandGraph::OnPointCompleted(const FInputActionValue& InputActionValue)
{
}

void UHandGraph::OnIndexCurlTriggered(const FInputActionValue& InputActionValue)
{
}

void UHandGraph::OnIndexCurlCompleted(const FInputActionValue& InputActionValue)
{
}

void UHandGraph::OnThumbStarted(const FInputActionValue& InputActionValue)
{
}

void UHandGraph::OnThumbCompleted(const FInputActionValue& InputActionValue)
{
}


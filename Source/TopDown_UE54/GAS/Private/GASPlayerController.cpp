// Fill out your copyright notice in the Description page of Project Settings.


#include "GASPlayerController.h"

#include "EnhancedInputSubsystems.h"
#include "EnhancedInputComponent.h"
#include "GASEnemyInterface.h"

AGASPlayerController::AGASPlayerController()
{
	bReplicates = true;
}

void AGASPlayerController::PlayerTick(float DeltaTime)
{
	Super::PlayerTick(DeltaTime);

	CursorTrace();
}

void AGASPlayerController::CursorTrace()
{
	FHitResult CursorHit;
	GetHitResultUnderCursor(ECC_Visibility, false, CursorHit);
	if (!CursorHit.bBlockingHit) return;

	LastActor = ThisActor;
	ThisActor = CursorHit.GetActor();

	if (LastActor == nullptr)
	{
		if (ThisActor != nullptr)
		{
			// LastActor is null && ThisActor is Valid - 평화롭다가 커서 올리는 경우
			ThisActor->HighlightActor();
		}
		else
		{
			// - LastActor is null && ThisActor is null - 아무것도 안 건드린 경우
		}
	}
	else // LastActor is valid
	{
		if (ThisActor == nullptr)
		{
			// LastActor is Valid && ThisActor is null - 하이라이트였다가 내려놓는 경우
			LastActor->UnHighlightActor();
		}
		else // both actors are valid
		{
			if (LastActor != ThisActor)
			{
				// - LastActor is Valid && ThisActor is Valid, LastActor != ThisActor - 엄청빠르게 여러마리 슥 긁는 경우
				LastActor->UnHighlightActor();
				ThisActor->HighlightActor();
			}
			else
			{
				// LastActor is Valid && ThisActor is Valid, LastActor == ThisActor - 그냥 마우스 올려놓고 쭉 가만히 있는 경우
			}
		}
	}

}

void AGASPlayerController::BeginPlay()
{
	Super::BeginPlay();
	check(WASDContext);

	UEnhancedInputLocalPlayerSubsystem* Subsystem = ULocalPlayer::GetSubsystem<UEnhancedInputLocalPlayerSubsystem>(GetLocalPlayer());
	check(Subsystem);
	Subsystem->AddMappingContext(WASDContext, 0);

	bShowMouseCursor = true;
	DefaultMouseCursor = EMouseCursor::Default;

	FInputModeGameAndUI InputModeData;
	InputModeData.SetLockMouseToViewportBehavior(EMouseLockMode::DoNotLock);
	InputModeData.SetHideCursorDuringCapture(false);
	SetInputMode(InputModeData);


}

void AGASPlayerController::SetupInputComponent()
{
	Super::SetupInputComponent();
	/*void AGASCharacterBase::SetupPlayerInputComponent(UInputComponent * PlayerInputComponent)
	{
		Super::SetupPlayerInputComponent(PlayerInputComponent);
		버전이 다르다.
	}*/

	UEnhancedInputComponent* EnhancedInputComponent = CastChecked<UEnhancedInputComponent>(InputComponent);
	EnhancedInputComponent->BindAction(MoveAction, ETriggerEvent::Triggered, this, &AGASPlayerController::Move);

}

void AGASPlayerController::Move(const FInputActionValue& InputActionValue)
{
	const FVector2D InputAxisVector = InputActionValue.Get<FVector2D>();
	const FRotator Rotation = GetControlRotation();
	const FRotator YawRotation(0.f, Rotation.Yaw, 0.f);

	const FVector ForwardDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::X);
	const FVector RightDirection = FRotationMatrix(YawRotation).GetUnitAxis(EAxis::Y);

	if (APawn* ControlledPawn = GetPawn<APawn>())
	{
		ControlledPawn->AddMovementInput(ForwardDirection, InputAxisVector.Y); // swizzle
		ControlledPawn->AddMovementInput(RightDirection, InputAxisVector.X);
	}
}
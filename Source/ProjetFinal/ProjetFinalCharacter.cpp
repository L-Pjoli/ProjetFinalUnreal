// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjetFinalCharacter.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AProjetFinalCharacter::AProjetFinalCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	bUseControllerRotationYaw = true;
	bUseControllerRotationPitch = true;

}

// Called to bind functionality to input
void AProjetFinalCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAction("Jump", IE_Pressed, this, &ACharacter::Jump);
	PlayerInputComponent->BindAction("Jump", IE_Released, this, &ACharacter::StopJumping);

	PlayerInputComponent->BindAxis("MoveForward", this, &AProjetFinalCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &AProjetFinalCharacter::MoveRight);
	PlayerInputComponent->BindAxis("Turn", this, &AProjetFinalCharacter::Turn);
	PlayerInputComponent->BindAxis("LookUp", this, &AProjetFinalCharacter::LookUp);
}

void AProjetFinalCharacter::MoveForward(float Amount)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::X);
	AddMovementInput(Direction, Amount);
}

void AProjetFinalCharacter::MoveRight(float Amount)
{
	FVector Direction = FRotationMatrix(Controller->GetControlRotation()).GetScaledAxis(EAxis::Y);
	AddMovementInput(Direction, Amount);
}

void AProjetFinalCharacter::Turn(float Amount)
{
	AddControllerYawInput(Amount);
}

void AProjetFinalCharacter::LookUp(float Amount)
{
	AddControllerPitchInput(Amount);
}




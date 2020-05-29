// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "ProjetFinalCharacter.generated.h"

UCLASS()
class PROJETFINAL_API AProjetFinalCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AProjetFinalCharacter();

protected:

	void MoveForward(float Amount);
	void MoveRight(float Amount);
	void Turn(float Amount);
	void LookUp(float Amount);

public:	
	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

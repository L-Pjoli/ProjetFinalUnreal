// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "StartButton.generated.h"

/**
 * 
 */
UCLASS()
class PROJETFINAL_API AStartButton : public ATriggerBox
{
	GENERATED_BODY()

public:
	AStartButton();

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, Category = "Setting")
		class AActor* SpecificActor;

	UPROPERTY(EditAnywhere, Category = "Setting")
		class AProjetFinal_GameMode* Gamemode;
};

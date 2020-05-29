// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "DeathVolume.generated.h"

/**
 * 
 */
UCLASS()
class PROJETFINAL_API ADeathVolume : public ATriggerBox
{
	GENERATED_BODY()

public:
	ADeathVolume();

	UFUNCTION()
		void OnOverlapBegin(class AActor* OverlappedActor, class AActor* OtherActor);

	UPROPERTY(EditAnywhere, Category = "DeathVolumeSetting")
		class AProjetFinal_GameMode* Gamemode;
};

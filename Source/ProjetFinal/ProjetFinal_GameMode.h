// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ProjetFinal_GameMode.generated.h"

UCLASS()
class PROJETFINAL_API AProjetFinal_GameMode : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AProjetFinal_GameMode();

	void StartGame();
	void Lose();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void movePlatformsFunc(int32 RandNum);
	void removePlatformsFunc();
	void Reset();
	void CleanUp();
	void Win();

	UPROPERTY(EditAnywhere, Category = "GameModeSettings")
		APawn* Character;

	UPROPERTY(EditAnywhere, Category = "GameModeSettings")
		UMaterial* ChangeMaterial;

	UPROPERTY(EditAnywhere, Category = "GameModeSettings")
		int32 Counter;

	UPROPERTY(EditAnywhere, Category = "GameModeSettings")
		float ColorChangeTime;

	std::vector<AActor*> Platforms;
	UWorld* world;
	std::vector<FVector> PlatformsLocation;
	bool FlagGameRunning;
	FTimerHandle RemovePlatform;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

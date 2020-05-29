// Fill out your copyright notice in the Description page of Project Settings.


#include "ProjetFinal_GameMode.h"
#include "EngineUtils.h"
#include "TimerManager.h"
#include "Engine/World.h"
#include "Engine/LevelStreaming.h"
#include "GameFramework/Pawn.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProjetFinalCharacter.h"

// Sets default values
AProjetFinal_GameMode::AProjetFinal_GameMode()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AProjetFinal_GameMode::BeginPlay()
{
	Super::BeginPlay();
	world = GetWorld();
	TActorIterator<AActor> Iterator(world, AActor::StaticClass());
	for (; Iterator; ++Iterator)
	{
		AActor* Actor = Cast<AActor>(*Iterator);
		if (Actor->GetFName().ToString().Find("Cube") != std::string::npos) {
			Platforms.push_back(Actor);
		}
		Character = GetWorld()->GetFirstPlayerController()->GetPawn();
	}
}

void AProjetFinal_GameMode::StartGame()
{
	FlagGameRunning = true;
	this->Reset();
	for (AActor* platform : Platforms) {
		PlatformsLocation.push_back(platform->GetActorLocation());
	}
	Character->SetActorLocation(FVector(-100.0f, -100.0f, 910.0f));
	Character->SetActorRotation(FRotator(0.0f, 0.0f, 0.0f));

	for (int32 i = 0; i <= Counter; i++) {
		UE_LOG(LogTemp, Warning, TEXT("test"));
		if (FlagGameRunning) {
			FTimerDelegate removePlatforms = FTimerDelegate::CreateUObject(this, &AProjetFinal_GameMode::removePlatformsFunc);
			GetWorldTimerManager().SetTimer(RemovePlatform, removePlatforms, ColorChangeTime + 0.25f, false);
		}
	}

	if (FlagGameRunning) {
		this->Win();
	}
}

void AProjetFinal_GameMode::movePlatformsFunc(int32 RandNum)
{
	Platforms.at(RandNum)->SetActorLocation(FVector(-10000.0f, -10000.0f, 200.0f));
}

void AProjetFinal_GameMode::removePlatformsFunc()
{
	int32 RandNum = rand() % 35;
	TArray<UStaticMeshComponent*> StaticComps;
	Platforms.at(RandNum)->GetComponents<UStaticMeshComponent>(StaticComps);
	FTimerDelegate movePlatforms = FTimerDelegate::CreateUObject(this, &AProjetFinal_GameMode::movePlatformsFunc, RandNum);
	GetWorldTimerManager().SetTimer(RemovePlatform, movePlatforms, ColorChangeTime, false);
}

void AProjetFinal_GameMode::Reset()
{
}

void AProjetFinal_GameMode::CleanUp()
{
}

void AProjetFinal_GameMode::Win()
{
}

void AProjetFinal_GameMode::Lose()
{
}



// Called every frame
void AProjetFinal_GameMode::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}


// Fill out your copyright notice in the Description page of Project Settings.


#include "StartButton.h"
#include "ProjetFinal_GameMode.h"

AStartButton::AStartButton()
{
	OnActorBeginOverlap.AddDynamic(this, &AStartButton::OnOverlapBegin);
}


void AStartButton::OnOverlapBegin(AActor * OverlappedActor, AActor * OtherActor)
{
	//Gamemode->StartGame();
}

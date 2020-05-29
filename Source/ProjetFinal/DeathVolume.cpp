// Fill out your copyright notice in the Description page of Project Settings.


#include "DeathVolume.h"
#include "ProjetFinal_GameMode.h"

ADeathVolume::ADeathVolume()
{
	OnActorBeginOverlap.AddDynamic(this, &ADeathVolume::OnOverlapBegin);
}

void ADeathVolume::OnOverlapBegin(AActor * OverlappedActor, AActor *OtherActor)
{
	//Gamemode->Lose();
}

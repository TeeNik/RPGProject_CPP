// Fill out your copyright notice in the Description page of Project Settings.

#include "MyTriggerBox.h"

void AMyTriggerBox::BeginPlay()
{
	Super::BeginPlay();

	//Register the enter and exit overlaps to fire
	OnActorBeginOverlap.AddDynamic(this, &AMyTriggerBox::OnTriggerEnter);
	OnActorEndOverlap.AddDynamic(this, &AMyTriggerBox::OnTriggerExit);
}

/*4.12 version*/
void AMyTriggerBox::OnTriggerEnter(AActor* OverlapedActor, AActor* OtherActor)
{
	GLog->Log("Begin overlap has fired");
}

/*4.12 version*/
void AMyTriggerBox::OnTriggerExit(AActor* OverlapedActor, AActor* OtherActor)
{
	GLog->Log("End overlap has fired");
}

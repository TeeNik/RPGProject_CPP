// Fill out your copyright notice in the Description page of Project Settings.

#include "MyActor.h"
#include "Engine.h"

// Sets default values
AMyActor::AMyActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMyActor::BeginPlay()
{
	Super::BeginPlay();
	this->PrintOnScreen(1);
	GLog->Log("Hello World!");
	PlayerStats.Health = 100;
	AStaticMeshActor* StaticMesh = Cast<AStaticMeshActor>(SM);
	if (StaticMesh) {
		GLog->Log("The Actor you chose is a static mesh actor");
	}

	FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyActor::DoAPeriodicCheck, LoopTime, true);
}

// Called every frame 
void AMyActor::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);
}

void AMyActor::EndPlay(const EEndPlayReason::Type EndPlayReason)
{
	GLog->Log("Override endplay fuction");
	GLog->Log("PlayerStats.Health: " + FString::FromInt(PlayerStats.Health));
	Super::EndPlay(EndPlayReason);
}

void AMyActor::DoAPeriodicCheck()
{
	GLog->Log("Fire!!!");
}


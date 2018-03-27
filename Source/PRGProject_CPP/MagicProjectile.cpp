// Fill out your copyright notice in the Description page of Project Settings.

#include "MagicProjectile.h"


// Sets default values
AMagicProjectile::AMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

// Called when the game starts or when spawned
void AMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	OnActorBeginOverlap.AddDynamic(this, &AMagicProjectile::OnTriggerEnter);
	
}

// Called every frame
void AMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

void AMagicProjectile::OnTriggerEnter(AActor* OverlapedActor, AActor* OtherActor)
{
	if(!OtherActor->ActorHasTag("Player"))
	{
		Destroy();
		GLog->Log("BAM");
	}
}


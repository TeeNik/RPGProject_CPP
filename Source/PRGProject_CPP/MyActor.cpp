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

	/*FTimerHandle TimerHandle;
	GetWorld()->GetTimerManager().SetTimer(TimerHandle, this, &AMyActor::DoAPeriodicCheck, LoopTime, true);*/

	TArray<FHitResult> HitResults;
	FVector StartLocation = GetActorLocation();
	FVector EndLocation = GetActorLocation();
	EndLocation.Z += SphereHieght;

	ECollisionChannel ECC = ECollisionChannel::ECC_WorldStatic;
	FCollisionShape CollisionShape;
	CollisionShape.ShapeType = ECollisionShape::Sphere;
	CollisionShape.SetSphere(SphereRadius);

	bool bHitSomething = GetWorld()->SweepMultiByChannel(HitResults, StartLocation, EndLocation, FQuat::FQuat(), ECC, CollisionShape);
	if (bHitSomething) {
		for (auto It = HitResults.CreateIterator(); It; It++) {
			GLog->Log(It->Actor->GetName());
		}
	}

	FVector CenterOfSphere = ((EndLocation - StartLocation) / 2) + StartLocation;
	DrawDebugSphere(GetWorld(), CenterOfSphere, CollisionShape.GetSphereRadius(), Segments, FColor::Blue, true);

	for (auto It = NearbyActors.CreateIterator(); It; It++) {
		UStaticMeshComponent* SM = Cast<UStaticMeshComponent>((*It)->GetRootComponent());
		if (SM) {
			SM->AddRadialImpulse(GetActorLocation(), Radius, Strength, ERadialImpulseFalloff::RIF_Linear, true);
		}
	}

	FPlayerStats* Row = DataTable->FindRow<FPlayerStats>(TEXT("1"), TEXT(""));
	if (Row) {
		FString output = FString::FromInt((*Row).XpToLevel);
		GLog->Log(output);
	}

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


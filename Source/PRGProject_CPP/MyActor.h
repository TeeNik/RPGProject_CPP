// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerStats.h"
#include "Engine/DataTable.h"
#include "MyActor.generated.h"


UCLASS()
class PRGPROJECT_CPP_API AMyActor : public AActor
{
	GENERATED_BODY()
	
public:	
	AMyActor();
	virtual void BeginPlay() override;
	virtual void Tick(float DeltaTime) override;
	virtual void EndPlay(const EEndPlayReason::Type EndPlayReason) override;

	FPlayerStats PlayerStats;

	UPROPERTY(EditAnywhere)
	float Health;

	UFUNCTION(BlueprintImplementableEvent, Category="Output")
	void PrintOnScreen(int32 IntToPrint);
	
	UPROPERTY(EditAnywhere)
	AActor* SM;

	void DoAPeriodicCheck();

	UPROPERTY(EditAnywhere)
	float LoopTime;

	UPROPERTY(EditAnywhere, Category="Sweep")
	float SphereHieght = 200;
	UPROPERTY(EditAnywhere, Category = "Sweep")
	float SphereRadius = 500;
	UPROPERTY(EditAnywhere, Category = "Sweep")
	int32 Segments = 100;

	UPROPERTY(EditAnywhere, Category = "Bomb")
	float Radius;
	UPROPERTY(EditAnywhere, Category = "Bomb")
	float Strength;
	UPROPERTY(EditAnywhere, Category = "Bomb")
	TArray<AActor*> NearbyActors;

	UPROPERTY(EditAnywhere)
	UDataTable* DataTable;



};

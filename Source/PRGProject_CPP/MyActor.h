// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "PlayerStats.h"
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
	
	
};

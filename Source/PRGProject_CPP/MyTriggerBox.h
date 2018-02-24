// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Engine/TriggerBox.h"
#include "MyTriggerBox.generated.h"

/**
 * 
 */
UCLASS()
class PRGPROJECT_CPP_API AMyTriggerBox : public ATriggerBox
{
	GENERATED_BODY()
	
	/*Overriding the BeginPlay function*/
	virtual void BeginPlay() override;

	/*This function is called when an Actor enters the Trigger - PRE 4.12 version*/
	UFUNCTION()
	void OnTriggerEnter(AActor* Other);

	/*This function is called when an Actor exits the Trigger - PRE 4.12 version*/
	UFUNCTION()
	void OnTriggerExit(AActor* Other);

	/*This function is called when an Actor enters the Trigger - 4.12 version*/
	UFUNCTION()
	void OnTriggerEnter(AActor* OverlapedActor, AActor* OtherActor);

	/*This function is called when an Actor exits the Trigger - 4.12 version*/
	UFUNCTION()
	void OnTriggerExit(AActor* OverlapedActor, AActor* OtherActor);
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#include "FightController.h"

UFightController::UFightController()
{
	PrimaryComponentTick.bCanEverTick = true;
}

void UFightController::BeginPlay()
{
	Super::BeginPlay();
}

void UFightController::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);
}


// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceManagerLibrary.h"
#include "Engine/Engine.h"

UResourceManagerLibrary::UResourceManagerLibrary(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {

}

UResourceManager * UResourceManagerLibrary::GetResourceManagerData(bool & IsValid)
{
	IsValid = false;
	UResourceManager* Instance = Cast<UResourceManager>(GEngine->GameSingleton);

	if (!Instance) return NULL;
	if (!Instance->IsValidLowLevel()) return NULL;

	IsValid = true;
	return Instance;
}

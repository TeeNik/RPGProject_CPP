// Fill out your copyright notice in the Description page of Project Settings.

#include "ResourceManager.h"

UResourceManager::UResourceManager(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

UResourceManager* UResourceManager::GetInstance()
{
	return Cast<UResourceManager>(GEngine->GameSingleton);
}

TSubclassOf<AActor> UResourceManager::GetFireball()
{
	return GetInstance()->Fireball;
}

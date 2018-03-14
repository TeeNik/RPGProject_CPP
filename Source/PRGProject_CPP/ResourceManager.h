// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "ResourceManager.generated.h"

/**
 * 
 */
UCLASS(Blueprintable)
class PRGPROJECT_CPP_API UResourceManager : public UObject
{
	GENERATED_BODY()
	
	public:
		UResourceManager(const FObjectInitializer& ObjectInitializer);

		static UResourceManager Instance;

		UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Projectiles")
		TSubclassOf<AActor> Fireball;

		static UResourceManager* GetInstance();

		static TSubclassOf<AActor> GetFireball();	
	
	
};

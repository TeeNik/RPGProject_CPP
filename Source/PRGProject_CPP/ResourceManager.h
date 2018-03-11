// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "ResourceManager.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRGPROJECT_CPP_API UResourceManager : public USceneComponent
{
	GENERATED_BODY()

public:	
	UResourceManager();
	/*UResourceManager(const UResourceManager&);
	UResourceManager& operator=(UResourceManager&);*/

	static UResourceManager& GetInstance() {
		static UResourceManager instance;
		return instance;
	}

	UPROPERTY(EditDefaultsOnly, Category = "Projectiles")
		TSubclassOf<AActor> Fireball;

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

		
	
};

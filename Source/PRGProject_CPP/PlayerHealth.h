// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerHealth.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRGPROJECT_CPP_API UPlayerHealth : public UActorComponent
{
	GENERATED_BODY()

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPlayerHealth();
	void TakeDamage(float value);
	bool TakeMana(float value);

	UPROPERTY(EditAnywhere)
	float Health;
	float Mana;

protected:
	virtual void BeginPlay() override;
		
private:
	

	void Dead();
	
};

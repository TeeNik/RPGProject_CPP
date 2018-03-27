// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "PlayerHealth.generated.h"

UCLASS(Blueprintable, ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class PRGPROJECT_CPP_API UPlayerHealth : public UActorComponent
{
	GENERATED_BODY()

public:	
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	UPlayerHealth();
	void TakeDamage(float value);
	bool TakeMana(float value);

	UPROPERTY(BlueprintReadWrite, EditAnywhere) float MaxHealth;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) float MaxMana;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) float Health;
	UPROPERTY(BlueprintReadWrite, EditAnywhere) float Mana;

protected:
	virtual void BeginPlay() override;
		
private:
	

	void Dead();
	
};

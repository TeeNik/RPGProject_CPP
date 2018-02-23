// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"

/**
 * 
 */
UCLASS(BlueprintType)
class RPGPROJECT_CPP_API PlayerHealth
{
public:
	PlayerHealth();
	~PlayerHealth();

	float Health;
	float Mana;
};

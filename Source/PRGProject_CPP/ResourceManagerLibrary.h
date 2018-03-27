// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Kismet/BlueprintFunctionLibrary.h"
#include "ResourceManager.h"
#include "ResourceManagerLibrary.generated.h"

/**
 * 
 */
UCLASS()
class PRGPROJECT_CPP_API UResourceManagerLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UResourceManagerLibrary(const FObjectInitializer& ObjectInitializer);

	UFUNCTION(BlueprintPure, Category = "Resoure Manager Singletone")
	static UResourceManager* GetResourceManagerData();
	
	
};

// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "UpgradeComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG02_UECHAL2_API UUpgradeComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UUpgradeComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:
	// Called every frame
	UFUNCTION(BlueprintCallable) int SpawnRandom();
public:
	UPROPERTY(BlueprintReadWrite) bool hasSpawned;
	UPROPERTY(EditAnywhere, BlueprintReadWrite, meta = (AllowPrivateAccess = "true"))
		TArray<TSubclassOf<AActor>> ActorToSpawn;

	UFUNCTION(BlueprintCallable) TSubclassOf<AActor> GetActorToSpawn();
};

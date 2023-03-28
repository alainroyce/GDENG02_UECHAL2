// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeComponent.h"
#include <time.h>

// Sets default values for this component's properties
UUpgradeComponent::UUpgradeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UUpgradeComponent::BeginPlay()
{
	Super::BeginPlay();
	hasSpawned = false;
	// ...
	
}

int UUpgradeComponent::SpawnRandom()
{
	FActorSpawnParameters SpawnParams;

	int randomIndex = FMath::RandRange(0, ActorToSpawn.Num());
	if (randomIndex < ActorToSpawn.Num() && !hasSpawned) {
		const FVector Location = GetOwner()->GetActorLocation();;
		const FRotator Rotation = GetOwner()->GetActorRotation();
		GetWorld()->SpawnActor<AActor>(ActorToSpawn[randomIndex], Location, Rotation, SpawnParams);
		UE_LOG(LogTemp, Warning, TEXT("Spawning"));
		hasSpawned = true;
	}
	else {
		hasSpawned = true;
	}

	return randomIndex;
}

TSubclassOf<AActor> UUpgradeComponent::GetActorToSpawn()
{
	int randomIndex = FMath::RandRange(0, ActorToSpawn.Num());
	class TSubclassOf<AActor> actorToSpawn = ActorToSpawn[randomIndex];
	return actorToSpawn;
}





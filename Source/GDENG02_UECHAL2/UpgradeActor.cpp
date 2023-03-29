// Fill out your copyright notice in the Description page of Project Settings.


#include "UpgradeActor.h"
#include "DrawDebugHelpers.h"
#include "Components/SphereComponent.h"

// Sets default values
AUpgradeActor::AUpgradeActor()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	MyMesh = CreateDefaultSubobject<UStaticMeshComponent>(TEXT("MY MESH"));
	MyMesh->SetupAttachment(RootComponent);

	//myProjectile = 

}

void AUpgradeActor::setUpgradeType()
{
	myProjectile->bulletUpgrade = PowerUpType;
}

void AUpgradeActor::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	UE_LOG(LogTemp, Warning, TEXT("Other Actor Name: %s"), *OverlappedComponent->GetOwner()->GetName());

	//Logic to Pass Upgrade Type to Projectile

	//Destroy PickUp Object
	OverlappedComponent->GetOwner()->Destroy();
}



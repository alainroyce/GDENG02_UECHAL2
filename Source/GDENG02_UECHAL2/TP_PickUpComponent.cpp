// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_PickUpComponent.h"

UTP_PickUpComponent::UTP_PickUpComponent()
{
	// Setup the Sphere Collision
	SphereRadius = 32.f;
}

void UTP_PickUpComponent::BeginPlay()
{
	Super::BeginPlay();

	// Register our Overlap Event
	OnComponentBeginOverlap.AddDynamic(this, &UTP_PickUpComponent::OnSphereBeginOverlap);
}

void UTP_PickUpComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{
	// Checking if it is a First Person Character overlapping
	AGDENG02_UECHAL2Character* Character = Cast<AGDENG02_UECHAL2Character>(OtherActor);
	if(Character != nullptr)
	{
		// Notify that the actor is being picked up
		OnPickUp.Broadcast(Character);

		// Unregister from the Overlap Event so it is no longer triggered
		OnComponentBeginOverlap.RemoveAll(this);

		Character->currentBulletType = this->upgradeType;
		UE_LOG(LogTemp, Warning, TEXT("Current Bullet: %d"), Character->currentBulletType);

		switch (this->upgradeType)
		{
		case 1:
			// change projectile size to small
			UE_LOG(LogTemp, Warning, TEXT("Changing bullet: Small"));
			break;
		case 2:
			// change projectile size to large
			UE_LOG(LogTemp, Warning, TEXT("Changing bullet: Large"));
			break;
		case 3:
			// change projectile size to huge
			UE_LOG(LogTemp, Warning, TEXT("Changing bullet: Huge"));
			break;
		default:
			// change projectile size to normal
			UE_LOG(LogTemp, Warning, TEXT("Changing bullet: Normal"));
		}

		this->GetOwner()->Destroy();
		//OverlappedComponent->GetOwner()->Destroy();
	}
}

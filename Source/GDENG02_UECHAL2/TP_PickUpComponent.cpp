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
	UE_LOG(LogTemp, Warning, TEXT("Other Actor Name: %s"), *OverlappedComponent->GetOwner()->GetName());

	if(pickUpType == Weapon)
	{
		// Checking if it is a First Person Character overlapping
		AGDENG02_UECHAL2Character* Character = Cast<AGDENG02_UECHAL2Character>(OtherActor);
		if (Character != nullptr)
		{
			// Notify that the actor is being picked up
			OnPickUp.Broadcast(Character);

			// Unregister from the Overlap Event so it is no longer triggered
			OnComponentBeginOverlap.RemoveAll(this);
		}
	}
	else if (pickUpType == Upgrade) 
	{
		//this->Projectile = Cast<AGDENG02_UECHAL2Projectile>(OtherActor);
		
		//Logic to Pass Upgrade Type to Projectile

		myUpgrade->setUpgradeType();

		//Destroy PickUp Object
		OverlappedComponent->GetOwner()->Destroy();
	}
	
}

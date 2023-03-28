// Copyright Epic Games, Inc. All Rights Reserved.

#include "TP_PickUpComponent.h"
#include "GDENG02_UECHAL2Projectile.h"

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
		AGDENG02_UECHAL2Character* Character = Cast<AGDENG02_UECHAL2Character>(OtherActor);
		switch (pickUpUpgrade) 
		{
			case YellowCone: 
				// Takes Projectile and sets UpgradeType (from Projectile)
					break;
			case RedCylinder: 
				// Takes Projectile and sets UpgradeType (from Projectile)
					break;
			case WoodenBox: 
				// Takes Projectile and sets UpgradeType (from Projectile)
					break;
			case OrangeCapsule: 
				// Takes Projectile and sets UpgradeType (from Projectile)


					break;
		}
	}
	
}

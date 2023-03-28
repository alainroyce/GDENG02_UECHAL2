// Fill out your copyright notice in the Description page of Project Settings.


#include "TP_UpgradeComponent.h"
#include "GDENG02_UECHAL2Projectile.h"
#include "TP_PickUpComponent.h"

// Sets default values for this component's properties
UTP_UpgradeComponent::UTP_UpgradeComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UTP_UpgradeComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}

void UTP_UpgradeComponent::OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult)
{

}


// Called every frame
void UTP_UpgradeComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	// ...
}

void UTP_UpgradeComponent::UpgradeProjectile()
{
	switch (this->bulletUpgrade) 
	{
	case Shrink: 
		baseProjectile->SetActorRelativeScale3D(FVector(0.4,0.4,0.4));
		break;

	case Expand:
		baseProjectile->SetActorRelativeScale3D(FVector(5, 5, 5));
		break;

	case DoubleExpand:
		baseProjectile->SetActorRelativeScale3D(FVector(5, 5, 5));
		break;

	case Regular:
		baseProjectile->SetActorRelativeScale3D(FVector(1, 1, 1));
		break;

	default:
		baseProjectile->SetActorRelativeScale3D(FVector(1, 1, 1));
		this->bulletUpgrade = Regular;
		break;

	}


}


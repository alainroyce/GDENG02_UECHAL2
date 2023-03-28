// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "Components/SphereComponent.h"
#include "GDENG02_UECHAL2Projectile.h"
#include "GDENG02_UECHAL2Character.h"
#include "TP_PickUpComponent.generated.h"

// Declaration of the delegate that will be called when someone picks this up
// The character picking this up is the parameter sent with the notification
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(FOnPickUp, AGDENG02_UECHAL2Character*, PickUpCharacter);

UENUM(BlueprintType)
enum UpgradePickup
{
	YellowCone UMETA(DisplayName = "Bullet Shrink Upgrade"),
	RedCylinder UMETA(DisplayName = "Bullet Expand Upgrade"),
	WoodenBox UMETA(DisplayName = "Bullet Default Size Upgrade"),
	OrangeCapsule UMETA(DisplayName = "Bullet Extra Expand Upgrade")
};

UENUM(BlueprintType)
enum PickupType
{
	Upgrade UMETA(DisplayName = "Upgrade"), // Yellow Cone
	Weapon UMETA(DisplayName = "Weapon"), // Red Cylinder
};

UCLASS(Blueprintable, BlueprintType, ClassGroup = (Custom), meta = (BlueprintSpawnableComponent))
class GDENG02_UECHAL2_API UTP_PickUpComponent : public USphereComponent
{
	GENERATED_BODY()

public:
	
	/** Delegate to whom anyone can subscribe to receive this event */
	UPROPERTY(BlueprintAssignable, Category = "Interaction")
	FOnPickUp OnPickUp;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = PickupType)
		TEnumAsByte<PickupType> pickUpType;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UpgradePickup)
		TEnumAsByte<UpgradePickup> pickUpUpgrade;

	int upgradeResult;

	int GetUpgradeResult();

	AGDENG02_UECHAL2Projectile* Projectile;

	UTP_PickUpComponent();
protected:

	/** Called when the game starts */
	virtual void BeginPlay() override;

	/** Code for when something overlaps this component */
	UFUNCTION()
	void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};
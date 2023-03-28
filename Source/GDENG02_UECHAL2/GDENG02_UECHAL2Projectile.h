// Copyright Epic Games, Inc. All Rights Reserved.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "GDENG02_UECHAL2Projectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent;

UENUM(BlueprintType)
enum UpgradeType
{
	Shrink UMETA(DisplayName = "Bullet Shrink Upgrade"), // Yellow Cone
	Expand UMETA(DisplayName = "Bullet Expand Upgrade"), // Red Cylinder
	Regular UMETA(DisplayName = "Bullet Default Size Upgrade"), // Wooden Box
	DoubleExpand UMETA(DisplayName = "Bullet Extra Expand Upgrade") // Orange Capsule
};

UCLASS(config=Game)
class AGDENG02_UECHAL2Projectile : public AActor
{
	GENERATED_BODY()

	/** Sphere collision component */
	UPROPERTY(VisibleDefaultsOnly, Category=Projectile)
	USphereComponent* CollisionComp;

	/** Projectile movement component */
	UPROPERTY(VisibleAnywhere, BlueprintReadOnly, Category = Movement, meta = (AllowPrivateAccess = "true"))
	UProjectileMovementComponent* ProjectileMovement;

public:
	AGDENG02_UECHAL2Projectile();

	void BeginPlay();

	/** called when projectile hits something */
	UFUNCTION()
	void OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit);

	/** Returns CollisionComp subobject **/
	USphereComponent* GetCollisionComp() const { return CollisionComp; }
	/** Returns ProjectileMovement subobject **/
	UProjectileMovementComponent* GetProjectileMovement() const { return ProjectileMovement; }

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UpgradeType)
		TEnumAsByte<UpgradeType> bulletUpgrade;

	// Logic for Bullet Upgrades
	void UpgradeProjectile();
};


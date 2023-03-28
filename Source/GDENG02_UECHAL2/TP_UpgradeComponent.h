// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/SceneComponent.h"
#include "GDENG02_UECHAL2Character.h"
#include "TP_UpgradeComponent.generated.h"

UENUM(BlueprintType)
enum UpgradeType
{
	Shrink UMETA(DisplayName = "Bullet Shrink Upgrade"), // Yellow Cone
	Expand UMETA(DisplayName = "Bullet Expand Upgrade"), // Red Cylinder
	Regular UMETA(DisplayName = "Bullet Default Size Upgrade"), // Wooden Box
	DoubleExpand UMETA(DisplayName = "Bullet Extra Expand Upgrade") // Orange Capsule
};

UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class GDENG02_UECHAL2_API UTP_UpgradeComponent : public USceneComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UTP_UpgradeComponent();



protected:
	// Called when the game starts
	virtual void BeginPlay() override;

	UFUNCTION()
		void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = UpgradeType)
		TEnumAsByte<UpgradeType> bulletUpgrade;

	// Logic for Bullet Upgrades
	void UpgradeProjectile();

private:

	// Player Projectile
	AGDENG02_UECHAL2Projectile* baseProjectile;
};

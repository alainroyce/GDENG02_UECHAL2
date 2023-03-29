// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "Components/SphereComponent.h"
#include "GDENG02_UECHAL2Character.h"
#include "GDENG02_UECHAL2Projectile.h"
#include "UpgradeActor.generated.h"

UCLASS()
class GDENG02_UECHAL2_API AUpgradeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUpgradeActor();

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite) 
		int PowerUpType;
	UPROPERTY(VisibleAnywhere) 
		class UStaticMeshComponent* MyMesh;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		AGDENG02_UECHAL2Projectile* myProjectile;

	void setUpgradeType();

protected:
	UFUNCTION()
		void OnSphereBeginOverlap(UPrimitiveComponent* OverlappedComponent, AActor* OtherActor, UPrimitiveComponent* OtherComp, int32 OtherBodyIndex, bool bFromSweep, const FHitResult& SweepResult);
};

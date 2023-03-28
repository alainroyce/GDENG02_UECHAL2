// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "UpgradeActor.generated.h"

UCLASS()
class GDENG02_UECHAL2_API AUpgradeActor : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AUpgradeActor();

public:	

	UPROPERTY(EditAnywhere, BlueprintReadWrite) int PowerUpType;
	UPROPERTY(VisibleAnywhere) class UStaticMeshComponent* MyMesh;

};

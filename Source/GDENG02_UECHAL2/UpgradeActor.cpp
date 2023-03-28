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

}



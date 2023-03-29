// Copyright Epic Games, Inc. All Rights Reserved.

#include "GDENG02_UECHAL2Projectile.h"
#include "GameFramework/ProjectileMovementComponent.h"
#include "Components/SphereComponent.h"


void AGDENG02_UECHAL2Projectile::BeginPlay()
{
	Super::BeginPlay();

	this->projectileMesh = this->FindComponentByClass<UStaticMeshComponent>();
	if (this->projectileMesh != nullptr)
	{
		UE_LOG(LogTemp, Warning, TEXT("Projectile staticMesh found!!!"));
	}

	APlayerController* playerController = GetWorld()->GetFirstPlayerController();
	if (playerController != nullptr)
	{
		this->Character = Cast<AGDENG02_UECHAL2Character>(playerController->GetPawn());
		if (this->Character != nullptr)
		{
			UE_LOG(LogTemp, Warning, TEXT("new bullet type: %d"), this->Character->currentBulletType);

			switch (this->Character->currentBulletType) 
			{
			case 1:
				CollisionComp->SetWorldScale3D(FVector(0.5f, 0.5f, 0.5f));
				//this->projectileMesh->SetRelativeScale3D(FVector(0.1f, 0.1f, 0.1f));
				//CollisionComp->SetSphereRadius(15.0f);
				//this->SetActorScale3D(FVector(0.5f, 0.5f, 0.5f));
				UE_LOG(LogTemp, Warning, TEXT("Changing bullet: Small"));
				break;
			case 2:
				CollisionComp->SetWorldScale3D(FVector(2.5f, 2.5f, 2.5f));
				//this->projectileMesh->SetRelativeScale3D(FVector(0.5f, 0.5f, 0.5f));
				//CollisionComp->SetSphereRadius(75.0f);
				//this->SetActorScale3D(FVector(1.5f, 1.5f, 1.5f));
				UE_LOG(LogTemp, Warning, TEXT("Changing bullet: Large"));
				break;
			case 3:
				CollisionComp->SetWorldScale3D(FVector(5.0f, 5.0f, 5.0f));
				//this->projectileMesh->SetRelativeScale3D(FVector(1.0f, 1.0f, 1.0f));
				//CollisionComp->SetSphereRadius(150.0f);
				//this->SetActorScale3D(FVector(2.0f, 2.0f, 2.0f));
				UE_LOG(LogTemp, Warning, TEXT("Changing bullet: Huge"));
				break;
			default:
				CollisionComp->SetWorldScale3D(FVector(1.0f, 1.0f, 1.0f));
				//this->projectileMesh->SetRelativeScale3D(FVector(0.2f, 0.2f, 0.2f));
				//CollisionComp->SetSphereRadius(30.0f);
				//this->SetActorScale3D(FVector(1.0f, 1.0f, 1.0f));
				UE_LOG(LogTemp, Warning, TEXT("Changing bullet: Normal"));
			}
		}
	}
}

AGDENG02_UECHAL2Projectile::AGDENG02_UECHAL2Projectile()
{
	// Use a sphere as a simple collision representation
	CollisionComp = CreateDefaultSubobject<USphereComponent>(TEXT("SphereComp"));
	CollisionComp->InitSphereRadius(5.0f);
	CollisionComp->BodyInstance.SetCollisionProfileName("Projectile");
	CollisionComp->OnComponentHit.AddDynamic(this, &AGDENG02_UECHAL2Projectile::OnHit);		// set up a notification for when this component hits something blocking

	// Players can't walk on it
	CollisionComp->SetWalkableSlopeOverride(FWalkableSlopeOverride(WalkableSlope_Unwalkable, 0.f));
	CollisionComp->CanCharacterStepUpOn = ECB_No;

	// Set as root component
	RootComponent = CollisionComp;

	// Use a ProjectileMovementComponent to govern this projectile's movement
	ProjectileMovement = CreateDefaultSubobject<UProjectileMovementComponent>(TEXT("ProjectileComp"));
	ProjectileMovement->UpdatedComponent = CollisionComp;
	ProjectileMovement->InitialSpeed = 3000.f;
	ProjectileMovement->MaxSpeed = 3000.f;
	ProjectileMovement->bRotationFollowsVelocity = true;
	ProjectileMovement->bShouldBounce = true;

	// Die after 3 seconds by default
	InitialLifeSpan = 0.0f;
}

void AGDENG02_UECHAL2Projectile::OnHit(UPrimitiveComponent* HitComp, AActor* OtherActor, UPrimitiveComponent* OtherComp, FVector NormalImpulse, const FHitResult& Hit)
{
	// Only add impulse and destroy projectile if we hit a physics
	if ((OtherActor != nullptr) && (OtherActor != this) && (OtherComp != nullptr) && OtherComp->IsSimulatingPhysics())
	{
		OtherComp->AddImpulseAtLocation(GetVelocity() * 100.0f, GetActorLocation());

		//Destroy();
	}
}
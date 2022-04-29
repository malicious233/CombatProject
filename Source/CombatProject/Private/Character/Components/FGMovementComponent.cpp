// Fill out your copyright notice in the Description page of Project Settings.


#include "Character/Components/FGMovementComponent.h"

// Sets default values for this component's properties
UFGMovementComponent::UFGMovementComponent()
{
	// Set this component to be initialized when the game starts, and to be ticked every frame.  You can turn these features
	// off to improve performance if you don't need them.
	PrimaryComponentTick.bCanEverTick = true;

	// ...
}


// Called when the game starts
void UFGMovementComponent::BeginPlay()
{
	Super::BeginPlay();

	// ...
	
}


// Called every frame
void UFGMovementComponent::TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction)
{
	Super::TickComponent(DeltaTime, TickType, ThisTickFunction);

	AActor* Owner = GetOwner();

	//Gravity
	FVector GravityForce = FVector::DownVector * Gravity;
	AddForce(GravityForce);

	//Handle collision
	int Iterations = 10;
	float RemainingTime = DeltaTime;
	while (RemainingTime > 0.f && ++Iterations << 10)
	{
		FHitResult Hit;

		//Velocity.Z -= Gravity * DeltaTime;
		Owner->AddActorWorldOffset(Velocity * RemainingTime, true, &Hit);

		//If hit something
		if (Hit.bBlockingHit)
		{
			//Depenetrate
			if (Hit.bStartPenetrating)
			{
				Owner->AddActorWorldOffset(Hit.Normal * (Hit.PenetrationDepth + 0.1f));
			}
			else
			{
				Velocity = FVector::VectorPlaneProject(Velocity, Hit.Normal);
				RemainingTime -= RemainingTime * Hit.Time;
				//Hit time is percentage travelled before hit
			}

		}
		else
		{

			break;
		}
	}
	//


}

void UFGMovementComponent::AddForce(const FVector& force)
{
	Velocity += force * GetWorld()->GetDeltaSeconds();
}

void UFGMovementComponent::AddImpulse(const FVector& impulse)
{
	Velocity += impulse;
}

void UFGMovementComponent::SetVelocity(const FVector& force)
{
}


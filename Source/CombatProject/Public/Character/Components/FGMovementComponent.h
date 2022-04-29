// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "Components/ActorComponent.h"
#include "FGMovementComponent.generated.h"


UCLASS( ClassGroup=(Custom), meta=(BlueprintSpawnableComponent) )
class COMBATPROJECT_API UFGMovementComponent : public UActorComponent
{
	GENERATED_BODY()

public:	
	// Sets default values for this component's properties
	UFGMovementComponent();

protected:
	// Called when the game starts
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void TickComponent(float DeltaTime, ELevelTick TickType, FActorComponentTickFunction* ThisTickFunction) override;




	UFUNCTION(BlueprintCallable)
	void AddForce(const FVector& force);

	UFUNCTION(BlueprintCallable)
	void AddImpulse(const FVector& impulse);

	UFUNCTION(BlueprintCallable)
	void SetVelocity(const FVector& force);

	UPROPERTY()
	FVector Velocity = FVector::ZeroVector;

	UPROPERTY(EditAnywhere)
	float Gravity;
		
};

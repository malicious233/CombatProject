// Fill out your copyright notice in the Description page of Project Settings.



#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "CombatProject/CharacterState.h"
#include "CombatProject/BaseState.h"
#include "BaseCharacter.generated.h"


UENUM()
enum class EState : uint8
{
	NONE,
	IDLE,
	WALKING,
	AIRBORNE,
	ATTACKING,
};


class USphereComponent;
class BaseState;

UCLASS()
class COMBATPROJECT_API ABaseCharacter : public APawn
{
	GENERATED_BODY()

private:
	UPROPERTY(EditAnywhere, Category = Combat)
	USphereComponent* Hurtbox;

protected:

	// Called when the game starts or when spawned
	ABaseCharacter();
	
	virtual void BeginPlay() override;



public:	

	UPROPERTY(EditDefaultsOnly)
	float WalkSpeed;

	
	UFUNCTION(BlueprintCallable)
	//Sets state of the character via given enum.
	virtual void SetState(EState ToState); 

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	BaseState* ActiveState; //Watch this guy cause a memory leak. Keep an eye on this
	

	


};



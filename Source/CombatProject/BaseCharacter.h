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
};


class USphereComponent;

UCLASS()
class COMBATPROJECT_API ABaseCharacter : public APawn
{
	GENERATED_BODY()

private:

	// Sets default values for this pawn's properties
	ABaseCharacter();
	

	class AttackingState : public BaseState
	{
	public:
		AttackingState();

		virtual void Leave() override;
		virtual void Tick(float DeltaTime) override;
	};
	


	

	UPROPERTY(EditAnywhere, Category = Combat)
		USphereComponent* Hurtbox;

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	

	BaseState* ActiveState; //Watch this guy if he causes a memory leak. This pointer scares me.

	AttackingState AttackState;

	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;


	

	


};



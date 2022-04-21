// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Components/SphereComponent.h"
#include "CombatProject/CharacterState.h"
#include "CombatProject/BaseState.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;
	Hurtbox = CreateDefaultSubobject<USphereComponent>(TEXT("Hurtbox"));
	ActiveState = &AttackState;
}

// Called when the game starts or when spawned
void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();

	
}

// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	ActiveState->Tick(DeltaTime);

}



// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}

#pragma region AttackState
ABaseCharacter::AttackingState::AttackingState()
{
	
}

void ABaseCharacter::AttackingState::Leave()
{
	//Despawn hitboxes
}



void ABaseCharacter::AttackingState::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Purple, TEXT("From C++ Wooo"));
}

#pragma endregion

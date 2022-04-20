// Fill out your copyright notice in the Description page of Project Settings.


#include "BaseCharacter.h"
#include "Components/SphereComponent.h"
#include "CombatProject/CharacterState.h"
#include "CombatProject/StateIdle.h"

// Sets default values
ABaseCharacter::ABaseCharacter()
{
 	// Set this pawn to call Tick() every frame.  You can turn this off to improve performance if you don't need it.

	PrimaryActorTick.bCanEverTick = true;
	Hurtbox = CreateDefaultSubobject<USphereComponent>(TEXT("Hurtbox"));
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

void ABaseCharacter::SetState(UCharacterState* ToState) //Be wary not to call this when state is null lol
{
	ActiveState->Leave();
	ActiveState = ToState; //Sets active states address to the new states address. thats how it does it right?
	ActiveState->Enter();
}

// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}





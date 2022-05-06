// Fill out your copyright notice in the Description page of Project Settings.



#include "BaseCharacter.h"
#include "Components/SphereComponent.h"
#include "CombatProject/Character/BaseState.h"

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


void ABaseCharacter::SetState(EState ToState)
{
}

EState ABaseCharacter::GetState()
{
	return EState::NONE;
}




// Called every frame
void ABaseCharacter::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
	ActiveState->Tick(DeltaTime);

}



// Called to bind functionality to input
void ABaseCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


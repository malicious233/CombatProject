// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatProject/Character/Fighter/FighterIdleState.h"
#include "FighterCharacter.h"
#include "CombatProject/Character/Components/StateInputBinderComponent.h"
#include "CombatProject/Public/Character/Components/FGMovementComponent.h"

void UFighterIdleState::InitializeState(AFighterCharacter* owner)
{
	UFighterState::InitializeState(owner);
}

void UFighterIdleState::Tick(float DeltaTime)
{
	Fighter->ActiveState->BPTick(DeltaTime);

	Fighter->MoveComp->PhysicsTick(DeltaTime);
}

void UFighterIdleState::Enter()
{
	FInputAxisBinding bind = Fighter->InputComponent->BindAxis(TEXT("MovementAxis"), Fighter, &AFighterCharacter::HandleWalk);
	Fighter->InputBinderComp->AddAxisBinding(bind);
}

void UFighterIdleState::Leave()
{
	Fighter->InputBinderComp->EmptyAllBindings(*(Fighter->InputComponent));
}
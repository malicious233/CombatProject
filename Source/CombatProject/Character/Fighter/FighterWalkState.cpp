// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatProject/Character/Fighter/FighterWalkState.h"
#include "FighterCharacter.h"
#include "CombatProject/Character/Components/StateInputBinderComponent.h"
#include "CombatProject/Public/Character/Components/FGMovementComponent.h"

void UFighterWalkState::InitializeState(AFighterCharacter* owner)
{
	UFighterState::InitializeState(owner);
}

void UFighterWalkState::Tick(float DeltaTime)
{
	Fighter->ActiveState->BPTick(DeltaTime);
	//Fighter->MoveComp->Velocity = FVector::RightVector * Fighter->InputAxis * Fighter->MoveComp->WalkSpeed;
	Fighter->MoveComp->AddForceClamped(Fighter->MoveComp->WalkSpeed * Fighter->InputAxis * FVector::RightVector, Fighter->MoveComp->MaxSpeed);
	Fighter->MoveComp->PhysicsTick(DeltaTime);

}

void UFighterWalkState::Enter()
{
	FInputAxisBinding bind = Fighter->InputComponent->BindAxis(TEXT("MovementAxis"), Fighter, &AFighterCharacter::HandleStopWalk);
	Fighter->InputBinderComp->AddAxisBinding(bind);
}

void UFighterWalkState::Leave()
{
	Fighter->InputBinderComp->EmptyAllBindings(*(Fighter->InputComponent));
}
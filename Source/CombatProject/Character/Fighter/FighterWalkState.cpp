// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatProject/Character/Fighter/FighterWalkState.h"
#include "FighterCharacter.h"

void UFighterWalkState::InitializeState(AFighterCharacter* owner)
{
	owner->WalkState = this;
}

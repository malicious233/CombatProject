// Fill out your copyright notice in the Description page of Project Settings.


#include "CombatProject/Character/Fighter/FighterState.h"

AFighterCharacter* UFighterState::GetFighter()
{
	return Fighter;
}

void UFighterState::InitializeState(AFighterCharacter* owner)
{
	Fighter = owner;
}

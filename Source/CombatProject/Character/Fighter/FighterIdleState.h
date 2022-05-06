// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatProject/Character/Fighter/FighterState.h"
#include "FighterIdleState.generated.h"

/**
 * 
 */
UCLASS()
class COMBATPROJECT_API UFighterIdleState : public UFighterState
{
	GENERATED_BODY()
public:

	virtual void InitializeState(AFighterCharacter* owner) override;
	virtual void Tick(float DeltaTime) override;
	
};

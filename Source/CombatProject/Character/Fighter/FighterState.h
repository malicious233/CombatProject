// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "CombatProject/Character/BaseState.h"
#include "FighterState.generated.h"

/**
 * 
 */

class AFighterCharacter;

UCLASS()
class COMBATPROJECT_API UFighterState : public UBaseState
{
	GENERATED_BODY()
	
public:
	UPROPERTY()
	AFighterCharacter* Fighter;

	UFUNCTION(BlueprintCallable)
	AFighterCharacter* GetFighter();

	virtual void InitializeState(AFighterCharacter* owner);

	UFUNCTION(BlueprintImplementableEvent)
	void InitializeStateBP(AFighterCharacter* owner);


};

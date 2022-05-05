#pragma once

#include "CombatProject/Character/BaseCharacter.h"
#include "CombatProject/Character/BaseState.h "
#include "FighterCharacter.generated.h"

class UStateInputBinderComponent;
class UFGMovementComponent;
class UFighterIdleState;
class UFighterWalkState;


UCLASS()
class AFighterCharacter : public ABaseCharacter
{
	GENERATED_BODY()


private:
	///States////

	
	///

public:
	
	AFighterCharacter();

	

	///Overrides///

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SetState(EState ToState) override;

	///

	///MiscFunctions///

	void HandleWalk(float axisValue);
	void HandleStopWalk(float axisValue);
	void HandleJump();
	///

	UPROPERTY(VisibleAnywhere)
		UStateInputBinderComponent* InputBinderComp;

	UPROPERTY(VisibleAnywhere)
		UFGMovementComponent* MoveComp;

	///States
	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UFighterIdleState> IdleStateClass;
	UPROPERTY()
		UFighterIdleState* IdleState;

	UPROPERTY(EditDefaultsOnly)
		TSubclassOf<UFighterWalkState> WalkStateClass;
	UPROPERTY()
		UFighterWalkState* WalkState;
	

private:
	float InputAxis;

};
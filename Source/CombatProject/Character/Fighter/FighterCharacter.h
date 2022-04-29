#pragma once

#include "CombatProject/Character/BaseCharacter.h"
#include "CombatProject/Character/BaseState.h "
#include "FighterCharacter.generated.h"

class UStateInputBinderComponent;
class UFGMovementComponent;

UCLASS()
class AFighterCharacter : public ABaseCharacter
{
	GENERATED_BODY()


private:
	///States////

	class BaseFighterState
	{
	public:
		AFighterCharacter* Fighter;
	};

	class IdleState : public BaseState, public BaseFighterState
	{
	public:
		virtual void Enter() override;
		virtual void Leave() override;
		virtual void Tick(float DeltaTime) override;

	};

	class WalkState : public BaseState, public BaseFighterState
	{
	public:
		virtual void Enter() override;
		virtual void Leave() override;
		virtual void Tick(float DeltaTime) override;
	};

	IdleState IdleState;
	WalkState WalkState;
	///

public:
	
	AFighterCharacter();

	UPROPERTY(VisibleAnywhere)
	UStateInputBinderComponent* InputBinderComp;

	UPROPERTY(VisibleAnywhere)
	UFGMovementComponent* MoveComp;

	///Overrides///

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SetState(EState ToState) override;

	///

	///MiscFunctions///

	void HandleWalk(float axisValue);
	void HandleStopWalk(float axisValue);
	///

private:
	float InputAxis;

public:
	friend class BaseState; //Oh not in the double inheritance AAAAAAAAAAAAAA

};
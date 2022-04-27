#pragma once

#include "CombatProject/Character/BaseCharacter.h"
#include "CombatProject/Character/BaseState.h"
#include "FighterCharacter.generated.h"


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

	

	///Overrides///

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	virtual void SetState(EState ToState) override;

	///

	///MiscFunctions///

	void HandleWalk(float inputAxis);
	void HandleStopWalk(float inputAxis);

	///

};
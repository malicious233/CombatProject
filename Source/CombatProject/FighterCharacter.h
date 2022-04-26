#pragma once

#include "BaseCharacter.h"
#include "FighterCharacter.generated.h"

class ABaseCharacter;

UCLASS()
class AFighterCharacter : public ABaseCharacter
{
	GENERATED_BODY()

public:
	
	AFighterCharacter();

	//States

	class BaseFighterState
	{
	public:
		AFighterCharacter* Fighter;
	};

	class IdleState : public BaseState, public BaseFighterState
	{
	public:
		virtual void Enter() override;
		virtual void Tick(float DeltaTime) override;
		
	};

	class WalkState : public BaseState, public BaseFighterState
	{
	public:
		virtual void Enter() override;
		virtual void Tick(float DeltaTime) override;
	};

	IdleState IdleState;
	WalkState WalkState;
	//

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetState(EState ToState) override;


};
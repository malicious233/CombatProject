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

	class IdleStateClass : public BaseIdleState, public BaseFighterState
	{
	public:
		virtual void Enter() override;
		virtual void Tick(float DeltaTime) override;
		
	};

	class WalkStateClass : public BaseWalkState, public BaseFighterState
	{
	public:
		virtual void Enter() override;
		virtual void Tick(float DeltaTime) override;
	};

	IdleStateClass IdleState;
	WalkStateClass WalkState;
	//

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetState(EState ToState) override;

	virtual void Walk(FVector InputVector) override;

};
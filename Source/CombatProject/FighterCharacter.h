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
	class IdleStateClass : public BaseIdleState
	{
	public:
		virtual void Enter() override;
		virtual void Tick(float DeltaTime) override;
	};

	class WalkStateClass : public BaseWalkState
	{
	public:
		virtual void Enter() override;
	};

	IdleStateClass IdleState;
	WalkStateClass WalkState;
	//

	virtual void Tick(float DeltaTime) override;

	virtual void BeginPlay() override;

	virtual void SetState(EState ToState) override;

};
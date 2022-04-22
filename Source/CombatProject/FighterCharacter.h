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

	class IdleStateClass : public BaseIdleState
	{
	public:
	};

	class WalkStateClass : public BaseWalkState
	{
	public:
	};

	IdleStateClass IdleState;
	WalkStateClass WalkState;

	virtual void SetState(EState ToState) override;

};
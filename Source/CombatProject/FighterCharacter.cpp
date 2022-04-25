#include "CombatProject/FighterCharacter.h"
#include "CombatProject/BaseState.h"

AFighterCharacter::AFighterCharacter()
{
	ActiveState = &IdleState;
	IdleState.Fighter = this;
	WalkState.Fighter = this;
	
}



void AFighterCharacter::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
	ABaseCharacter::Tick(DeltaTime);

	
	
}

void AFighterCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetState(EState::WALKING);
	
	
}

void AFighterCharacter::SetState(EState ToState)
{
	switch (ToState)
	{
	case EState::IDLE:
		ActiveState->Leave();
		ActiveState = &IdleState;
		ActiveState->Enter();
		break;
	case EState::WALKING:
		ActiveState->Leave();
		ActiveState = &WalkState;
		ActiveState->Enter();
		break;
	}
}

void AFighterCharacter::Walk(FVector InputVector)
{
	Move(InputVector * WalkSpeed);
}




#pragma region IdleState
void AFighterCharacter::IdleStateClass::Enter()
{

}

void AFighterCharacter::IdleStateClass::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Purple, TEXT("Is Idle"));
}

#pragma endregion

#pragma region WalkState
void AFighterCharacter::WalkStateClass::Enter()
{

}

void AFighterCharacter::WalkStateClass::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Purple, TEXT("Is Walking"));
	Fighter->Walk(Fighter->InputDirection);
}



#pragma endregion
#include "CombatProject/FighterCharacter.h"
#include "CombatProject/BaseState.h"

AFighterCharacter::AFighterCharacter()
{
	ActiveState = &IdleState;
	
}



void AFighterCharacter::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
	ABaseCharacter::Tick(DeltaTime);

	
	
}

void AFighterCharacter::BeginPlay()
{
	Super::BeginPlay();
	SetState(EState::IDLE);
	
	
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


#pragma region IdleState
void AFighterCharacter::IdleStateClass::Enter()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Purple, TEXT("Entered Idle"));
}

void AFighterCharacter::IdleStateClass::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Purple, TEXT("Is Idle"));
}

#pragma endregion

#pragma region WalkState
void AFighterCharacter::WalkStateClass::Enter()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Purple, TEXT("Entered Walk"));
}
#pragma endregion
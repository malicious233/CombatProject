#include "CombatProject/FighterCharacter.h"
#include "CombatProject/BaseState.h"

AFighterCharacter::AFighterCharacter()
{
	ActiveState = &IdleState;
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

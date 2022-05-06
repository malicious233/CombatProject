#include "FighterCharacter.h"
#include "CombatProject/Character/BaseState.h"
#include "CombatProject/Character/BaseCharacter.h"
#include "CombatProject/Character/Components/StateInputBinderComponent.h"
#include "Character/Components/FGMovementComponent.h"
#include "CombatProject/Character/Fighter/FighterIdleState.h"
#include "CombatProject/Character/Fighter/FighterWalkState.h"


AFighterCharacter::AFighterCharacter()
{
	InputBinderComp = CreateDefaultSubobject<UStateInputBinderComponent>(TEXT("StateInputBinderComponent"));
	MoveComp = CreateDefaultSubobject<UFGMovementComponent>(TEXT("MovementComponent"));

	
	
}



void AFighterCharacter::Tick(float DeltaTime)
{
	//Super::Tick(DeltaTime);
	ABaseCharacter::Tick(DeltaTime);

	
	
}

void AFighterCharacter::BeginPlay()
{
	Super::BeginPlay();

	//Remember to both initialize and set the Fighter reference to itself... I should make this into a function.
	IdleState = NewObject<UFighterIdleState>(this, IdleStateClass);
	IdleState->InitializeState(this);

	WalkState = NewObject<UFighterWalkState>(this, WalkStateClass);
	WalkState->InitializeState(this);

	ActiveState = IdleState;

	SetState(EState::IDLE);
	
	
}

void AFighterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	//PlayerInputComponent->BindAxis(TEXT("MovementAxis"), this, &AFighterCharacter::HandleWalk);
}

void AFighterCharacter::SetState(EState ToState)
{

	//This bit is ugly boilerplatey... I should add a function in BaseState for switching state which calls leave, BP leave and so on.
	switch (ToState)
	{
	case EState::IDLE:
		ActiveState->Leave();
		ActiveState->BPLeave();
		ActiveState = IdleState;
		ActiveState->Enter();
		ActiveState->BPEnter();
		break;
	case EState::WALKING:
		ActiveState->Leave();
		ActiveState->BPLeave();
		ActiveState = WalkState;
		ActiveState->Enter();
		ActiveState->BPEnter();
		break;
	}
}






#pragma region IdleState

void UFighterIdleState::Tick(float DeltaTime)
{
	Fighter->ActiveState->BPTick(DeltaTime);
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Purple, TEXT("From C++ Wooo"));
	
}




#pragma endregion

#pragma region AirborneState



#pragma endregion 

void AFighterCharacter::HandleWalk(float axisValue)
{
	if (axisValue != 0)
	{
		InputAxis = axisValue;
		SetState(EState::WALKING);
		
	}
		
}

void AFighterCharacter::HandleStopWalk(float axisValue)
{
	if (axisValue == 0)
	{
		InputAxis = axisValue;
		MoveComp->Velocity.X = 0;
		SetState(EState::IDLE);
	}
		
}


void AFighterCharacter::HandleJump()
{
	MoveComp->Velocity.Z = 200.f;
	SetState(EState::AIRBORNE);
}



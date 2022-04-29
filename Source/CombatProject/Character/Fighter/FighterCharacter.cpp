#include "FighterCharacter.h"
#include "CombatProject/Character/BaseState.h"
#include "CombatProject/Character/BaseCharacter.h"
#include "CombatProject/Character/Components/StateInputBinderComponent.h"
#include "Character/Components/FGMovementComponent.h"

AFighterCharacter::AFighterCharacter()
{
	InputBinderComp = CreateDefaultSubobject<UStateInputBinderComponent>(TEXT("StateInputBinderComponent"));
	MoveComp = CreateDefaultSubobject<UFGMovementComponent>(TEXT("MovementComponent"));

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
	SetState(EState::IDLE);
	
	
}

void AFighterCharacter::SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent)
{
	//PlayerInputComponent->BindAxis(TEXT("MovementAxis"), this, &AFighterCharacter::HandleWalk);
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
void AFighterCharacter::IdleState::Enter()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Purple, TEXT("Enter Idle"));

	FInputAxisBinding bind = Fighter->InputComponent->BindAxis(TEXT("MovementAxis"), Fighter, &AFighterCharacter::HandleWalk);
	Fighter->InputBinderComp->AddAxisBinding(bind);

	//Calling this without an initialized character controller touches a null pointer.
	//Apparently the inputcomponent is initialized with the character controller. Is it time for some defensive programming?
	
	
}

void AFighterCharacter::IdleState::Leave()
{
	Fighter->InputBinderComp->EmptyAxisBindings(*(Fighter->InputComponent));
	
}

void AFighterCharacter::IdleState::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, DeltaTime, FColor::Purple, TEXT("Is Idle"));
	
}

#pragma endregion

#pragma region WalkState
void AFighterCharacter::WalkState::Enter()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Purple, TEXT("Enter Walk"));

	FInputAxisBinding bind = Fighter->InputComponent->BindAxis(TEXT("MovementAxis"), Fighter, &AFighterCharacter::HandleStopWalk);
	Fighter->InputBinderComp->AddAxisBinding(bind);

	//Look into how to make the lambda expression to make it prettier. I dont want 2000 random functions lying around. Or do I?
}

void AFighterCharacter::WalkState::Leave()
{
	Fighter->InputBinderComp->EmptyAxisBindings(*(Fighter->InputComponent));
}

void AFighterCharacter::WalkState::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, DeltaTime, FColor::Purple, TEXT("Is Walking"));
}



#pragma endregion

void AFighterCharacter::HandleWalk(float axisValue)
{
	if (axisValue != 0)
		SetState(EState::WALKING);
}

void AFighterCharacter::HandleStopWalk(float axisValue)
{
	if (axisValue == 0)
		SetState(EState::IDLE);
}



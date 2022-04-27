#include "FighterCharacter.h"
#include "CombatProject/Character/BaseState.h"
#include "CombatProject/Character/BaseCharacter.h"
#include "CombatProject/Character/Components/StateInputBinderComponent.h"

AFighterCharacter::AFighterCharacter()
{
	InputBinderComp = CreateDefaultSubobject<UStateInputBinderComponent>(TEXT("StateInputBinderComponent"));

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
	
}

void AFighterCharacter::IdleState::Leave()
{
	//Fighter->InputComponent->AxisBindings.Empty();
	//Figure out how to not have to clear every single inputBinding and only clear the ones bound when entering state
	Fighter->InputBinderComp->EmptyAxisBindings(*(Fighter->InputComponent));
	
}

void AFighterCharacter::IdleState::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Purple, TEXT("Is Idle"));
	
}

#pragma endregion

#pragma region WalkState
void AFighterCharacter::WalkState::Enter()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Purple, TEXT("Enter Walk"));
	
	//Fighter->InputComponent->BindAxis(TEXT("MovementAxis"), Fighter, &AFighterCharacter::HandleStopWalk);
	//Look into how to make the lambda expression to make it prettier. I dont want 2000 random functions lying around
}

void AFighterCharacter::WalkState::Leave()
{
	//Fighter->InputComponent->AxisBindings.Empty();
}

void AFighterCharacter::WalkState::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 0.f, FColor::Purple, TEXT("Is Walking"));
}



#pragma endregion

void AFighterCharacter::HandleWalk(float axisValue)
{
	if (axisValue != 0)
		SetState(EState::WALKING);
}



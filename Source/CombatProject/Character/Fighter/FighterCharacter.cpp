#include "FighterCharacter.h"
#include "CombatProject/Character/BaseState.h"
#include "CombatProject/Character/BaseCharacter.h"
#include "CombatProject/Character/Components/StateInputBinderComponent.h"
#include "Character/Components/FGMovementComponent.h"

AFighterCharacter::AFighterCharacter()
{
	InputBinderComp = CreateDefaultSubobject<UStateInputBinderComponent>(TEXT("StateInputBinderComponent"));
	MoveComp = CreateDefaultSubobject<UFGMovementComponent>(TEXT("MovementComponent"));

	
	IdleState.Fighter = this;
	WalkState.Fighter = this;
	AirborneState.Fighter = this;

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
	case EState::AIRBORNE:
		ActiveState->Leave();
		ActiveState = &AirborneState;
		ActiveState->Enter();
		break;
	}
}






#pragma region IdleState
void AFighterCharacter::IdleState::Enter()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Purple, TEXT("Enter Idle"));

	//Subscribe walk input
	FInputAxisBinding bind = Fighter->InputComponent->BindAxis(TEXT("MovementAxis"), Fighter, &AFighterCharacter::HandleWalk);
	Fighter->InputBinderComp->AddAxisBinding(bind);

	//Calling this without an initialized character controller touches a null pointer.
	//Apparently the inputcomponent is initialized with the character controller. Is it time for some defensive programming?
	
	
}

void AFighterCharacter::IdleState::Leave()
{
	Fighter->InputBinderComp->EmptyAllBindings(*(Fighter->InputComponent));
	
}

void AFighterCharacter::IdleState::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, DeltaTime, FColor::Purple, TEXT("Is Idle"));
	Fighter->MoveComp->PhysicsTick(DeltaTime);
	
}

#pragma endregion

#pragma region WalkState
void AFighterCharacter::WalkState::Enter()
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Purple, TEXT("Enter Walk"));

	//Subscribe Walk Input
	FInputAxisBinding bind = Fighter->InputComponent->BindAxis(TEXT("MovementAxis"), Fighter, &AFighterCharacter::HandleStopWalk);
	Fighter->InputBinderComp->AddAxisBinding(bind);

	//Subscribe Jump Input
	FInputActionBinding bind1 = Fighter->InputComponent->BindAction(TEXT("Jump"), IE_Pressed, Fighter, &AFighterCharacter::HandleJump);
	Fighter->InputBinderComp->AddActionBinding(bind1);

	//Look into how to make the lambda expression to make it prettier. I dont want 2000 random functions lying around. Or do I?
}

void AFighterCharacter::WalkState::Leave()
{
	Fighter->InputBinderComp->EmptyAllBindings(*(Fighter->InputComponent));
}

void AFighterCharacter::WalkState::Tick(float DeltaTime)
{
	GEngine->AddOnScreenDebugMessage(INDEX_NONE, DeltaTime, FColor::Purple, TEXT("Is Walking"));

	float walkForce = Fighter->InputAxis * 2000.f * DeltaTime;
	Fighter->MoveComp->Velocity.X = walkForce;
	
	Fighter->MoveComp->PhysicsTick(DeltaTime);
}



#pragma endregion

#pragma region AirborneState

void AFighterCharacter::AirborneState::Enter()
{
}

void AFighterCharacter::AirborneState::Leave()
{
}

void AFighterCharacter::AirborneState::Tick(float DeltaTime)
{
	//Gravity
	FVector GravityForce = FVector::DownVector * 120.f;
	Fighter->MoveComp->AddForce(GravityForce);

	Fighter->MoveComp->PhysicsTick(DeltaTime);

	if (Fighter->MoveComp->IsGrounded) //Add an event that states can subscribe to whenever you collide with something.
		Fighter->SetState(EState::IDLE);
}

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



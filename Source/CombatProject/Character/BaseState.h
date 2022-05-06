#pragma once
#include "CoreMinimal.h"
#include "BaseState.generated.h"


UCLASS(Blueprintable)
class UBaseState : public UObject
{
	GENERATED_BODY()
public:


	UFUNCTION()
		virtual void Tick(float DeltaTime);

	UFUNCTION(BlueprintImplementableEvent)
		void BPTick(float DeltaTime);

	UFUNCTION()
		virtual void Enter();

	UFUNCTION(BlueprintImplementableEvent)
		void BPEnter();

	UFUNCTION()
		virtual void Leave();

	UFUNCTION(BlueprintImplementableEvent)
		void BPLeave();
};
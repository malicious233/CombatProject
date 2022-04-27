#pragma once

#include "CoreMinimal.h"
#include "CharacterState.generated.h"

class ABaseCharacter;

UCLASS(Blueprintable)
class UCharacterState : public UObject
{
	GENERATED_BODY()
private:
	UPROPERTY()
	ABaseCharacter* owner;

public:

	//Is called every frame when state is active
	UFUNCTION(BlueprintNativeEvent)
	void Tick(float DeltaTime);

	//Is called when state is entered
	UFUNCTION(BlueprintNativeEvent)
	void Enter();

	//Is called when state is left under any circumstance
	UFUNCTION(BlueprintNativeEvent)
	void Leave();

};
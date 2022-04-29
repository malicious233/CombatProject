#pragma once
#include "Components/ActorComponent.h"
#include "StateInputBinderComponent.generated.h"

struct FInputAxisBinding;
class UInputComponent;

UCLASS(Meta = (BlueprintSpawnableComponent))
class UStateInputBinderComponent : public UActorComponent
{
	GENERATED_BODY()

public:

	/// <summary>
	/// Remembers axis bound in this state. 
	/// ATTENTION: Remember to always call EmptyAxisBindings when leaving the state.
	/// </summary>
	void AddAxisBinding(FInputAxisBinding item);

	/// <summary>
	/// Removes all bound axis bound during this state
	/// </summary>
	/// <param name="inputComp"></param>
	void EmptyAxisBindings(UInputComponent& inputComp);


	bool CompareInputAxisBindings(FInputAxisBinding lhs, FInputAxisBinding rhs);
	
	void RemoveAxisBinding(const int32 BindingIndex, UInputComponent& inputComp);

	TArray<FInputAxisBinding> RememberedAxisBindings;
};
#pragma once
#include "Components/ActorComponent.h"
#include "StateInputBinderComponent.generated.h"

struct FInputAxisBinding;
struct FInputActionBinding;
class UInputComponent;

UCLASS(Meta = (BlueprintSpawnableComponent))
class UStateInputBinderComponent : public UActorComponent
{
	GENERATED_BODY()

private:
	TArray<FInputAxisBinding> RememberedAxisBindings;

	TArray<FInputActionBinding> RememberedActionBindings;

public:

	/// <summary>
	/// Remembers axis bound in this state and is cleared when EmptyActionBindings is called
	/// ATTENTION: Remember to always call EmptyAxisBindings when leaving the state.
	/// </summary>
	void AddAxisBinding(FInputAxisBinding item);

	/// <summary>
	/// Remembers action bound in this state and is cleared when EmptyActionBindings is called
	/// </summary>
	/// <param name="item"></param>
	void AddActionBinding(FInputActionBinding item);

	/// <summary>
	/// Calls both to empty action and axis bindings that were bound in given state from given InputComponent 
	/// </summary>
	/// <param name="inputComp"></param>
	void EmptyAllBindings(UInputComponent& inputComp);

	bool CompareInputAxisBindings(FInputAxisBinding lhs, FInputAxisBinding rhs);

	bool CompareInputActionBindings(FInputActionBinding lhs, FInputActionBinding rhs);

private:
	/// <summary>
	/// Removes all bound axis bound during this state
	/// </summary>
	/// <param name="inputComp"></param>
	void EmptyAxisBindings(UInputComponent& inputComp);

	/// <summary>
	/// Removes all bound actions bound during this state
	/// </summary>
	/// <param name="inputComp"></param>
	void EmptyActionBindings(UInputComponent& inputComp);

	

	
};
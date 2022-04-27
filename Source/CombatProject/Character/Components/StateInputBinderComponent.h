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

	void AddAxisBinding(FInputAxisBinding& item);
	void EmptyAxisBindings(UInputComponent& inputComp);
	bool CompareInputAxisBindings(FInputAxisBinding lhs, FInputAxisBinding rhs);
	
	void RemoveAxisBinding(const int32 BindingIndex, UInputComponent& inputComp);

	TArray<FInputAxisBinding> RememberedAxisBindings;
};
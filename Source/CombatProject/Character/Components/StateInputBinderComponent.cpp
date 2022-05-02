#include "CombatProject/Character/Components/StateInputBinderComponent.h"

void UStateInputBinderComponent::AddAxisBinding(FInputAxisBinding item)
{
	RememberedAxisBindings.Add(item);
}

void UStateInputBinderComponent::AddActionBinding(FInputActionBinding item)
{
	RememberedActionBindings.Add(item);
}

void UStateInputBinderComponent::EmptyAxisBindings(UInputComponent& inputComp)
{
	
	for (int32 i = 0; i < RememberedAxisBindings.Num(); ++i)
	{
		for (int32 b = 0; b < inputComp.AxisBindings.Num(); ++b)
		{
			FInputAxisBinding binding = inputComp.AxisBindings[b];
			if (CompareInputAxisBindings(binding, RememberedAxisBindings[i]))
			{
				inputComp.AxisBindings.RemoveAt(b);
				b--;
				continue;
			}
		}
		
	}
	RememberedAxisBindings.Empty();
	
}

void UStateInputBinderComponent::EmptyActionBindings(UInputComponent& inputComp)
{
	for (int32 i = 0; i < RememberedActionBindings.Num(); ++i)
	{
		for (int32 b = 0; b < inputComp.GetNumActionBindings(); ++b)
		{
			FInputActionBinding binding = inputComp.GetActionBinding(b);
			if (CompareInputActionBindings(binding, RememberedActionBindings[i]))
			{
				inputComp.RemoveActionBinding(b);
				b--;
				continue;
			}
		}

	}
	RememberedActionBindings.Empty();
}

void UStateInputBinderComponent::EmptyAllBindings(UInputComponent& inputComp)
{
	EmptyActionBindings(inputComp);
	EmptyAxisBindings(inputComp);
}

bool UStateInputBinderComponent::CompareInputAxisBindings(FInputAxisBinding lhs, FInputAxisBinding rhs)
{
	return lhs.AxisDelegate.GetDelegateForManualSet().GetHandle() == rhs.AxisDelegate.GetDelegateForManualSet().GetHandle() && lhs.AxisName == rhs.AxisName;
}

bool UStateInputBinderComponent::CompareInputActionBindings(FInputActionBinding lhs, FInputActionBinding rhs)
{
	return lhs.ActionDelegate.GetDelegateForManualSet().GetHandle() == rhs.ActionDelegate.GetDelegateForManualSet().GetHandle() && lhs.GetActionName() == rhs.GetActionName();
}



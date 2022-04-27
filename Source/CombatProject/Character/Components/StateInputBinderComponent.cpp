#include "CombatProject/Character/Components/StateInputBinderComponent.h"

void UStateInputBinderComponent::AddAxisBinding(FInputAxisBinding& item)
{
	RememberedAxisBindings.Add(item);
}

void UStateInputBinderComponent::EmptyAxisBindings(UInputComponent& inputComp)
{
	for (int32 i = 0; i < RememberedAxisBindings.Num(); ++i)
	{
		for (int32 b = 0; b < inputComp.GetNumActionBindings(); ++b)
		{
			FInputAxisBinding binding = inputComp.AxisBindings[b];
			if (CompareInputAxisBindings(binding, RememberedAxisBindings[i]))
			{
				GEngine->AddOnScreenDebugMessage(INDEX_NONE, 1.f, FColor::Purple, TEXT("Remov"));
				//inputComp.AxisBindings[b].AxisDelegate.Unbind();
				inputComp.AxisBindings.RemoveAt(b, 1, false);
				b--;
				continue;
			}
		}
		
	}
	RememberedAxisBindings.Empty();
	
}



bool UStateInputBinderComponent::CompareInputAxisBindings(FInputAxisBinding lhs, FInputAxisBinding rhs)
{
	return lhs.AxisDelegate.GetDelegateForManualSet().GetHandle() == rhs.AxisDelegate.GetDelegateForManualSet().GetHandle() && lhs.AxisName == rhs.AxisName;
}

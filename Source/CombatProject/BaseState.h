#pragma once

class BaseState
{
public:

	UFUNCTION()
		virtual void Tick(float DeltaTime);

	UFUNCTION()
		virtual void Enter();

	UFUNCTION()
		virtual void Leave();
};
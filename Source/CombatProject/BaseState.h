#pragma once

class BaseState
{
public:

	BaseState();

	UFUNCTION()
		virtual void Tick(float DeltaTime);

	UFUNCTION()
		virtual void Enter();

	UFUNCTION()
		virtual void Leave();
};
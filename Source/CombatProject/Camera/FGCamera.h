#pragma once
#include "GameFramework/Actor.h"
#include "FGCamera.generated.h"

class UCameraComponent;
class USceneComponent;

UCLASS()
class AFGCamera : public AActor
{
	GENERATED_BODY()

public: 
	AFGCamera();

	void BeginPlay() override;
	void Tick(float DeltaTime) override;

	UPROPERTY(VisibleAnywhere)
	USceneComponent* Root;

	UPROPERTY(VisibleAnywhere)
	UCameraComponent* Camera;
};
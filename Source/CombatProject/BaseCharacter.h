// Fill out your copyright notice in the Description page of Project Settings.



#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Pawn.h"
#include "BaseCharacter.generated.h"

UENUM()
enum class EState : uint8
{
	NONE,
	IDLE,
	WALKING,
};


class UCharacterState;
class USphereComponent;

UCLASS()
class COMBATPROJECT_API ABaseCharacter : public APawn
{
	GENERATED_BODY()

public:
	// Sets default values for this pawn's properties
	ABaseCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	


	


	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere, Category = Combat)
	USphereComponent* Hurtbox;

	UPROPERTY()
	UCharacterState* ActiveState;

	UFUNCTION()
	void SetState(UCharacterState* ToState);

	

	


};



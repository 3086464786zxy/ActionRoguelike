// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"  
#include "NCharacter.generated.h"

class UCameraComponent;
class USpringArmComponent;
UCLASS()
class ACTIONROGUELIKE_API ANCharacter : public ACharacter
{
	GENERATED_BODY()

protected:

	UPROPERTY(EditAnywhere);
	TSubclassOf<AActor> ProjectileClass;

public:
	// Sets default values for this character's properties
	// Sets default values
	ANCharacter();

protected:

	UPROPERTY(visibleAnywhere);
	USpringArmComponent* mSpringArmComp = nullptr;

	UPROPERTY(visibleAnywhere);
	UCameraComponent* mCameraComp = nullptr;

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	void MoveForward(float value);
	void MoveRight(float value); 

	void PrimaryAttack();

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

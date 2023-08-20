// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "STFCharacter.generated.h"


class UCameraComponent;
class USpringArmComponent;

UCLASS()
class STFGAMEPROJECT_API ASTFCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ASTFCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

	UPROPERTY(visibleAnywhere)
	UCameraComponent* CameraComp;

	UPROPERTY(visibleAnywhere)
	USpringArmComponent* SpringArmComp;

	void MoveForward(float value);

	void MoveRight(float value);
public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

};

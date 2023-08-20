// Fill out your copyright notice in the Description page of Project Settings.


#include "STFCharacter.h"
#include "Camera/CameraComponent.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "GameFramework/SpringArmComponent.h"

// Sets default values
ASTFCharacter::ASTFCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	SpringArmComp= CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
	SpringArmComp->SetupAttachment(RootComponent);

	CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
	CameraComp->SetupAttachment(SpringArmComp);

	bUseControllerRotationPitch = false;
	bUseControllerRotationYaw = false;
	bUseControllerRotationRoll = false;
	GetCharacterMovement()->bOrientRotationToMovement = true;
	SpringArmComp->bUsePawnControlRotation = true;
	CameraComp->bUsePawnControlRotation = false;
}

// Called when the game starts or when spawned
void ASTFCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

void ASTFCharacter::MoveForward(float value)
{
	FRotator ControllerRot = GetControlRotation();
	ControllerRot.Pitch = 0;
	ControllerRot.Roll = 0;
	AddMovementInput(ControllerRot.Vector(), value);
}

void ASTFCharacter::MoveRight(float value)
{
	FRotator ControllerRot = GetControlRotation();
	ControllerRot.Pitch = 0;
	ControllerRot.Roll = 0;

	FVector RightVec = FRotationMatrix(ControllerRot).GetScaledAxis(EAxis::Y);
	AddMovementInput(RightVec, value);
}

// Called every frame
void ASTFCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ASTFCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward",this,&ASTFCharacter::MoveForward);
	PlayerInputComponent->BindAxis("MoveRight", this, &ASTFCharacter::MoveRight);

	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
	PlayerInputComponent->BindAxis("LookUp", this, &APawn::AddControllerPitchInput);
}


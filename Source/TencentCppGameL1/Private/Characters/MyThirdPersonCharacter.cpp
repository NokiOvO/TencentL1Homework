// Fill out your copyright notice in the Description page of Project Settings.


#include "Characters/MyThirdPersonCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"
#include "Kismet/KismetMathLibrary.h"
#include "Components/InputComponent.h"
#include "GameFramework/CharacterMovementComponent.h"

// Sets default values
AMyThirdPersonCharacter::AMyThirdPersonCharacter()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	SpringArm = CreateDefaultSubobject<USpringArmComponent>(TEXT("SpringArm"));

	SpringArm->SetupAttachment(RootComponent);

	SpringArm->bUsePawnControlRotation = true;

	Camera = CreateDefaultSubobject<UCameraComponent>(TEXT("Camera"));

	Camera->SetupAttachment(SpringArm);

	GetCharacterMovement()->bOrientRotationToMovement = true;

 	GetCharacterMovement()->RotationRate = FRotator(0.f, 600.f, 0.f);

	GetCharacterMovement()->NavAgentProps.bCanCrouch = true;

	GetCharacterMovement()->MaxWalkSpeed = 650;

	JumpMaxCount = 2;

	JumpMaxHoldTime = 1;

	bUseControllerRotationYaw = false;

	

}

// Called when the game starts or when spawned
void AMyThirdPersonCharacter::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AMyThirdPersonCharacter::Tick(float DeltaTime)
{

	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void AMyThirdPersonCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis(TEXT("MoveForward"), this, &AMyThirdPersonCharacter::MoveForward);

	PlayerInputComponent->BindAxis(TEXT("MoveRight"), this, &AMyThirdPersonCharacter::MoveRight);

	PlayerInputComponent->BindAxis(TEXT("Turn"), this, &AMyThirdPersonCharacter::AddControllerYawInput);

	PlayerInputComponent->BindAxis(TEXT("LookUp"), this, &AMyThirdPersonCharacter::AddControllerPitchInput);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Pressed, this, &AMyThirdPersonCharacter::CrouchDown);

	PlayerInputComponent->BindAction(TEXT("Crouch"), IE_Released, this, &AMyThirdPersonCharacter::CrouchUp);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Pressed, this, &AMyThirdPersonCharacter::Jump);

	PlayerInputComponent->BindAction(TEXT("Jump"), IE_Released, this, &AMyThirdPersonCharacter::StopJumping);

	PlayerInputComponent->BindAction(TEXT("Rush"), IE_Pressed, this, &AMyThirdPersonCharacter::Rush);

	PlayerInputComponent->BindAction(TEXT("Rush"), IE_Released, this, &AMyThirdPersonCharacter::EndRush);


}

void AMyThirdPersonCharacter::MoveForward(float Value)
{
	AddMovementInput(UKismetMathLibrary::GetForwardVector(GetControlRotation()), Value);
}

void AMyThirdPersonCharacter::MoveRight(float Value)
{
	AddMovementInput(UKismetMathLibrary::GetRightVector(GetControlRotation()), Value);
}

void AMyThirdPersonCharacter::CrouchDown()
{
	Crouch();
}

void AMyThirdPersonCharacter::CrouchUp()
{
	UnCrouch();	
	
}

void AMyThirdPersonCharacter::Rush()
{
	GetCharacterMovement()->MaxWalkSpeed = 1500;
}

void AMyThirdPersonCharacter::EndRush()
{
	GetCharacterMovement()->MaxWalkSpeed = 650;
}




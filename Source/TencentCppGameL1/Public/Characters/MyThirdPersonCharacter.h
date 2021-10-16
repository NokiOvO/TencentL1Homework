// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "MyThirdPersonCharacter.generated.h"

UCLASS()
class TENCENTCPPGAMEL1_API AMyThirdPersonCharacter : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMyThirdPersonCharacter();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
	    class USpringArmComponent * SpringArm;

	UPROPERTY(VisibleAnywhere, BlueprintReadOnly)
		class UCameraComponent * Camera;

	void MoveForward(float Value);

	void MoveRight(float Value);

	void CrouchDown();

	void CrouchUp();

	UFUNCTION(BlueprintCallable, Category = "MyCustomFunctions")
	void Rush();

	UFUNCTION(BlueprintCallable, Category = "MyCustomFunctions")
	void EndRush();




};

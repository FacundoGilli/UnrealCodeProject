
#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "InputAction.h"
#include "SCharacter.generated.h"


class USpringArmComponent;
class UCameraComponent;
class UInputMappingContext;

UCLASS()
class UNREALCODEPROJECT_API ASCharacter : public ACharacter
{
	GENERATED_BODY()

	//Mapping context
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputMappingContext> DefaultInputMapping;

	//Move input action
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Move;

	//Look input action
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_LookMouse;

	//Jump input action
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_Jump;

	//Primary attack input action
	UPROPERTY(EditDefaultsOnly, Category="Input")
	TObjectPtr<UInputAction> Input_PrimaryAttack;


protected:

	UPROPERTY(EditAnywhere)
	TSubclassOf<AActor> ProjectileClass;

	TSubclassOf<AActor> InteractClass;

	//Camera boom positioning the camera behind the character
	UPROPERTY(VisibleAnywhere, Category="Camera")
	USpringArmComponent* SpringArmComp;

	//Follow camera
	UPROPERTY(VisibleAnywhere, BlueprintReadWrite, Category="Camera")
	UCameraComponent* CameraComp;

public:
	

	// Sets default values for this character's properties
	ASCharacter();

protected:
	
	//Called for movement input
	void Move(const FInputActionValue& Instance);

	//Called for looking input
	void LookMouse(const FInputActionValue& Instance);

	//Called attack input
	void PrimaryAttack();

	// To add mapping context
	virtual void BeginPlay() override;

	// APawn interface
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

public:

	//Returns CameraBoom sub object
	FORCEINLINE class USpringArmComponent* GetCameraBoom() const { return SpringArmComp;  }
	//Returns FollowCamera sub object
	FORCEINLINE class UCameraComponent* GetFollowCamera() const { return CameraComp; }
};

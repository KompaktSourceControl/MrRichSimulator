// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"
#include "Blueprint/UserWidget.h"
#include "Engine.h"
#include "MrRich.generated.h"

UCLASS()
class MRRICHSIMULATOR_API AMrRich : public ACharacter
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	AMrRich();

protected:
	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	AMrRich(const FObjectInitializer& ObjectInitializer);

	//Functions
	UFUNCTION()
	void MoveForward(float Val);

	UFUNCTION()
	void MoveRight(float Val);

	UFUNCTION()
		void StartJump();

	UFUNCTION()
		void EndJump();

	UFUNCTION()
		void Attack();

	UFUNCTION()
		void Sprint();

	UFUNCTION()
		void StopSprint();

	UFUNCTION()
		void IdleTimer();

	UFUNCTION()
		void HealthDeplete();

	UFUNCTION()
		void EatSnack();

	UFUNCTION(exec)
		void Death();

	//Cheats
	UFUNCTION(exec)
		void RawrJump(); //Sets the jump noise to goblin

	UFUNCTION(exec)
		void VapeALot(); //Sets the out of breath noise to vaping noises.

	UFUNCTION(exec)
		void WhatsAGoonToAGoblin(); //Sets the sprite to the goblin

	UFUNCTION(exec)
		void WhenFattysAttack(); //Sets the attack noise to goblin

	UFUNCTION(exec)
		void RawrRawr(); //Sets the breath noise to goblin

	UFUNCTION(exec)
		void TheGoblin(); //Become the goblin

	UFUNCTION(exec)
		void ILostSomeWeight(); //Sets your stamina really high.

	UFUNCTION(exec)
		void ImHealthyAgain(); //Stops the health from depleting, but is still vulnerable to other hazards.

	UFUNCTION(exec)
		void IAmAGod(); //High health and stamina.

	
	//Properties
	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		float Stamina = 1;

	UPROPERTY()
		float MaxStamina = 1;

	UPROPERTY(BlueprintReadWrite)
		int Health = 100;

	UPROPERTY()
		int MaxHealth = 100;

	UPROPERTY(BlueprintReadWrite)
		int Snacks;
	
	UPROPERTY()
	USoundCue* JumpCue;
	
	UPROPERTY()
	UAudioComponent* JumpAudio;

	UPROPERTY(EditAnywhere)
		UCameraComponent* RichCamera;

	UPROPERTY(EditAnywhere)
		UPaperSpriteComponent* RichSprite;

	UPROPERTY()
		UPaperSprite* FattySprite;

	UPROPERTY()
		USoundCue* SmashCue;

	UPROPERTY()
		UAudioComponent* SmashAudio;

	UPROPERTY()
		USoundCue* BreathCue;

	UPROPERTY()
		UAudioComponent* BreathAudio;
	
	UPROPERTY()
		UAudioComponent* EatAudio;
	
	UPROPERTY()
		USoundCue* EatCue;

	UPROPERTY()
		bool bIsSprinting;

	UPROPERTY()
		bool bIsExhausted;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		TSubclassOf<class UUserWidget> wHUD;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		UUserWidget* HUD;

	UPROPERTY()
		FTimerHandle IdleHandle;

	UPROPERTY()
		float IdleTime = 20;

	UPROPERTY()
		FTimerHandle HealthHandle;
	
	UPROPERTY()
		float HealthTime = 3;

	UPROPERTY()
		float DeathTime = 10;

	UPROPERTY()
		FTimerHandle DeathHandle;

	UPROPERTY()
		USoundCue* IdleCueOne;

	UPROPERTY()
		USoundCue* IdleCueTwo;

	UPROPERTY()
		USoundCue* IdleCueThree;

	UPROPERTY()
		USoundCue* IdleCueFour;

	UPROPERTY()
		USoundCue* IdleCueFive;

	UPROPERTY()
		USoundCue* IdleCueSix;

	UPROPERTY()
		USoundCue* IdleCueSeven;
	
	UPROPERTY()
		USoundCue* IdleCueEight;

	UPROPERTY()
		USoundCue* IdleCueNine;

	UPROPERTY()
		USoundCue* IdleCueTen;

	UPROPERTY()
		UAudioComponent* IdleAudio;

	UPROPERTY()
		USoundCue* RawrJumpCue;

	UPROPERTY()
		USoundCue* VapeCue;

	UPROPERTY()
		USoundCue* FattyAttack;

	UPROPERTY()
		USoundCue* FattyStamina;

	UPROPERTY()
		int IdleSwitch;

	UPROPERTY(EditAnywhere, BlueprintReadWrite)
		bool bCanTalk =  true;

	UPROPERTY(BlueprintReadWrite)
		int CollectedEarbuds;

	UPROPERTY(BlueprintReadWrite)
		int NeededEarbuds;

	
};

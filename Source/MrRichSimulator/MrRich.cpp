// Fill out your copyright notice in the Description page of Project Settings.

#include "MrRich.h"
#include "PaperSprite.h"
#include "PaperSpriteComponent.h"



// Sets default values
AMrRich::AMrRich()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

}

AMrRich::AMrRich(const FObjectInitializer & ObjectInitializer) :Super(ObjectInitializer)
{
	RichCamera = CreateDefaultSubobject<UCameraComponent>(TEXT("RichCamera"));
	RichCamera->bUsePawnControlRotation = true;
	RichCamera->AttachTo(GetRootComponent());
	RichCamera->SetRelativeLocation(FVector(0, 0, 100));

	//Movement
	GetCharacterMovement()->JumpZVelocity = 600;
	GetCharacterMovement()->AirControl = 1;

	//Jump sound
	ConstructorHelpers::FObjectFinder<USoundCue>JumpCueObject(TEXT("/Game/Sounds/Rich/jump_sound_1_Cue.jump_sound_1_Cue"));
	JumpAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("JumpAudio"));
	JumpAudio->bAutoActivate = false;
	JumpCue = JumpCueObject.Object;
	JumpAudio->SetSound(JumpCue);

	ConstructorHelpers::FObjectFinder<USoundCue>SmashCueObject(TEXT("/Game/Sounds/Rich/smash_sound_Cue.smash_sound_Cue"));
	SmashAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("SmashAudio"));
	SmashAudio->bAutoActivate = false;
	SmashCue = SmashCueObject.Object;
	SmashAudio->SetSound(SmashCue);

	ConstructorHelpers::FObjectFinder<USoundCue>BreathCueObject(TEXT("/Game/Sounds/Rich/heavy_breath_Cue.heavy_breath_Cue"));
	BreathAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("BreathAudio"));
	BreathAudio->bAutoActivate = false;
	BreathCue = BreathCueObject.Object;
	BreathAudio->SetSound(BreathCue);

	//Create sprite
	ConstructorHelpers::FObjectFinder<UPaperSprite>RichSpriteObject(TEXT("/Game/Textures/People/Mr_rich_Sprite.Mr_rich_Sprite"));
	RichSprite = CreateDefaultSubobject<UPaperSpriteComponent>(TEXT("RichSprite"));
	RichSprite->SetSprite(RichSpriteObject.Object);
	RichSprite->AttachTo(GetRootComponent());
	RichSprite->SetRelativeRotation(FRotator(0, 90, 0));
	RichSprite->SetRelativeLocation(FVector(-10, 12, 32));
	RichSprite->SetWorldScale3D(FVector(.25, .25, .25));

	IdleAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("IdleAudio"));

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueOneObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/death_metal_1_Cue.death_metal_1_Cue'"));
	IdleCueOne = IdleCueOneObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueTwoObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/fat_2_Cue.fat_2_Cue'"));
	IdleCueTwo = IdleCueTwoObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueThreeObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/gonna_murder_joey_3_Cue.gonna_murder_joey_3_Cue'"));
	IdleCueThree = IdleCueThreeObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueFourObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/loser_4_Cue.loser_4_Cue'"));
	IdleCueFour = IdleCueFourObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueFiveObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/run_over_with_my_car_5_Cue.run_over_with_my_car_5_Cue'"));
	IdleCueFive = IdleCueFiveObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueSixObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/strangle_6_Cue.strangle_6_Cue'"));
	IdleCueSix = IdleCueSixObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueSevenObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/stupid_earbuds_7_Cue.stupid_earbuds_7_Cue'"));
	IdleCueSeven = IdleCueSevenObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueEightObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/super_deep_8_Cue.super_deep_8_Cue'"));
	IdleCueEight = IdleCueEightObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueNineObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/wasting_time_9_Cue.wasting_time_9_Cue'"));
	IdleCueNine = IdleCueNineObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>IdleCueTenObject(TEXT("SoundCue'/Game/Sounds/Rich/Idle/wish_i_had_pizza_10_Cue.wish_i_had_pizza_10_Cue'"));
	IdleCueTen = IdleCueTenObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>RawrSoundObject(TEXT("SoundCue'/Game/Sounds/lil_fatty_Cue.lil_fatty_Cue'"));
	RawrJumpCue = RawrSoundObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>VapeSoundObject(TEXT("SoundCue'/Game/Sounds/Graveyard/joeygrave_Cue.joeygrave_Cue'"));
	VapeCue = VapeSoundObject.Object;

	ConstructorHelpers::FObjectFinder<UPaperSprite>FattyObject(TEXT("PaperSprite'/Game/Textures/People/crazy_Animal_Sprite.crazy_Animal_Sprite'"));
	FattySprite = FattyObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>FattyAttackObject(TEXT("SoundCue'/Game/Sounds/Fatty/newfatattack_Cue.newfatattack_Cue'"));
	FattyAttack = FattyAttackObject.Object;

	ConstructorHelpers::FObjectFinder<USoundCue>FattyStaminaObject(TEXT("SoundCue'/Game/Sounds/Fatty/fattystamina_Cue.fattystamina_Cue'"));
	FattyStamina = FattyStaminaObject.Object;

	EatAudio = CreateDefaultSubobject<UAudioComponent>(TEXT("EatAudio"));
	ConstructorHelpers::FObjectFinder<USoundCue>EatObject(TEXT("SoundCue'/Game/Sounds/Rich/rich_eats_Cue.rich_eats_Cue'"));
	EatCue = EatObject.Object;


}

// Called when the game starts or when spawned
void AMrRich::BeginPlay()
{
	Super::BeginPlay();
	
	HUD = CreateWidget<UUserWidget>(GetWorld()->GetFirstLocalPlayerFromController()->PlayerController, wHUD);
	HUD->AddToViewport();
	GetWorldTimerManager().SetTimer(IdleHandle, this, &AMrRich::IdleTimer, 1.f, true); //Sets the timer for the idle quotes
	GetWorldTimerManager().SetTimer(HealthHandle, this, &AMrRich::HealthDeplete, 1.f, true); //Sets the timer for health depletion
}

// Called every frame
void AMrRich::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

	if (bIsSprinting && (GetMovementComponent()->Velocity.X != 0 || GetMovementComponent()->Velocity.Y != 0)) //Sprinting
	{
		Stamina = FMath::Clamp(Stamina, 0.f, MaxStamina);
		Stamina = Stamina - .4f * DeltaTime;
	}

	if (!bIsSprinting) //Not sprinting
	{
		Stamina = FMath::Clamp(Stamina, 0.f, MaxStamina);
		Stamina = Stamina + .2f * DeltaTime;
	}

	if(Stamina <= 0) //When you become exhausted
	{
		bIsExhausted = true;
		bIsSprinting = false;
		BreathAudio->Play();
		GetCharacterMovement()->MaxWalkSpeed = 600;
	}
	
	if(Stamina >= 0) //If you're not exhausted
	{
		bIsExhausted = false;
	}
	
}

// Called to bind functionality to input
void AMrRich::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);
	
	 InputComponent->BindAxis("MoveForward", this, &AMrRich::MoveForward);
	 InputComponent->BindAxis("MoveRight", this, &AMrRich::MoveRight);
	 InputComponent->BindAxis("LookUp", this, &AMrRich::AddControllerPitchInput);
	 InputComponent->BindAxis("LookRight", this, &AMrRich::AddControllerYawInput);

	 InputComponent->BindAction("Jump", IE_Pressed, this, &AMrRich::StartJump);
	 InputComponent->BindAction("Jump", IE_Released, this, &AMrRich::EndJump);
	 InputComponent->BindAction("Attack", IE_Pressed, this, &AMrRich::Attack);
	 InputComponent->BindAction("Sprint", IE_Pressed, this, &AMrRich::Sprint);
	 InputComponent->BindAction("Sprint", IE_Released, this, &AMrRich::StopSprint);
	 InputComponent->BindAction("Eat", IE_Pressed, this, &AMrRich::EatSnack);

	 if (GetWorld()->GetFirstPlayerController()->WasInputKeyJustPressed(EKeys::Escape))
	 {
		 GetWorld()->GetFirstPlayerController()->ConsoleCommand("quit");
	 }
}

void AMrRich::MoveForward(float Value)
{
	FVector Direction = GetActorForwardVector();
	AddMovementInput(Direction, Value);
}

void AMrRich::MoveRight(float Value)
{
	FVector Direction = GetActorRightVector();
	AddMovementInput(Direction, Value);
}

void AMrRich::StartJump()
{
	Jump();
	if (GetCharacterMovement()->IsFalling() == false)
	{
		JumpAudio->Play();
	}
}

void AMrRich::EndJump()
{
	StopJumping();
}

void AMrRich::Attack()
{
	Stamina = FMath::Clamp(Stamina, 0.f, MaxStamina);
	if (Stamina > .2)
	{ 
	FHitResult* HitResult = new FHitResult(); //Create the hitresult
	FVector StartLocation = RichCamera->GetComponentLocation() + RichCamera->GetForwardVector() + 5; //Start location of line trace
	FVector EndLocation = ((RichCamera->GetForwardVector() * 300) + StartLocation); //End location of line trace
	FCollisionQueryParams* TraceParams = new FCollisionQueryParams(); //Collison params
	TSubclassOf<UDamageType> const ValidDamageTypeClass = TSubclassOf<UDamageType>(UDamageType::StaticClass()); //Create damage type.
	FDamageEvent DamageEvent(ValidDamageTypeClass); //Create damage event.

	GetWorld()->LineTraceSingleByChannel(*HitResult, StartLocation, EndLocation, ECC_Visibility, *TraceParams);

	UGameplayStatics::ApplyPointDamage(HitResult->GetActor(), 30, StartLocation, *HitResult, GetWorld()->GetFirstPlayerController(), this, ValidDamageTypeClass);

	SmashAudio->Play(); //Play audio
	Stamina -= .2f;
}

}

void AMrRich::Sprint()
{
	if (!bIsExhausted && GetMovementComponent()->Velocity.X != 0 || GetMovementComponent()->Velocity.Y != 0)
	{
		bIsSprinting = true;
		GetCharacterMovement()->MaxWalkSpeed = 2000;
	}
}

void AMrRich::StopSprint()
{
	bIsSprinting = false;
	GetCharacterMovement()->MaxWalkSpeed = 600;
}

void AMrRich::IdleTimer()
{
	IdleTime--;
	IdleSwitch = FMath::RandRange(1, 10);
	
	if (IdleTime == 0 && (GetMovementComponent()->Velocity.X == 0 || GetMovementComponent()->Velocity.Y == 0) && bCanTalk)
	{
		GetWorldTimerManager().ClearTimer(IdleHandle);
		IdleTime = 20;
		GetWorldTimerManager().SetTimer(IdleHandle, this, &AMrRich::IdleTimer, 1.f, true);

		switch (IdleSwitch)
		{
		case 1:
			IdleAudio->SetSound(IdleCueOne);
			IdleAudio->Play();
			break;

		case 2:
			IdleAudio->SetSound(IdleCueTwo);
			IdleAudio->Play();
			break;

		case 3:
			IdleAudio->SetSound(IdleCueThree);
			IdleAudio->Play();
			break;

		case 4:
			IdleAudio->SetSound(IdleCueFour);
			IdleAudio->Play();
			break;

		case 5:
			IdleAudio->SetSound(IdleCueFive);
			IdleAudio->Play();
			break;

		case 6:
			IdleAudio->SetSound(IdleCueSix);
			IdleAudio->Play();
			break;

		case 7:
			IdleAudio->SetSound(IdleCueSeven);
			IdleAudio->Play();
			break;

		case 8:
			IdleAudio->SetSound(IdleCueEight);
			IdleAudio->Play();
			break;

		case 9:
			IdleAudio->SetSound(IdleCueNine);
			IdleAudio->Play();
			break;

		case 10:
			IdleAudio->SetSound(IdleCueTen);
			IdleAudio->Play();
			break;
		}
	}
	if (GetMovementComponent()->Velocity.X != 0 || GetMovementComponent()->Velocity.Y != 0)
	{
		GetWorldTimerManager().ClearTimer(IdleHandle);
		IdleTime = 20;
		GetWorldTimerManager().SetTimer(IdleHandle, this, &AMrRich::IdleTimer, 1.f, true);
	}
}

void AMrRich::HealthDeplete()
{
	Health = FMath::Clamp(Health, 0, MaxHealth);
	HealthTime--;
	if (HealthTime <= 0)
	{
		Health--;
		GetWorldTimerManager().ClearTimer(HealthHandle);
		HealthTime = 3;
		GetWorldTimerManager().SetTimer(HealthHandle, this, &AMrRich::HealthDeplete, 1.f, true);
	}
	if (Health <= 0)
	{
		GetWorldTimerManager().ClearTimer(HealthHandle);
		Death();
		GetWorldTimerManager().SetTimer(DeathHandle, this, &AMrRich::Death, 1.f, true);
	}
}

void AMrRich::EatSnack()
{
	if (Snacks > 0)
	{
		Health = 100;
		Snacks--;
		EatAudio->SetSound(EatCue);
		EatAudio->Play();
	}
}

void AMrRich::Death()
{
	Health = 0;
	DeathTime--; //The timer used on restarting the level.
	RichCamera->SetRelativeLocation(FVector(0, 0, -30));
	RichCamera->SetRelativeRotation(FRotator(0, 0, 45));
	RichCamera->bUsePawnControlRotation = false;
	RichSprite->SetRelativeRotation(FRotator(-90,90,0));
	RichSprite->SetRelativeLocation(FVector(0, -70, -30));
	GetWorldTimerManager().ClearTimer(IdleHandle);
	bIsSprinting = false;
	DisableInput(GetWorld()->GetFirstPlayerController());
	
	if (DeathTime <= 0)
	{
		UGameplayStatics::OpenLevel(GetWorld(), GetWorld()->GetFName());
		GetWorldTimerManager().ClearTimer(DeathHandle);
	}
}

//Cheats
void AMrRich::RawrJump()
{
	JumpAudio->SetSound(RawrJumpCue);
}

void AMrRich::VapeALot()
{
	BreathAudio->SetSound(VapeCue);
}

void AMrRich::WhatsAGoonToAGoblin()
{
	RichSprite->SetSprite(FattySprite);
	RichSprite->SetRelativeLocation(FVector(-30, 0, 80));
}

void AMrRich::WhenFattysAttack()
{
	SmashAudio->SetSound(FattyAttack);
}

void AMrRich::RawrRawr()
{
	BreathAudio->SetSound(FattyStamina);
}

void AMrRich::TheGoblin()
{
	RawrJump();
	WhatsAGoonToAGoblin();
	WhenFattysAttack();
	RawrRawr();
}

void AMrRich::ILostSomeWeight()
{
	MaxStamina = 10000;
	Stamina = 10000;
}

void AMrRich::ImHealthyAgain()
{
	GetWorldTimerManager().ClearTimer(HealthHandle);
	Health = 10000;
	MaxHealth = 10000;
}

void AMrRich::IAmAGod()
{
	ILostSomeWeight();
	ImHealthyAgain();
}


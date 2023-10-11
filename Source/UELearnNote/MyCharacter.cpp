// Fill out your copyright notice in the Description page of Project Settings.


#include "MyCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h"

// Sets default values
AMyCharacter::AMyCharacter()
{
    // Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
    PrimaryActorTick.bCanEverTick = true;

    SpringArmComp = CreateDefaultSubobject<USpringArmComponent>("SpringArmComp");
    SpringArmComp->SetupAttachment(RootComponent);

    CameraComp = CreateDefaultSubobject<UCameraComponent>("CameraComp");
    CameraComp->SetupAttachment(SpringArmComp);
}

// Called when the game starts or when spawned
void AMyCharacter::BeginPlay()
{
    Super::BeginPlay();
}

void AMyCharacter::MoveForward(float value)
{
    std::string strValue = "MoveForward : " + std::to_string(value);
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString(strValue.c_str()));
    AddMovementInput(GetActorForwardVector(), value);
}

// Called every frame
void AMyCharacter::Tick(float DeltaTime)
{
    Super::Tick(DeltaTime);
}

// Called to bind functionality to input
void AMyCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
    GEngine->AddOnScreenDebugMessage(-1, 2.0f, FColor::Green, FString("SetupPlayerInputComponent"));
    Super::SetupPlayerInputComponent(PlayerInputComponent);

    PlayerInputComponent->BindAxis("MoveForward", this, &AMyCharacter::MoveForward);

    PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);
}


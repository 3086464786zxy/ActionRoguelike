// Fill out your copyright notice in the Description page of Project Settings.


#include "NCharacter.h"
#include "GameFramework/SpringArmComponent.h"
#include "Camera/CameraComponent.h" 
#include "GameFramework/CharacterMovementcomponent.h" 
// Called when the game starts or when spawned
ANCharacter::ANCharacter()
{
	//set this character to call tick() every frame. you can turn this off to imporve performance if you don't need it
	PrimaryActorTick.bCanEverTick = true;

	mSpringArmComp = CreateDefaultSubobject<USpringArmComponent>("springArmComp");
	mSpringArmComp->bUsePawnControlRotation = true;
	mSpringArmComp->SetupAttachment(RootComponent);

	mCameraComp = CreateDefaultSubobject<UCameraComponent>("cameraComp");
	mCameraComp->SetupAttachment(mSpringArmComp);

	GetCharacterMovement()->bOrientRotationToMovement = true;
	bUseControllerRotationYaw = false;
}

void ANCharacter::BeginPlay()
{
	Super::BeginPlay();

}

void ANCharacter::MoveForward(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	AddMovementInput(GetActorForwardVector(), value);

}

void ANCharacter::MoveRight(float value)
{
	FRotator ControlRot = GetControlRotation();
	ControlRot.Pitch = 0.0f;
	ControlRot.Roll = 0.0f;

	FVector RightVector = FRotationMatrix(ControlRot).GetScaledAxis(EAxis::Y);

	AddMovementInput(RightVector, value);
}

void ANCharacter::PrimaryAttack()
{
	FVector HandleLocation = GetMesh()->GetSocketLocation("middle_01_r");	//��Ͷ������ŵ���ɫ�Ĺ��������λ��

	//FTransform SpawnTM = FTransform(GetControlRotation(), GetActorLocation());
	FTransform SpawnTM = FTransform(GetControlRotation(), HandleLocation);

	FActorSpawnParameters SpawnParams;	//����
	//������ײ���Ǵ���
	SpawnParams.SpawnCollisionHandlingOverride = ESpawnActorCollisionHandlingMethod::AlwaysSpawn; 


	GetWorld()->SpawnActor<AActor>(ProjectileClass, SpawnTM, SpawnParams);//�࣬ ������ת�ͻ�õ�ַ�� ��ײ�Ȳ���
}


// Called every frame
void ANCharacter::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ANCharacter::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

	PlayerInputComponent->BindAxis("MoveForward", this, &ANCharacter::MoveForward);		//���� 
	PlayerInputComponent->BindAxis("MoveRight", this, &ANCharacter::MoveRight);


	PlayerInputComponent->BindAxis("Turn", this, &APawn::AddControllerYawInput);	//ת��
	PlayerInputComponent->BindAxis("LookUP", this, &APawn::AddControllerPitchInput);

	PlayerInputComponent->BindAction("PrimaryAttack", IE_Pressed, this, &ANCharacter::PrimaryAttack);
}


// Fill out your copyright notice in the Description page of Project Settings.




#include "ASMagicProjectile.h"  
#include "Components/SphereComponent.h" 
#include "GameFramework/ProjectileMovementComponent.h" 
#include "Particles/ParticleSystemComponent.h" 

// Sets default values
AASMagicProjectile::AASMagicProjectile()
{
 	// Set this actor to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = true;

	//�����������������ײ��������
	mSphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp"); 
	//mSphereComp->SetCollisionObjectType(ECC_WorldDynamic); //�����Լ�Ϊ���綯̬, ��Ϊ�Լ����ƶ�
	//mSphereComp->SetCollisionResponseToChannels(ECR_Ignore); //������ײͨ��, ��������ͨ��������
	//mSphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); //ֻ�Ը��ǲ��֣� ����pawn
	//mSphereComp->SetCollisionProfileName("Projectile"); //��������һ�������ļ����ƣ���custion..)

	RootComponent = mSphereComp;
	

	mEffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	mEffectComp->SetupAttachment(mSphereComp);		//���ӵ����������

	mMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	mMovementComp->InitialSpeed = 1000.0f;			//���ó�ʼ�ٶ�
	mMovementComp->bRotationFollowsVelocity = true;		//��ѡ Rotation Follows Velocity ÿ֡��������ת ��ƥ���ٶȵķ���
	mMovementComp->bInitialVelocityInLocalSpace = true;		//�ھֲ��ռ��������ٶ�

}

// Called when the game starts or when spawned
void AASMagicProjectile::BeginPlay()
{
	Super::BeginPlay();
	
}

// Called every frame
void AASMagicProjectile::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}



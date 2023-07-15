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

	//球体组件可以设置碰撞对象类型
	mSphereComp = CreateDefaultSubobject<USphereComponent>("SphereComp"); 
	//mSphereComp->SetCollisionObjectType(ECC_WorldDynamic); //设置自己为世界动态, 因为自己在移动
	//mSphereComp->SetCollisionResponseToChannels(ECR_Ignore); //设置碰撞通道, 设置所有通道被忽略
	//mSphereComp->SetCollisionResponseToChannel(ECC_Pawn, ECR_Overlap); //只对覆盖部分， 设置pawn
	//mSphereComp->SetCollisionProfileName("Projectile"); //设置其中一个配置文件名称（如custion..)

	RootComponent = mSphereComp;
	

	mEffectComp = CreateDefaultSubobject<UParticleSystemComponent>("EffectComp");
	mEffectComp->SetupAttachment(mSphereComp);		//附加到球体组件中

	mMovementComp = CreateDefaultSubobject<UProjectileMovementComponent>("MovementComp");
	mMovementComp->InitialSpeed = 1000.0f;			//设置初始速度
	mMovementComp->bRotationFollowsVelocity = true;		//勾选 Rotation Follows Velocity 每帧更新其旋转 以匹配速度的方向
	mMovementComp->bInitialVelocityInLocalSpace = true;		//在局部空间中设置速度

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



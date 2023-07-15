// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "ASMagicProjectile.generated.h"

class USphereComponent;
class UProjectileMovementComponent; //投射物组件
class UParticleSystemComponent;
UCLASS()
class ACTIONROGUELIKE_API AASMagicProjectile : public AActor
{
	GENERATED_BODY()
	
public:	
	// Sets default values for this actor's properties
	AASMagicProjectile();

protected:

	UPROPERTY(visibleAnywhere);
	USphereComponent* mSphereComp = nullptr;	//球体组件， 碰撞的最基本组件

	UPROPERTY(visibleAnywhere);
	UProjectileMovementComponent* mMovementComp = nullptr;	//投射物运动组件， 这只是一个组件，
	//将给出一个速度并且进入直线, 用来做抛物线或者子弹的组件

	UPROPERTY(visibleAnywhere);
	UParticleSystemComponent* mEffectComp = nullptr;	//粒子系统组件，可以展示其它东西(eg特效)

	// Called when the game starts or when spawned
	virtual void BeginPlay() override;

public:	
	// Called every frame
	virtual void Tick(float DeltaTime) override;

};

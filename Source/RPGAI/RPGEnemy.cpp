// Fill out your copyright notice in the Description page of Project Settings.


#include "RPGEnemy.h"

// Sets default values
ARPGEnemy::ARPGEnemy()
{
 	// Set this character to call Tick() every frame.  You can turn this off to improve performance if you don't need it.
	PrimaryActorTick.bCanEverTick = false;

	Health = 100.f;
	Mana = 100.f;

}

// Called when the game starts or when spawned
void ARPGEnemy::BeginPlay()
{
	Super::BeginPlay();
	
}

bool ARPGEnemy::GetIsAlive()
{
	if (Health > 0.f)
	{
		return true;
	}
	return false;
}

bool ARPGEnemy::GetIsPlayer()
{
	return false;
}

// Called every frame
void ARPGEnemy::Tick(float DeltaTime)
{
	Super::Tick(DeltaTime);

}

// Called to bind functionality to input
void ARPGEnemy::SetupPlayerInputComponent(UInputComponent* PlayerInputComponent)
{
	Super::SetupPlayerInputComponent(PlayerInputComponent);

}


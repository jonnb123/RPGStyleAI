// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIInterface.h"
#include "BehaviorTree/BehaviorTree.h"
#include "GameFramework/Character.h"
#include "RPGEnemy.generated.h"

UCLASS()
class RPGAI_API ARPGEnemy : public ACharacter, public IAIInterface
{
	GENERATED_BODY()

public:
	// Sets default values for this character's properties
	ARPGEnemy();

	// Called every frame
	virtual void Tick(float DeltaTime) override;

	// Called to bind functionality to input
	virtual void SetupPlayerInputComponent(class UInputComponent* PlayerInputComponent) override;

	UPROPERTY(EditAnywhere)
	UBehaviorTree* Tree;

	virtual bool GetIsAlive() override;
	virtual bool GetIsPlayer() override;

protected:
	virtual void BeginPlay() override;

	float Health;
	float Mana;

	

	 
private:
	

};

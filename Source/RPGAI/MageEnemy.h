// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "RPGEnemy.h"
#include "MageEnemy.generated.h"

/**
 * 
 */
UCLASS()
class RPGAI_API AMageEnemy : public ARPGEnemy
{
	GENERATED_BODY()

public:
	virtual float GetAttackRange() override;
};

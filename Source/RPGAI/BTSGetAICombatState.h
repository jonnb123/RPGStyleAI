// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "MageAIController.h"
#include "RPGEnemy.h"
#include "BehaviorTree/BTService.h"
#include "BTSGetAICombatState.generated.h"

/**
 * 
 */
UCLASS()
class RPGAI_API UBTServiceMageAI : public UBTService
{
	GENERATED_BODY()

public:
	
	virtual void TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds) override;

	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector CombatStateKey;
	
	UPROPERTY(EditAnywhere)
	FBlackboardKeySelector TargetKey;
	
	ARPGEnemy* AIChar;

	AActor* Target;

	float CurrentDistance;
};

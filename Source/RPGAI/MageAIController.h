// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "AIController.h"
#include "Perception/AISenseConfig_Damage.h"
#include "Perception/AISenseConfig_Sight.h"
#include "MageAIController.generated.h"

/**
 * 
 */
UENUM(BlueprintType)
enum class ECombatState : uint8
{
	E_Idle			UMETA(DisplayName = "Idle"),
	E_Patrol		UMETA(DisplayName = "Patrol"),
	E_RangedAttack  UMETA(DisplayName = "Ranged_Ataack"),
	E_MeleeAttack	UMETA(DisplayName = "Melee_Attack"),
	E_OutOfRange	UMETA(DisplayName = "Out_Of_Range"),
	
	E_Size			 UMETA(DisplayName = "Size")
};


UCLASS()
class RPGAI_API AMageAIController : public AAIController
{
	GENERATED_BODY()
	
protected:
	AMageAIController();
	
	virtual void OnPossess(APawn* InPawn) override;

	UFUNCTION()
	void PerceptionUpdate(const TArray<AActor*>& UpdatedActors);
	
	UPROPERTY(VisibleAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	UAIPerceptionComponent* AIPerception;

	UPROPERTY(VisibleAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	UAISenseConfig_Sight* SightConfig;

	UPROPERTY(VisibleAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	UAISenseConfig_Damage* DamageConfig;

	UPROPERTY(VisibleAnywhere, Category="AI", meta=(AllowPrivateAccess="true"))
	FName EnemyTargetKey;

	
	
};

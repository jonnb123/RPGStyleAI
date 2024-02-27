// Fill out your copyright notice in the Description page of Project Settings.


#include "MageAIController.h"

#include "MageEnemy.h"
#include "RPGAICharacter.h"
#include "RPGEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"
#include "Perception/AIPerceptionComponent.h"
#include "Perception/AISense_Sight.h"

AMageAIController::AMageAIController()
{
	AIPerception = CreateDefaultSubobject<UAIPerceptionComponent>(TEXT("AIPerceptionComponent"));
	SightConfig = CreateDefaultSubobject<UAISenseConfig_Sight>(TEXT("SightConfig"));
	DamageConfig = CreateDefaultSubobject<UAISenseConfig_Damage>(TEXT("DamageConfig"));

	// configuring sight
	AIPerception->ConfigureSense(*SightConfig);
	SightConfig->SightRadius = 2000.f;
	SightConfig->LoseSightRadius = 2200.f;
	SightConfig->PeripheralVisionAngleDegrees = 65.f;
	SightConfig->DetectionByAffiliation.bDetectEnemies = true;
	SightConfig->DetectionByAffiliation.bDetectFriendlies = true;
	SightConfig->DetectionByAffiliation.bDetectNeutrals = true;
	SightConfig->SetMaxAge(3.f);

	// configuring damage
	AIPerception->ConfigureSense(*DamageConfig);
	DamageConfig->SetMaxAge(7.f);

	EnemyTargetKey = "EnemyTarget";
	
	AIPerception->SetDominantSense(SightConfig->GetSenseImplementation());

	if (AIPerception != nullptr)
	{
		AIPerception->OnPerceptionUpdated.AddDynamic(this, &AMageAIController::PerceptionUpdate);
	}
	
}



void AMageAIController::OnPossess(APawn* InPawn)
{
	Super::OnPossess(InPawn);

	if (!InPawn) { return; }
	
	ARPGEnemy* CharacterBase = Cast<ARPGEnemy>(InPawn);

	if (!CharacterBase)
	{
		printf("No RPG Enemy");
		return;
	}

	if (CharacterBase->Tree == nullptr)
	{
		printf("No Tree");
		return;
	}

	RunBehaviorTree(CharacterBase->Tree);
	
	
}

void AMageAIController::PerceptionUpdate(const TArray<AActor*>& UpdatedActors)
{
	AMageEnemy* Enemy = Cast<AMageEnemy>(GetCharacter());
	if(!Enemy->GetIsAlive())
	{
		return;
	}
	for (AActor* Actor : UpdatedActors)
	{
		if (ARPGAICharacter* PlayerCharacter = Cast<ARPGAICharacter>(Actor))
		{
			if (PlayerCharacter->GetIsAlive())
			{
				if (PlayerCharacter->GetIsPlayer())
				{
					ARPGAICharacter* Target = PlayerCharacter;
					GetBlackboardComponent()->SetValueAsObject(EnemyTargetKey, Target);
					return;
				}
			}
		}
	}
}





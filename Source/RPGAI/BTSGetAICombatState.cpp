// Fill out your copyright notice in the Description page of Project Settings.


#include "BTSGetAICombatState.h"

#include "RPGEnemy.h"
#include "BehaviorTree/BlackboardComponent.h"

void UBTServiceMageAI::TickNode(UBehaviorTreeComponent& OwnerComp, uint8* NodeMemory, float DeltaSeconds)
{
	Super::TickNode(OwnerComp, NodeMemory, DeltaSeconds);

	AIChar = Cast<ARPGEnemy>(OwnerComp.GetAIOwner()->GetPawn());
	

	UBlackboardComponent* Blackboard = OwnerComp.GetBlackboardComponent();

	if (!Blackboard->GetValueAsObject(TargetKey.SelectedKeyName))
	{
		if(AIChar->PatrolRoute)
		{
			Blackboard->SetValueAsEnum(CombatStateKey.SelectedKeyName, static_cast<uint8>(ECombatState::E_Patrol));
		}
		else
		{
			Blackboard->SetValueAsEnum(CombatStateKey.SelectedKeyName, static_cast<uint8>(ECombatState::E_Idle));
		}
	}
	else
	{
		Target = Cast<AActor>(Blackboard->GetValueAsObject(TargetKey.SelectedKeyName));
		CurrentDistance = FVector::Distance(Target->GetActorLocation(), AIChar->GetActorLocation());
		if (CurrentDistance > AIChar->GetAttackRange())
		{
			Blackboard->SetValueAsEnum(CombatStateKey.SelectedKeyName, static_cast<uint8>(ECombatState::E_OutOfRange));
		}
		else
		{
			Blackboard->SetValueAsEnum(CombatStateKey.SelectedKeyName, static_cast<uint8>(ECombatState::E_MeleeAttack));
		}
	}

	
}

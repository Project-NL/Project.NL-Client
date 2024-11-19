// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include <AIController.h>

#include "EnemyAIController.generated.h"

/**
 * 
 */
class UBlackboardData;
class UBehaviorTree;
UCLASS()
class PROJECTNL_API AEnemyAIController : public AAIController
{
	GENERATED_BODY()

public:
	AEnemyAIController();
	
	virtual void Tick(float DeltaSeconds) override;
	
protected:

	UFUNCTION()
	void RunAi();
	UFUNCTION()
	void StopAi();
	UFUNCTION()
	virtual void OnPossess(APawn* InPawn) override;
	UFUNCTION()
	void SearchForNearestEnemy();
	UFUNCTION()
	void OnPerceptionUpdated(AActor* UpdatedActor, FAIStimulus Stimulus);
	UFUNCTION()
	void UpdateClosestEnemy();
private:
	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UAIPerceptionComponent* AIPerceptionComponent;

	UPROPERTY(VisibleAnywhere, Category = "AI")
	class UAISenseConfig_Sight* SightConfig;

	
	
	UPROPERTY(EditAnywhere, Category = "BB")
	TObjectPtr<UBlackboardData> BBAsset;
	UPROPERTY(EditAnywhere, Category = "BT")
	TObjectPtr<UBehaviorTree> BTAsset;
	
};

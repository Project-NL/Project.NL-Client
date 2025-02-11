// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "CoreMinimal.h"
#include "ProjectNL/GAS/Ability/Utility/BaseInputTriggerAbility.h"
#include "GA_EnableOutlineSkill.generated.h"

/**
 * 
 */
UCLASS()
class PROJECTNL_API UGA_EnableOutlineSkill : public UBaseInputTriggerAbility
{
	GENERATED_BODY()
public:
	UGA_EnableOutlineSkill(const FObjectInitializer& ObjectInitializer);

protected:
	virtual void ActivateAbility(const FGameplayAbilitySpecHandle Handle
															, const FGameplayAbilityActorInfo* ActorInfo
															, const FGameplayAbilityActivationInfo
															ActivationInfo
															, const FGameplayEventData*
															TriggerEventData) override;

	virtual void EndAbility(const FGameplayAbilitySpecHandle Handle
													, const FGameplayAbilityActorInfo* ActorInfo
													, const FGameplayAbilityActivationInfo ActivationInfo
													, bool bReplicateEndAbility
													, bool bWasCancelled) override;

	UFUNCTION()
	void OnCompleted(FGameplayTag EventTag, FGameplayEventData EventData);
	
	UFUNCTION()
	void OnCancelled(FGameplayTag EventTag, FGameplayEventData EventData);

	UFUNCTION()
	void PlayActionAnimation();
	void DisableOutline();

public:
	
	
	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category = "GAS")
	TObjectPtr<UAnimMontage> SkillAnimMontage;

	UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="Material")
	UMaterialInstance* OutlineMaterialInstance;
private:
	UPROPERTY()
	TObjectPtr<class UPlayMontageWithEvent> PlayMontageTask;
	
	UPROPERTY()
	int32 bEnableLine{};
	
	UPROPERTY()
	UMaterialInstanceDynamic* OutlineMaterialInstanceDynamic;

	/** 타이머 핸들 */
	FTimerHandle OutlineDisableTimerHandle;
};

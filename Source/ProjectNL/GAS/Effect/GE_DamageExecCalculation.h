﻿#pragma once

#include "CoreMinimal.h"
#include "GameplayEffectExecutionCalculation.h"
#include "GE_DamageExecCalculation.generated.h"


UCLASS()
class PROJECTNL_API UGE_DamageExecCalculation : public UGameplayEffectExecutionCalculation
{
	GENERATED_BODY()

public:
	UGE_DamageExecCalculation();

protected:
	virtual void Execute_Implementation(const FGameplayEffectCustomExecutionParameters& ExecutionParams, FGameplayEffectCustomExecutionOutput& OutExecutionOutput) const override;

private:
	UPROPERTY(EditDefaultsOnly, Category="Value", meta = (AllowPrivateAccess = true))
	float DamageValue = 0;

	UPROPERTY(EditDefaultsOnly, Category="Value", meta = (AllowPrivateAccess = true))
	FGameplayTag DamageCalcTag;
};

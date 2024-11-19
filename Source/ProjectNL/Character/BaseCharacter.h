﻿#pragma once

#include "CoreMinimal.h"
#include "GameFramework/Character.h"
#include "AbilitySystemInterface.h"
#include "ProjectNL/GAS/NLAbilitySystemComponent.h"
#include "ProjectNL/GAS/NLAbilitySystemInitializationData.h"
#include "ProjectNL/Helper/UtilHelper.h"
#include "BaseCharacter.generated.h"

class UEquipComponent;
enum class EEntityCategory : uint8;

UCLASS()
class PROJECTNL_API ABaseCharacter : public ACharacter, public IAbilitySystemInterface
{
	GENERATED_BODY()

public:
	ABaseCharacter();
	
	virtual UAbilitySystemComponent* GetAbilitySystemComponent() const override
	{
		return AbilitySystemComponent;
	}

	UFUNCTION(Server, Reliable)
	void Server_ApplyGameplayEffectToSelf(TSubclassOf<UGameplayEffect> Effect, const uint32 Level = 1);

	UFUNCTION(Server, Reliable)
	void Server_RemoveActiveGameplayEffectBySourceEffect(
		TSubclassOf<UGameplayEffect> Effect);
	
	GETTER(UEquipComponent*, EquipComponent)
	GETTER(FVector2D, MovementVector)
	GETTER_SETTER(EEntityCategory, EntityType)
	
protected:
	virtual void BeginPlay() override;

	virtual void Tick(float DeltaSeconds) override;
	
	UPROPERTY()
	UNLAbilitySystemComponent* AbilitySystemComponent;
	
	UPROPERTY(EditDefaultsOnly, BlueprintReadOnly)
	UEquipComponent* EquipComponent;
	
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "AbilitySystem"
		, meta = (AllowPrivateAccess = "true"))
	FNLAbilitySystemInitializationData InitializeData;

	// TODO: 추후 별도의 컴포넌트로 전환해도 무방
	// 해당 플레이어가 어느 방향으로 이동 중 인지를 검증하는 결과 값
	FVector2D MovementVector = FVector2D().ZeroVector;

	void MovementSpeedChanged(const FOnAttributeChangeData& Data);
	
	void Initialize();

	virtual void OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode) override;
private:
	UPROPERTY(EditAnywhere, BlueprintReadOnly, Category = "Entity|Category"
		, meta = (AllowPrivateAccess = "true"))
	EEntityCategory EntityType;
};

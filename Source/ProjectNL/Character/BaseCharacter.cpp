﻿#include "BaseCharacter.h"

#include "AbilitySystemBlueprintLibrary.h"
#include "ProjectNL/Helper/EnumHelper.h"

#include "ProjectNL/Component/EquipComponent/EquipComponent.h"
#include "ProjectNL/GAS/Attribute/BaseAttributeSet.h"
#include "GameFramework/CharacterMovementComponent.h"
#include "ProjectNL/Helper/GameplayTagHelper.h"


ABaseCharacter::ABaseCharacter()
{
	EntityType = EEntityCategory::Undefined;
	EquipComponent = CreateDefaultSubobject<UEquipComponent>("Equip Component");
}



void ABaseCharacter::BeginPlay()
{
	Super::BeginPlay();
}

void ABaseCharacter::Tick(float DeltaSeconds)
{
	Super::Tick(DeltaSeconds);
	// 태그 컨테이너 선언
	// if(!GetCharacterMovement())
	// {
	// 	return;
	// }
	// // Check if the character is falling
	
}

void ABaseCharacter::Initialize()
{
	if (AbilitySystemComponent)
	{
		if (GetEquipComponent()->GetIsFirstEquipWeapon())
		{
			AbilitySystemComponent->AddLooseGameplayTag(NlGameplayTags::Status_Combat);
		}
	}
}

void ABaseCharacter::OnMovementModeChanged(EMovementMode PrevMovementMode, uint8 PreviousCustomMode)
{
	Super::OnMovementModeChanged(PrevMovementMode, PreviousCustomMode);
}

void ABaseCharacter::NotifyHitInteraction(const FHitResult& Hit)
{
	AActor* HitActor = Hit.GetActor();
	if(HitActor)
	{
		ABaseCharacter* TargetActor=Cast<ABaseCharacter>(HitActor);
		Server_ApplyGameplayEffectToTarget(GetEquipComponent()->GetAttackDamageEffect(),TargetActor);
	}
}


void ABaseCharacter::Server_ApplyGameplayEffectToSelf_Implementation(
	TSubclassOf<UGameplayEffect> Effect, const uint32 Level)
{
	if (GetLocalRole() != ROLE_Authority)
	{
		Server_ApplyGameplayEffectToSelf(Effect);
		return;
	}

	if (!IsValid(AbilitySystemComponent))
	{
		return;
	}

	AbilitySystemComponent->ApplyGameplayEffectToSelf(
		Effect.GetDefaultObject(), Level
		, AbilitySystemComponent->MakeEffectContext());
}

void
ABaseCharacter::Server_RemoveActiveGameplayEffectBySourceEffect_Implementation(
	TSubclassOf<UGameplayEffect> Effect)
{
	if (GetLocalRole() != ROLE_Authority)
	{
		Server_ApplyGameplayEffectToSelf(Effect);
		return;
	}

	if (!IsValid(AbilitySystemComponent))
	{
		return;
	}

	AbilitySystemComponent->RemoveActiveGameplayEffectBySourceEffect(
		Effect, AbilitySystemComponent);
}

void ABaseCharacter::Server_ApplyGameplayEffectToTarget_Implementation(TSubclassOf<UGameplayEffect> Effect,
	const  ABaseCharacter* TargetActor,
	const uint32 Level)
{
	UAbilitySystemComponent* TargetASC = TargetActor->GetAbilitySystemComponent();
	if (!IsValid(TargetASC))
	{
		FString Message = FString::Printf(TEXT("TargetASC가 없습니다"));
		return;
	}
	TargetASC->ApplyGameplayEffectToSelf(
	Effect.GetDefaultObject(), Level
	, TargetASC->MakeEffectContext());
}
void ABaseCharacter::MovementSpeedChanged(const FOnAttributeChangeData& Data)
{
	const float MovementSpeed = Data.NewValue;

	GetCharacterMovement()->MaxWalkSpeed = MovementSpeed;
}
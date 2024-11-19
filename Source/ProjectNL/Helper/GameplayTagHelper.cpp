﻿#include "GameplayTagHelper.h"
#include "NativeGameplayTags.h"

namespace NlGameplayTags
{
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Ability, "Ability", "Ability 관련 최상위 트리 태그");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Category, "Category", "특정 Actor의 카테고리 관련 최상위 트리 태그");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Category_Entity, "Category.Entity", "특정 Actor의 카테고리가 엔티티(살아있는 생물체)인 경우");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State, "State", "특정 액터의 행동 상태에 대한 최상위 트리 태그로 하나만 들어갈 수 있음");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_Idle, "State.Idle", "특정 액터의 행동 상태가 어떠한 동작하지 않는 대기 상태인 경우 태그");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_GrabWeapon, "State.GrabWeapon", "특정 액터가 현재 무기를 뽑는 상태일 때를 나타내는 태그");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(State_PutWeapon, "State.PutWeapon", "특정 액터가 현재 무기를 집어넣는 상태일 때를 나타내는 태그");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status, "Status", "특정 액터의 현재 상황에 대해 나타내는 태그로 여러개가 들어갈 수 있음");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Combat, "Status.Combat", "특정 액터가 현재 전투를 준비한 상황에 대한 태그");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Movement_Grounded, "Status.Movement.Grounded", "특정 액터가 현재 땅에 붙어있는 상태일 때를 나타내는 태그");
	UE_DEFINE_GAMEPLAY_TAG_COMMENT(Status_Movement_Falling, "Status.Movement.Falling", "특정 액터가 현재 떠 있는 상태일 때를 나타내는 태그");
}
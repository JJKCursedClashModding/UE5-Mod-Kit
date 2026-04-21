#pragma once
#include "CoreMinimal.h"
#include "EGameDebugDispCollision.generated.h"

UENUM(BlueprintType)
enum class EGameDebugDispCollision : uint8 {
    Min,
    CharacterMove = Min,
    CharacterAttack,
    CharacterDamage,
    CharacterClashing,
    EffectAttack,
    EffectDamage,
    BattleAreaCharacter,
    BattleAreaEffect,
    Background,
    Destructible,
    UCX_WorldStatic,
    UCX_Destructible,
    UCX_GameGround,
    UCX_GameBackground,
    UCX_GameRoof,
    UCX_GameTransprency,
    UCX_GameDestructibleRoof,
    UCX_Other,
    Max = UCX_Other,
    Num,
    Invalid = 255,
};


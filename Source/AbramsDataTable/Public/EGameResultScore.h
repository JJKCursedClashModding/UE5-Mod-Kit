#pragma once
#include "CoreMinimal.h"
#include "EGameResultScore.generated.h"

UENUM(BlueprintType)
enum class EGameResultScore : uint8 {
    None,
    Win,
    OverwhelmingWin,
    GoodFight,
    Defeat,
    Assist,
    Damage,
    LevelUp,
    MaximumOutput,
    LinkCombo,
    SpecialTagCombo,
    SuperCursedEnergyAttack,
    SpecialAttackFinish,
    FirstAttack,
    FirstKill,
    NoGuard,
    NoDeath,
    NoDamage,
    FastFinish,
    GuardBreak,
    Finisher,
    Debuff,
    LongShot,
    KillStreak,
    Involvement,
    JustGuard,
    Runner,
    WallBound,
    GroundBound,
    ReturnToHell,
    DomainExpansionReturn,
    Provocation,
    DomainExpansionOverlap,
    Respect,
    NoOperation,
    Invalid = 255,
};


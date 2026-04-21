#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterBehaviorThinkPriority.generated.h"

UENUM()
enum class EGameCharacterBehaviorThinkPriority {
    ChangeTarget = 10,
    CooperationChangeTarget = 20,
    OwnerDead = 30,
    BreakFall = 40,
    OwnerDown = 50,
    InSimpleDomainCounter = 60,
    TargetDead = 70,
    TagCombo = 80,
    JustGuarded = 90,
    GuardCounter = 100,
    TargetCounter = 110,
    TargetedAttacking = 120,
    TargetUpperGround = 130,
    GuardBreakAttack = 140,
    DamagingAttack = 150,
    TargetGuard = 160,
    UnscalableWall = 170,
    Wall = 180,
    Shooter = 190,
    Escape = 200,
    FarTarget = 210,
    TargetDown = 220,
    TeammateAttacking = 230,
    TargetCharging = 240,
    Cooperation = 250,
    Onslaught = 260,
    Carefully = 270,
    Rampage = 280,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetCaptureType.generated.h"

UENUM()
enum class EGameWidgetCaptureType : uint64 {
    None,
    CharacterSelect,
    StoryCharacterSelect,
    VsAlly_01 = 16,
    VsAlly_02 = 32,
    VsAlly_03 = 64,
    VsAlly_04 = 128,
    VsAlly_05 = 256,
    VsAlly_06 = 512,
    VsEnemy_01 = 4096,
    VsEnemy_02 = 8192,
    VsEnemy_03 = 16384,
    VsEnemy_04 = 32768,
    VsEnemy_05 = 65536,
    VsEnemy_06 = 131072,
    FreeBattle = 1048576,
    Customize_01 = 8388608,
    Customize_02 = 16777216,
    Customize_03 = 33554432,
    Customize_04 = 67108864,
    Customize_05 = 134217728,
    Customize_06 = 268435456,
    Archive = 1073741824,
    FreeBattleImage = 2147483648,
    CP_270_TagCombo = 4294967296,
    VsAlly = 1008,
    VsEnemy = 258048,
    Customize = 528482304,
    Invalid = -1,
};


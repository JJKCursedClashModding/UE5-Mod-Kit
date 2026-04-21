#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSoundVoiceGroupType.generated.h"

UENUM(BlueprintType)
enum class EGameCharacterSoundVoiceGroupType : uint8 {
    None,
    CharacterSelect,
    CharacterReselect,
    Ready,
    LobbyGoToBattle,
    LobbyChangedMatchRule,
    ResultRank_S,
    ResultRank_A,
    ResultRank_B_Lower,
    ResultWinningStreak_05,
    ResultWinningStreak_10,
    ResultWinningStreak_15,
    ResultWinningStreak_20,
    ResultOpenResultItem,
    ResultPromoteRank,
    ResultDemoteRank,
    RematchSuccessRematch,
    RematchInWaitingOtherPlayer,
    RematchSelectFind,
    RematchDeclinedRematchByOther,
    RematchDeclinedRematchByMyself,
    Invalid = 255,
};


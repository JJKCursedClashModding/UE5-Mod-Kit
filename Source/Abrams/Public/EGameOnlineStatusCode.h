#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineStatusCode.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineStatusCode : uint8 {
    Processing,
    Success,
    NetworkConnectionUnavailable,
    TimeOut,
    BeaconIsNull,
    LoginFailure,
    PrivilegeAccountTypeFailure,
    PrivilegeAgeRestrictionFailure,
    PrivilegeOnlinePlayFailure,
    PrivilegePatchFailure,
    CommunicateTypeFailure,
    FindSessionsFailure,
    CancelFindSessionsFailure,
    JoinSessionFailure,
    JoinSessionIsFull,
    JoinSessionDoesNotExist,
    CreateSessionFailure,
    MatchmakingFailure,
    CancelMatchmakingFailure,
    InvitedSessionFailure,
    PasswordFailure,
    JoinRequestFailure,
    BattleSettingsReceiveFailure,
    ReadLeaderboardFailure,
    WriteLeaderboardFailure,
    ReadFriendsListFailure,
    QueryBlockedPlayersFailure,
    ShowStoreUIFailure,
    ShowWebURLFailure,
    ShowAccountUpgradeUIFailure,
    SteamOverlayDisabled,
    UnknownError,
    Invalid = 255,
};


#pragma once
#include "CoreMinimal.h"
#include "EGameOnlineLobbyFindFriendType.generated.h"

UENUM(BlueprintType)
enum class EGameOnlineLobbyFindFriendType : uint8 {
    NotFriend,
    FriendOnly,
    Either,
};


#pragma once
#include "CoreMinimal.h"
#include "OnlineAchievementsManager.h"
#include "GameOnlineAchievementsManager.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameOnlineAchievementsManager : public UOnlineAchievementsManager {
    GENERATED_BODY()
public:
    UGameOnlineAchievementsManager();

};


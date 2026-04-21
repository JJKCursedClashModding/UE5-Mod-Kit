#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EGameBattleTeam.h"
#include "GameWidgetBattleTeamColorParameter.generated.h"

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetBattleTeamColorParameter {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameBattleTeam, FColor> BattleTeamColor;
    
public:
    FGameWidgetBattleTeamColorParameter();
};


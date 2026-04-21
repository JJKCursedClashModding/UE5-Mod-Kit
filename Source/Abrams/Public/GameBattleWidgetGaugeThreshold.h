#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EGameBattleWidgetHPGaugeRateType.h"
#include "GameBattleWidgetGaugeThreshold.generated.h"

class UNiagaraSystem;

USTRUCT(BlueprintType)
struct FGameBattleWidgetGaugeThreshold {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Rate;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBattleWidgetHPGaugeRateType RateType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor PlayerTeamColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor RivalTeamColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FColor PlayerTeamStatusColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UNiagaraSystem* HPGaugeNiagaraSystem;
    
public:
    ABRAMS_API FGameBattleWidgetGaugeThreshold();
};


#pragma once
#include "CoreMinimal.h"
#include "EGameCursedEnergyGaugeType.h"
#include "GameWidgetCharaModelViewerParameter.h"
#include "GameWidgetCursedEnergyGaugeParameter.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetCharacterParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetCharacterParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameCursedEnergyGaugeType, FGameWidgetCursedEnergyGaugeParameter> CursedEnergyGaugeParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameWidgetCharaModelViewerParameter> CharaModelViewerParameterMap;
    
public:
    UGameWidgetCharacterParameter();

};


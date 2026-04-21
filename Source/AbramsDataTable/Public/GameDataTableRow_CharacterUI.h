#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGameCharacterEnergyType.h"
#include "EGameCursedEnergyGaugeType.h"
#include "GameDataTableRow_CharacterUI.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_CharacterUI : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterEnergyType CharacterEnergyType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCursedEnergyGaugeType CursedEnergyGaugeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TargetCursorHeightRate;
    
    FGameDataTableRow_CharacterUI();
};


#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGameBattleLogConditionType.h"
#include "EGameBattleLogPassiveType.h"
#include "EGameBattleLogTargetType.h"
#include "EGameBattleLogValueType.h"
#include "EGameBindingVowsEffectType.h"
#include "GameDataTableRow_MissionTask.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_MissionTask : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameBattleLogValueType> ValueType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameBattleLogTargetType> TargetType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameBattleLogPassiveType> PassiveType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<float> Value;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameBattleLogConditionType> ConditionType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Id_BattleText_TaskDetail;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameBindingVowsEffectType> ExcludeBindingVowsEffectType;
    
    FGameDataTableRow_MissionTask();
};


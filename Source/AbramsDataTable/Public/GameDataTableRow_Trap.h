#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGameTrapActionType.h"
#include "GameDataTableRow_Trap.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_Trap : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName FileName_BP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameTrapActionType ActionType;
    
    FGameDataTableRow_Trap();
};


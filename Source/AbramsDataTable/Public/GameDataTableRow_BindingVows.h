#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGameBindingVowsDifficulty.h"
#include "GameDataTableRow_BindingVows.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_BindingVows : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameBindingVowsDifficulty Difficulty;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Id_BindingVowsEffect;
    
    FGameDataTableRow_BindingVows();
};


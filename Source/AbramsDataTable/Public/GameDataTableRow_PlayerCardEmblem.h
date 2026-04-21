#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGameEmblemGradeType.h"
#include "GameDataTableRow_PlayerCardEmblem.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_PlayerCardEmblem : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameEmblemGradeType GradeType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_Character;
    
    FGameDataTableRow_PlayerCardEmblem();
};


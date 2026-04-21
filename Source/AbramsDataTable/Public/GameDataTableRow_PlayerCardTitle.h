#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameDataTableRow_PlayerCardTitle.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_PlayerCardTitle : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_Item;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_ItemText;
    
    FGameDataTableRow_PlayerCardTitle();
};


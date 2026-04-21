#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameDataTableRow_ScriptCharacterClothes.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_ScriptCharacterClothes : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ClothesFileName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> FacialFileName;
    
    FGameDataTableRow_ScriptCharacterClothes();
};


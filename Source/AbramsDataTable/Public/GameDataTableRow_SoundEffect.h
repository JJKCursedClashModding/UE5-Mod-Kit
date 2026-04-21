#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "GameDataTableRow_SoundEffect.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_SoundEffect : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CueSheetName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString CueName;
    
    FGameDataTableRow_SoundEffect();
};


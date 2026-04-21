#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGameCharacterFacialPartsMouth.h"
#include "GameDataTableRow_CharacterMouthPattern.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_CharacterMouthPattern : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float AnimationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float EndAnimationTime;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameCharacterFacialPartsMouth> MouthTypeArray;
    
    FGameDataTableRow_CharacterMouthPattern();
};


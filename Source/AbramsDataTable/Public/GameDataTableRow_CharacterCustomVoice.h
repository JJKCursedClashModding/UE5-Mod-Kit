#pragma once
#include "CoreMinimal.h"
#include "Engine/DataTable.h"
#include "EGameCustomVoiceCategory.h"
#include "EGameCustomVoiceIndexType.h"
#include "GameDataTableRow_CharacterCustomVoice.generated.h"

USTRUCT(BlueprintType)
struct ABRAMSDATATABLE_API FGameDataTableRow_CharacterCustomVoice : public FTableRowBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCustomVoiceCategory Category;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCustomVoiceIndexType IndexType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FName> Id_Voice_Sample;
    
    FGameDataTableRow_CharacterCustomVoice();
};


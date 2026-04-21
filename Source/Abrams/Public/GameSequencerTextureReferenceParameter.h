#pragma once
#include "CoreMinimal.h"
#include "GameSequencerTextureReferenceParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameSequencerTextureReferenceParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_Character;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TextureName;
    
    ABRAMS_API FGameSequencerTextureReferenceParameter();
};


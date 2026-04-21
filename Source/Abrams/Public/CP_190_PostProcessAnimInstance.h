#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameCharacterPostProcessAnimInstance.h"
#include "CP_190_PostProcessAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UCP_190_PostProcessAnimInstance : public UGameCharacterPostProcessAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float SleeveLocationOffsetAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Sleeve_R_A1_LocationOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector Sleeve_L_A1_LocationOffset;
    
public:
    UCP_190_PostProcessAnimInstance();

};


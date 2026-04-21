#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameCharacterAnimInstance.h"
#include "CN_150_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UCN_150_AnimInstance : public UGameCharacterAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LeftBackToeEffectLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftBackToeAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RightBackToeEffectLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightBackToeAlpha;
    
    UCN_150_AnimInstance();

};


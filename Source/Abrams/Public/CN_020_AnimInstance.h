#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameShikigamiAnimInstance.h"
#include "CN_020_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UCN_020_AnimInstance : public UGameShikigamiAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector LeftHandEffectLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeftHandAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector RightHandEffectLocation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float RightHandAlpha;
    
    UCN_020_AnimInstance();

};


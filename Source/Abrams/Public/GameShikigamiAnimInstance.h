#pragma once
#include "CoreMinimal.h"
#include "GameActorAnimInstance.h"
#include "GameShikigamiAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UGameShikigamiAnimInstance : public UGameActorAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeanRateUD;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float LeanAlpha;
    
    UGameShikigamiAnimInstance();

};


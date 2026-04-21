#pragma once
#include "CoreMinimal.h"
#include "GameShikigamiAnimInstance.h"
#include "CN_030_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UCN_030_AnimInstance : public UGameShikigamiAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TongueLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TongueAlpha;
    
    UCN_030_AnimInstance();

};


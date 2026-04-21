#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameShikigamiAnimInstance.h"
#include "CN_050_AnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UCN_050_AnimInstance : public UGameShikigamiAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TailLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> TailTransformArray;
    
    UCN_050_AnimInstance();

};


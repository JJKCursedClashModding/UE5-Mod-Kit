#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameTrapAnimInstance.h"
#include "GameTrapAnimInstance_PlantRoot.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UGameTrapAnimInstance_PlantRoot : public UGameTrapAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float BoneLength;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurveAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransform> BoneTransformArray;
    
    UGameTrapAnimInstance_PlantRoot();

};


#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameCharacterPostProcessAnimInstance.h"
#include "CP_200_PostProcessAnimInstance.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UCP_200_PostProcessAnimInstance : public UGameCharacterPostProcessAnimInstance {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CurseRotateAlpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator CurseBodyARotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator CurseBodyBRotation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator CurseHeadRotation;
    
public:
    UCP_200_PostProcessAnimInstance();

};


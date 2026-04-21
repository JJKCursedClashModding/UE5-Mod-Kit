#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameTrapAnimInstance.h"
#include "GameTrapAnimInstance_Volcano.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UGameTrapAnimInstance_Volcano : public UGameTrapAnimInstance {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FRotator ShootRotation;
    
    UGameTrapAnimInstance_Volcano();

};


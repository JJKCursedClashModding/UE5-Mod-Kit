#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "EGameDebugDispCollision.h"
#include "GameParameterBase.h"
#include "GameDebugParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameDebugParameter : public UGameParameterBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameDebugDispCollision, FColor> DebugCollisionColor;
    
    UGameDebugParameter();

};


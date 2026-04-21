#pragma once
#include "CoreMinimal.h"
#include "GameParameterBase.h"
#include "GameSequencerGlobalOffsetParameter.h"
#include "GameSequencerOffsetParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameSequencerOffsetParameter : public UGameParameterBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameSequencerGlobalOffsetParameter> SettingsMap;
    
    UGameSequencerOffsetParameter();

};


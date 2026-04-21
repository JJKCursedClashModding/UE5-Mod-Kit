#pragma once
#include "CoreMinimal.h"
#include "GameParameterBase.h"
#include "GameSequencerLoadingFileParameter.h"
#include "GameSequencerLoadingParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameSequencerLoadingParameter : public UGameParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameSequencerLoadingFileParameter> FileParameters;
    
public:
    UGameSequencerLoadingParameter();

};


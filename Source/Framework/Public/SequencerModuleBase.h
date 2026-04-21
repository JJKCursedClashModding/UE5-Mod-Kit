#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "SequencerModuleBase.generated.h"

class UMovieSceneSection;

UCLASS(Blueprintable)
class FRAMEWORK_API USequencerModuleBase : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Export, meta=(AllowPrivateAccess=true))
    TWeakObjectPtr<UMovieSceneSection> SourceSectionPtr;
    
public:
    USequencerModuleBase();

};


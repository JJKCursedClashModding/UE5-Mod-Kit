#pragma once
#include "CoreMinimal.h"
#include "MovieSceneSection.h"
#include "EntitySystem/IMovieSceneEntityProvider.h"
#include "UObject/NoExportTypes.h"
#include "SequencerSectionInterface.h"
#include "SequencerSectionBase.generated.h"

class USequencerModuleBase;

UCLASS(Abstract, Blueprintable)
class FRAMEWORK_API USequencerSectionBase : public UMovieSceneSection, public IMovieSceneEntityProvider, public ISequencerSectionInterface {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<USequencerModuleBase*> Modules;
    
public:
    USequencerSectionBase();

    // IMovieSceneEntityProvider — required pure virtual in UE 5.1
    virtual void ImportEntityImpl(UMovieSceneEntitySystemLinker* Linker, const FEntityImportParams& Params, FImportedEntity* OutImportedEntity) override {}
};


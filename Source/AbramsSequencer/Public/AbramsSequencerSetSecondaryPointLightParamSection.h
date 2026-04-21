#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "Channels/MovieSceneFloatChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSetSecondaryPointLightParamSection.generated.h"

class UMaterialParameterCollection;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSetSecondaryPointLightParamSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bIsUseMulti;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneFloatChannel Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UMaterialParameterCollection*> PointLightParameterCollections;
    
    UAbramsSequencerSetSecondaryPointLightParamSection();

};


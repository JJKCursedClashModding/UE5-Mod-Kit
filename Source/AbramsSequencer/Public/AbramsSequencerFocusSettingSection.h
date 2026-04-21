#pragma once
#include "CoreMinimal.h"
#include "MovieSceneObjectBindingID.h"
#include "AbramsSequencerSectionBindingBase.h"
#include "AbramsSequencerFocusSettingSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerFocusSettingSection : public UAbramsSequencerSectionBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneObjectBindingID FocusActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFallbackFindFromClass;
    
    UAbramsSequencerFocusSettingSection();

};


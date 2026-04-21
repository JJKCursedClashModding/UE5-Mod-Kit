#pragma once
#include "CoreMinimal.h"
#include "Channels/MovieSceneBoolChannel.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerCharacterAndWeaponVisibilitySection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerCharacterAndWeaponVisibilitySection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneBoolChannel bVisibility;
    
    UAbramsSequencerCharacterAndWeaponVisibilitySection();

};


#pragma once
#include "CoreMinimal.h"
#include "MovieSceneObjectBindingID.h"
#include "AbramsSequencerSectionBindingBase.h"
#include "AbramsSequencerSectionGameActorConstraintBase.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSectionGameActorConstraintBase : public UAbramsSequencerSectionBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneObjectBindingID TargetActor;
    
    UAbramsSequencerSectionGameActorConstraintBase();

};


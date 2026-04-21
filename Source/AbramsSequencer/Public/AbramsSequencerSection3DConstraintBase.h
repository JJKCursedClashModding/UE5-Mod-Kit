#pragma once
#include "CoreMinimal.h"
#include "MovieSceneObjectBindingID.h"
#include "AbramsSequencerSectionBindingBase.h"
#include "AbramsSequencerSection3DConstraintBase.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSection3DConstraintBase : public UAbramsSequencerSectionBindingBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FMovieSceneObjectBindingID ConstraintBindingID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName AttachBoneName;
    
    UAbramsSequencerSection3DConstraintBase();

};


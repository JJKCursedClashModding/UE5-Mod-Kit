#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerActorType.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerAttachBindingParameterActorSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerAttachBindingParameterActorSection : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerActorType TargetClassType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName TargetCharacterTag;
    
    UAbramsSequencerAttachBindingParameterActorSection();

};


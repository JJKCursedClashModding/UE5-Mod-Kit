#pragma once
#include "CoreMinimal.h"
#include "EGameSequencerWidgetType.h"
#include "AbramsSequencerSectionMasterWidgetBase.h"
#include "AbramsSequencerOpenLevelSequenceWidgetSection.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerOpenLevelSequenceWidgetSection : public UAbramsSequencerSectionMasterWidgetBase {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameSequencerWidgetType WidgetType;
    
    UAbramsSequencerOpenLevelSequenceWidgetSection();

};


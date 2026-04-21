#pragma once
#include "CoreMinimal.h"
#include "GameWidgetChatParameter.generated.h"

class UPaperSprite;

USTRUCT(BlueprintType)
struct ABRAMS_API FGameWidgetChatParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UPaperSprite* ChatIconSprite;
    
    FGameWidgetChatParameter();
};


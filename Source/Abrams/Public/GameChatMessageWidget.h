#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameChatMessageWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameChatMessageWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 ChatSpace;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 StampSpace;
    
public:
    UGameChatMessageWidget();

};


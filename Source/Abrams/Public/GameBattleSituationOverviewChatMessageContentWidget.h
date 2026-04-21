#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleSituationOverviewChatMessageContentWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSituationOverviewChatMessageContentWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ChatMessage;
    
public:
    UGameBattleSituationOverviewChatMessageContentWidget();

};


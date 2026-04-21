#pragma once
#include "CoreMinimal.h"
#include "GameChatMessageContentWidget.h"
#include "GameBattleSymbolChatMessageContentWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSymbolChatMessageContentWidget : public UGameChatMessageContentWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* SystemMessageText;
    
public:
    UGameBattleSymbolChatMessageContentWidget();

};


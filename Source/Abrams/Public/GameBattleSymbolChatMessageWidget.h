#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleSymbolChatMessageWidget.generated.h"

class UGameBattleSymbolChatMessageContentWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSymbolChatMessageWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSymbolChatMessageContentWidget* SymbolChatMessage_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSymbolChatMessageContentWidget* SymbolChatMessage_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSymbolChatMessageContentWidget* SymbolChatMessage_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 MessageSpacing;
    
public:
    UGameBattleSymbolChatMessageWidget();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameWidgetInputGuide.h"
#include "GameBattleSymbolChatWidget.generated.h"

class UGameBattleChatMethodDirectionWidget;
class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSymbolChatWidget : public UGameWidgetBase, public IGameBattleWidgetContent, public IGameWidgetInputGuide {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleChatMethodDirectionWidget* UpKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleChatMethodDirectionWidget* DownKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleChatMethodDirectionWidget* RightKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleChatMethodDirectionWidget* LeftKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* SpamPreventionIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ChatInputImage;
    
public:
    UGameBattleSymbolChatWidget();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetTabWindow.h"
#include "GameCommonChatListWindowWidget.generated.h"

class UGameCommonChatListViewWidget;
class UGameWidgetTabWindowContent;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCommonChatListWindowWidget : public UGameWidgetTabWindow {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonChatListViewWidget* ConversationChatList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonChatListViewWidget* TacticsChatList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonChatListViewWidget* UniqueChatList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonChatListViewWidget* StampList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTabWindowContent* ConversationButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTabWindowContent* TacticsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTabWindowContent* UniqueButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTabWindowContent* StampButton;
    
public:
    UGameCommonChatListWindowWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameChatListWidget.generated.h"

class UGameChatListItemData;
class UGameChatListViewWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameChatListWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameChatListViewWidget* ChatList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameChatListItemData*> ItemDataList;
    
public:
    UGameChatListWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "EGameChatCategory.h"
#include "GameCommonChatListItemData.h"
#include "GameCommonStampListItemData.h"
#include "GameWindowBase.h"
#include "GameCommonChatListWidget.generated.h"

class UGameCommonChatListWindowWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCommonChatListWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonChatListWindowWidget* ChatWindow;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameChatCategory, FGameCommonChatListItemData> ChatListItemDataMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameCommonStampListItemData StampListItemData;
    
public:
    UGameCommonChatListWidget();

};


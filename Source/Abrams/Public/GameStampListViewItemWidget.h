#pragma once
#include "CoreMinimal.h"
#include "GameChatListViewItemWidgetBase.h"
#include "GameStampListViewItemWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStampListViewItemWidget : public UGameChatListViewItemWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Stamp;
    
public:
    UGameStampListViewItemWidget();

};


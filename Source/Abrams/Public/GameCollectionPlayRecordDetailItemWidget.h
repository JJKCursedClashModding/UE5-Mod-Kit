#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameWidgetScrollListItem.h"
#include "GameCollectionPlayRecordDetailItemWidget.generated.h"

class UCanvasPanel;
class UGameWidgetRichTextBlock;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionPlayRecordDetailItemWidget : public UGameWidgetBase, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* HeaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* RecordText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* SymbolText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* DelimiterText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ItemCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* DelimiterCanvas;
    
public:
    UGameCollectionPlayRecordDetailItemWidget();


    // Fix for true pure virtual functions not being implemented
};


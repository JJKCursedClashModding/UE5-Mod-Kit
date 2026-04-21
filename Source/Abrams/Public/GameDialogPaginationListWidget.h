#pragma once
#include "CoreMinimal.h"
#include "GameWidgetPaginationListView.h"
#include "GameDialogPaginationListWidget.generated.h"

class USizeBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameDialogPaginationListWidget : public UGameWidgetPaginationListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USizeBox* ScrollBoxSizeBox;
    
public:
    UGameDialogPaginationListWidget();

};


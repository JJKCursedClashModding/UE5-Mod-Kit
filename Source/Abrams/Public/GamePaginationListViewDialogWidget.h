#pragma once
#include "CoreMinimal.h"
#include "GamePopupDialogWidgetBase.h"
#include "GamePaginationListViewDialogWidget.generated.h"

class UGameWidgetButton;
class UGameWidgetPaginationListView;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGamePaginationListViewDialogWidget : public UGamePopupDialogWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetPaginationListView* PaginationListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* OkButton;
    
public:
    UGamePaginationListViewDialogWidget();

};


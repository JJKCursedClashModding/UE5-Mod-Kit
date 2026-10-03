#pragma once
#include "CoreMinimal.h"
#include "GameWidgetScrollListView.h"
#include "GameRankingFilterWidget.generated.h"

class UGameRankingFilterToggleButtonWidget;
class UGameWidgetButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankingFilterWidget : public UGameWidgetScrollListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetButton* AllCharaSelectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetButton* AllCharaDeselectButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingFilterToggleButtonWidget* AscendingOrderButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameRankingFilterToggleButtonWidget* DescendingOrderButton;
    
public:
    UGameRankingFilterWidget();

};


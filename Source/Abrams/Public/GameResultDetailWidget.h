#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameResultDetailWidget.generated.h"

class UGameResultScoreListViewWidget;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameResultDetailWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultScoreListViewWidget* ScoreListView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TotalScoreText;
    
public:
    UGameResultDetailWidget();

};


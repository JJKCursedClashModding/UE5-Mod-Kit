#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameWidgetScrollListItem.h"
#include "GameResultScoreListItemWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameResultScoreListItemWidget : public UGameWidgetButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ScoreLabelText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ScoreText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ScoreSignText;
    
public:
    UGameResultScoreListItemWidget();


    // Fix for true pure virtual functions not being implemented
};


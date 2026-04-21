#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleSituationOverviewPlayerCardWidget.generated.h"

class UGamePlayerCardWidget;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSituationOverviewPlayerCardWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* PlayerIndexText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGamePlayerCardWidget* PlayerCardWidget;
    
public:
    UGameBattleSituationOverviewPlayerCardWidget();

};


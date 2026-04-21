#pragma once
#include "CoreMinimal.h"
#include "GameNotifyMessageDialogWidget.h"
#include "GameConfigNotifyMessageDialogWidget.generated.h"

class UPanelWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigNotifyMessageDialogWidget : public UGameNotifyMessageDialogWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* SameRegionOnlyMatchingPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* OpenRankMatchingPanel;
    
public:
    UGameConfigNotifyMessageDialogWidget();

};


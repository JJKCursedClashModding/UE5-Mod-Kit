#pragma once
#include "CoreMinimal.h"
#include "GamePopupDialogWidgetBase.h"
#include "GameCharaRelateLevelDialogWidget.generated.h"

class UGameCharaRelateLevelListWidget;
class UGameWidgetButton;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameCharaRelateLevelDialogWidget : public UGamePopupDialogWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* OkButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharaRelateLevelListWidget* CharaRelateLevelList;
    
public:
    UGameCharaRelateLevelDialogWidget();

};


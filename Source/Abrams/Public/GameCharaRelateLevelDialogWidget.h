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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetButton* OkButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCharaRelateLevelListWidget* CharaRelateLevelList;
    
public:
    UGameCharaRelateLevelDialogWidget();

};


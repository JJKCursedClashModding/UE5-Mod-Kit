#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameCreditWidget.generated.h"

class UGameCreditContentPanelWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCreditWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCreditContentPanelWidget* DefaultCreditWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCreditContentPanelWidget* ShortCreditWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCreditContentPanelWidget* DlcCreditWidget_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCreditContentPanelWidget* DlcCreditWidget_2;
    
public:
    UGameCreditWidget();

};


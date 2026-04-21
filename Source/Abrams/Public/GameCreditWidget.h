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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCreditContentPanelWidget* DefaultCreditWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCreditContentPanelWidget* ShortCreditWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCreditContentPanelWidget* DlcCreditWidget_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCreditContentPanelWidget* DlcCreditWidget_2;
    
public:
    UGameCreditWidget();

};


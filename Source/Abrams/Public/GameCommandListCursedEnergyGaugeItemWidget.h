#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCommandListCursedEnergyGaugeItemWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCommandListCursedEnergyGaugeItemWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CursedEnergyGaugeImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* AddImage;
    
public:
    UGameCommandListCursedEnergyGaugeItemWidget();

};


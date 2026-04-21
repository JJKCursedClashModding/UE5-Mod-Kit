#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GamePlayerCardPlateWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGamePlayerCardPlateWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* PlateImage;
    
public:
    UGamePlayerCardPlateWidget();

};


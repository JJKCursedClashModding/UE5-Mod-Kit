#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GamePlayerCardEmblemWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGamePlayerCardEmblemWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* EmblemIconImage;
    
public:
    UGamePlayerCardEmblemWidget();

};


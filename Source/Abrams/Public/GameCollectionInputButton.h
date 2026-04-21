#pragma once
#include "CoreMinimal.h"
#include "GameWidgetInputImageButton.h"
#include "GameCollectionInputButton.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionInputButton : public UGameWidgetInputImageButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* DisplayImage;
    
public:
    UGameCollectionInputButton();

};


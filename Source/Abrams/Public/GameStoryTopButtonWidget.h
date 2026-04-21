#pragma once
#include "CoreMinimal.h"
#include "WidgetLocalization.h"
#include "GameWidgetButton.h"
#include "GameStoryTopButtonWidget.generated.h"

class UGameWidgetImage;
class UTexture;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryTopButtonWidget : public UGameWidgetButton, public IWidgetLocalization {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture* IconTexture;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLineBreak;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Icon;
    
public:
    UGameStoryTopButtonWidget();


    // Fix for true pure virtual functions not being implemented
};


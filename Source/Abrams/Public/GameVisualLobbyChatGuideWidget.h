#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameWidgetInputGuide.h"
#include "GameVisualLobbyChatGuideWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetInputImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVisualLobbyChatGuideWidget : public UGameWidgetBase, public IGameWidgetInputGuide {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* UpIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* DownIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* LeftIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* RightIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ChatInputImage;
    
public:
    UGameVisualLobbyChatGuideWidget();


    // Fix for true pure virtual functions not being implemented
};


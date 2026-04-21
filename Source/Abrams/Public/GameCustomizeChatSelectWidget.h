#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameCustomizeChatSelectWidget.generated.h"

class UGameCustomizeChatCommandWidget;
class UGameWidgetInputImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizeChatSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeChatCommandWidget* UpCommand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeChatCommandWidget* DownCommand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeChatCommandWidget* LeftCommand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeChatCommandWidget* RightCommand;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* UpIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* DownIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* LeftIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* RightIcon;
    
public:
    UGameCustomizeChatSelectWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryEarnedRewardNotifyWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetInputGuideText;
class UGameWidgetStoryEarnedRewardCloseButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryEarnedRewardNotifyWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetInputGuideText* CategoryMessageText1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetInputGuideText* CategoryMessageText2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetInputGuideText* CategoryMessageText3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetInputGuideText* CategoryMessageText4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* CategoryIcon1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* CategoryIcon2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* CategoryIcon3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* CategoryIcon4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetStoryEarnedRewardCloseButton* CloseButton;
    
public:
    UGameStoryEarnedRewardNotifyWidget();

};


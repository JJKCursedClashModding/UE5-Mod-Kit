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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* CategoryMessageText1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* CategoryMessageText2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* CategoryMessageText3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputGuideText* CategoryMessageText4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CategoryIcon1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CategoryIcon2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CategoryIcon3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CategoryIcon4;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetStoryEarnedRewardCloseButton* CloseButton;
    
public:
    UGameStoryEarnedRewardNotifyWidget();

};


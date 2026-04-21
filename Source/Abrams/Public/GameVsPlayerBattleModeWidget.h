#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsPlayerBattleModeWidget.generated.h"

class UGameWidgetButton;
class UGameWidgetVsPlayerBattleModeButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsPlayerBattleModeWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsPlayerBattleModeButton* TagFreeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsPlayerBattleModeButton* TagRankButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* RankingButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* RankSystemButton;
    
public:
    UGameVsPlayerBattleModeWidget();

};


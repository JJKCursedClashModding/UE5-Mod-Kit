#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsPlayerWidget.generated.h"

class UGameRankSystemWidget;
class UGameRankingPvPWidget;
class UGameVsPlayerBattleModeWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsPlayerWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsPlayerBattleModeWidget* BattleModeWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankingPvPWidget* RankingWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameRankSystemWidget* RankSystemWidget;
    
public:
    UGameVsPlayerWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameResultWidget.generated.h"

class UGameChatMessageContentWidget;
class UGameCommonBackgroundBlurWidget;
class UGameOutGameTimeLimitWidget;
class UGameResultChangeRankPointWidget;
class UGameResultDetailBackgroundWidget;
class UGameResultDetailWidget;
class UGameResultMissionScoreListWidget;
class UGameResultPlayerListWidget;
class UGameResultRankWidget;
class UGameResultRewardWidget;
class UGameResultSacredTreasureCutInWidget;
class UGameResultSaveReplayWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameResultWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultDetailWidget* ResultDetailWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultDetailBackgroundWidget* ResultDetailBackgroundWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultPlayerListWidget* ResultPlayerListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultRankWidget* ResultRankWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultChangeRankPointWidget* ResultChangeRankPointWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultMissionScoreListWidget* ResultMissionScoreListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultRewardWidget* ResultRewardWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameOutGameTimeLimitWidget* TimeLimitWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCommonBackgroundBlurWidget* BackgroundBlur;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameChatMessageContentWidget* SymbolChatMessage_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameChatMessageContentWidget* SymbolChatMessage_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultSaveReplayWidget* SaveReplayWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCommonBackgroundBlurWidget* ArcadeBackgroundBlur;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameResultSacredTreasureCutInWidget* SacredTreasureCutIn;
    
public:
    UGameResultWidget();

};


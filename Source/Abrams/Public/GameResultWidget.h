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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultDetailWidget* ResultDetailWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultDetailBackgroundWidget* ResultDetailBackgroundWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultPlayerListWidget* ResultPlayerListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultRankWidget* ResultRankWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultChangeRankPointWidget* ResultChangeRankPointWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultMissionScoreListWidget* ResultMissionScoreListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultRewardWidget* ResultRewardWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameOutGameTimeLimitWidget* TimeLimitWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonBackgroundBlurWidget* BackgroundBlur;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameChatMessageContentWidget* SymbolChatMessage_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameChatMessageContentWidget* SymbolChatMessage_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultSaveReplayWidget* SaveReplayWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonBackgroundBlurWidget* ArcadeBackgroundBlur;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameResultSacredTreasureCutInWidget* SacredTreasureCutIn;
    
public:
    UGameResultWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "EGameMissionDifficulty.h"
#include "UObject/NoExportTypes.h"
#include "GameWindowBase.h"
#include "GameVsEnemyIntervalWidget.generated.h"

class UGameChatMessageWidget;
class UGameOutGameTimeLimitWidget;
class UGameVsEnemyBindingVowsSelectWidget;
class UGameVsEnemyIntervalCharacterWidget;
class UGameVsEnemyIntervalExtraMissionSuggestionWidget;
class UGameVsEnemyIntervalForceGaugeWidget;
class UGameVsEnemyIntervalMissionProgressWidget;
class UGameVsEnemyIntervalWaveInfoWidget;
class UGameVsEnemyRecoverySelectWidget;
class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyIntervalWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyRecoverySelectWidget* RecoverySelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyBindingVowsSelectWidget* BindingVowsSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalCharacterWidget* PlayerCharacterInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalCharacterWidget* PartnerCharacterInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalForceGaugeWidget* ForceGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalWaveInfoWidget* WaveInfo1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalWaveInfoWidget* WaveInfo2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalWaveInfoWidget* WaveInfo3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalMissionProgressWidget* MissionProgress;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* MissionDifficultyText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameOutGameTimeLimitWidget* TimeLimit;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameMissionDifficulty, FLinearColor> DifficultyColorMap_BG;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameMissionDifficulty, FLinearColor> DifficultyColorMap_Smoke_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameMissionDifficulty, FLinearColor> DifficultyColorMap_Smoke_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameMissionDifficulty, FLinearColor> DifficultyColorMap_Gradation_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameMissionDifficulty, FLinearColor> DifficultyColorMap_Background;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BG;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Smoke_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Smoke_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Gradation_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Background;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameChatMessageWidget* ChatMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyIntervalExtraMissionSuggestionWidget* ExtraMissionSuggestion;
    
public:
    UGameVsEnemyIntervalWidget();

};


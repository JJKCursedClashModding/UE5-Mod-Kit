#pragma once
#include "CoreMinimal.h"
#include "DebugWidgetBase.h"
#include "Types/SlateEnums.h"
#include "DebugMenuWidget.generated.h"

class UDebugWidgetCheckBox;
class UDebugWidgetComboBox;
class UDebugWidgetSlider;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UDebugMenuWidget : public UDebugWidgetBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetCheckBox* RandomInputKeyCheckBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TMap<FString, UDebugWidgetCheckBox*> DlcEnabledCheckBoxMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* LoadReplayComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* AddBuffDebuffComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* LeaderboardTypeComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDebugWidgetComboBox*> PvEAIComboBoxArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDebugWidgetComboBox*> PvEAIEnumComboBoxArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDebugWidgetComboBox*> ArcadeAIComboBoxArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDebugWidgetComboBox*> ArcadeAIEnumComboBoxArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* OnlinePenaltyLevelComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* OnlinePenaltyLevelDownBattleCountComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* ArcadeClearFlagComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* BuildUniqueIdSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* FOVSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* CullingDistanceNearSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* FreeCameraDistanceSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* TargetCameraDistanceSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* TargetCameraActionDistanceSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* ShootCameraDistanceSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* CameraOwnerHeightOffsetSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* CameraTargetHeightOffsetSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* TargetCameraOffsetAngleVSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* TargetCameraBaseAngleHSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* RadialBlurWeightSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* RadialBlurDistSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* RadialBlurPosXSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* RadialBlurPosYSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* RadialBlurRadiusSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* RadialBlurDensitySlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* NegaPosiWeightSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* NegaPosiScaleSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* FlareWeightSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* FlarePosXSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* FlarePosYSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* FlareRotateSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* FlareWidthMinSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* FlareWidthMaxSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* ChromaticAberrationWeightSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* ChromaticAberrationScaleSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* GrayScaleWeightSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* GrayScaleScaleSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* GammaValueSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* PaniniDSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* PaniniSSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* PaniniScreenFitSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* ScreenPercentageSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* TAACurrentFrameWeightSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* CameraRotateThresholdSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* CameraTranslateThresholdSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* LeaderboardScoreSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* SkipFrameNumberSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* ExperienceSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* PvPWinCountSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* ExtraMissionPointSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* MoneySlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* RankPointSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* RiskValueMaxSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* UserRecordComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* UserRecordValueSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* UserCharacterRecordIdComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* UserCharacterRecordValueTypeComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetSlider* UserCharacterRecordValueSlider;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UDebugWidgetComboBox* UserFixedLotteryResultComboBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDebugWidgetCheckBox*> VisibleBackgroundCollisionFlagCheckBoxArray;
    
public:
    UDebugMenuWidget();

    UFUNCTION(BlueprintCallable)
    void ResetGetLotteryItem();
    
    UFUNCTION(BlueprintCallable)
    void OnUnlockAllShopLineup();
    
    UFUNCTION(BlueprintCallable)
    void OnTimeLimitOneSecond();
    
    UFUNCTION(BlueprintCallable)
    void OnTextureStreamingEnabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnStoryDemoReleaseReset();
    
    UFUNCTION(BlueprintCallable)
    void OnStoryDemoReleaseAll();
    
    UFUNCTION(BlueprintCallable)
    void OnStatUnitGraph();
    
    UFUNCTION(BlueprintCallable)
    void OnStatUnit();
    
    UFUNCTION(BlueprintCallable)
    void OnStatSceneRendering();
    
    UFUNCTION(BlueprintCallable)
    void OnStatSceneMemory();
    
    UFUNCTION(BlueprintCallable)
    void OnStatRHI();
    
    UFUNCTION(BlueprintCallable)
    void OnStatMemoryPlatform();
    
    UFUNCTION(BlueprintCallable)
    void OnStatMemory();
    
    UFUNCTION(BlueprintCallable)
    void OnStatLevels();
    
    UFUNCTION(BlueprintCallable)
    void OnStatGame();
    
    UFUNCTION(BlueprintCallable)
    void OnStatFPS();
    
    UFUNCTION(BlueprintCallable)
    void OnShowLODInformation(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVoiceId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVoiceDisabled(const bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleWidgetFocusArea(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleWidgetAnimationLog(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleSoundLog(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleScript(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleSafeArea(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleRankingRecord(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleMouseHoverArea(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleMission(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleGrowthStatus(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleGroundInformation(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleEffectWallCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleEffectCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleDestructibleCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleComboCount(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterWallCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterTrail(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterStatus(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterMoveCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterLocation(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterDamageCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterClashingCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterAxis(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterAttackCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleCharacterAction(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagOther(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagNoTransprency(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagGameTransprency(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagGameRoof(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagGameGround(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagGameDestructibleRoof(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagGameBackground(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagDestructible(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionFlagAll(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollisionCheckParentVisibility(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleBackgroundCollision(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleAIThink4P(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleAIThink3P(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleAIThink2P(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleAIThink1P(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleAIMove4P(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleAIMove3P(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleAIMove2P(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetVisibleAIMove1P(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUserRecordValue(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUserRecord(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUserCharacterRecordValueType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUserCharacterRecordValue(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUserCharacterRecordId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUsePlayableCamera(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUpdateSessionInfo(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUniquePairVoiceForceSecond(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetUniqueModeIndex(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTimeLimitStop(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTimeDilationRate(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTensionLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTensionGaugeFixed(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTensionGaugeConsumeDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTargetCameraOffsetAngleV(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTargetCameraDistance(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTargetCameraBaseAngleH(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTargetCameraActionDistance(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetTAACurrentFrameWeight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetSystemSaveDataLoadEnabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetSymbolChatEnabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetStoryVoiceOverrideIndex(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetStoryRoomPlacementId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetStepActionTriggerInputEnabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetSpecialAttackUnlimited(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetSoloSpecialTagCombo(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetShowUnlockItemName(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetShowTextId(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetShowSequencerFrame(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetShowSequencerBindingLODInfo(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetShootCameraDistance(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetSequencerDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetSeId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetSeDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetScreenPercentage(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRiskValueMax(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetResultVoiceOverwhelmingWin(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetReplaySaveDataIndex(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetReleaseStoryDemoIdChapter09(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetReleaseStoryDemoIdChapter08(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetReleaseStoryDemoId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRankPoint(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRandomInputKey(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRadialBlurWeight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRadialBlurRadius(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRadialBlurPosY(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRadialBlurPosX(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRadialBlurDist(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetRadialBlurDensity(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvPWinCount(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvESurvivalModeMissionNum(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvENormalModeMissionNum(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEMissionWaveId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEMissionId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEMissionBattleLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEBindingVowsId3(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEBindingVowsId2(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEBindingVowsId1(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAllyCharacterId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIOperation6P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIOperation5P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIOperation4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIOperation3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIOperation2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIMode6P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIMode5P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIMode4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIMode3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAIMode2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAILevel6P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAILevel5P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAILevel4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAILevel3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPvEAILevel2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPostProcessAnimDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPlatform(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPhotoMode(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPassionGaugeConsumeDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPaniniScreenFit(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPaniniS(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPaniniD(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetPairSequencerFixedValue(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetOutputSequenceLog(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetOnlineUserNameHidden(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetOnlinePenaltyTime(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetOnlinePenaltyLevelDownBattleCount(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetOnlinePenaltyLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetOcclusionCameraTranslateThreshold(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetOcclusionCameraRotateThreshold(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNormalAttackVoicePattern(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkSendWaitFrame(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkInputDelayCount(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkAgingShuffleCharacterIndex(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkAgingFixedRandomStreamSeedIndex(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkAgingCharacter4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkAgingCharacter3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkAgingCharacter2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkAgingCharacter1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNetworkAgingBattleLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNegaPosiWeight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetNegaPosiScale(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetMSAASampleCount(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetMoveSpeedRate(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetMoveCollisionDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetMotionBlurEnabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetMoney(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetMaterialPattern(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetMatchingRegion(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetLookAtDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetLODSettings(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetInterpolationDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetInputMashEnabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetInputGuidePlatformHidden(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetHitSlowDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetHitPointOne();
    
    UFUNCTION(BlueprintCallable)
    void OnSetHitPointMax();
    
    UFUNCTION(BlueprintCallable)
    void OnSetHISMCHidden(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetHideStaticMesh(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetGuardBreakDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetGridHidden(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetGridHeight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetGrayScaleWeight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetGrayScaleScale(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetGammaValue(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFreeCameraDistance(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFreeCamera(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFrameRate(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFOV(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetForceNeutralCamera(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetForceGaugeMax(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetForceGaugeInfinity(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetForceFeedbackDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFootIKDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFlareWidthMin(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFlareWidthMax(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFlareWeight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFlareRotation(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFlarePosY(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFlarePosX(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetFallbackFacialParameter(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetExtraMissionPoint(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetExtraMissionOccurs(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetExperienceZero();
    
    UFUNCTION(BlueprintCallable)
    void OnSetExperienceMax();
    
    UFUNCTION(BlueprintCallable)
    void OnSetEffectNotSpawn(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetEffectHidden(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetEffectDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetEffectAsyncLoad(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDownIKDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDomainExpansionUnlimited(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlcItemCheckEnabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc11Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc10Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc08Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc07Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc05Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc04Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc03Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc02Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDlc01Enabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDisableFocusColor(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDisableAutoMouthAnimation(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDecalFadeScreenSize(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugReplay(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkTimeOutDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkSkipFrameNumber(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkSendInputDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkSameCharacterEnabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkPacket(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkNoOutOfSyncError(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkMockMode(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkMatchingSolo(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkMatchingDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkLogFile(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkLeaderboardScore(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkLANMatch(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkHighDelayMode(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkForceMatchingHost(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkForceError(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkForceBlockedUser(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugNetworkDisplayLog(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDebugCamera(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDashGaugeInfinity(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetDamageCollisionDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCursedEnergyLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCursedEnergyFixed(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCursedEnergyConsumeDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCursedEnergyAttackVoicePattern(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCullingDistanceNear(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetChromaticAberrationWeight(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetChromaticAberrationScale(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCharacterUniquePossessionConsumeDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCharacterMeshHidden(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCharacterInvincible(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCharacterInstantDeath(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetChangeOnlineUserNameDummy(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCameraTargetHeightOffset(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCameraShakeDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetCameraOwnerHeightOffset(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBuildUniqueId(float Value);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBgmDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagTimeLimit(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagTargetCursor(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagTagComboHitWidget(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagTagComboChanceWidget(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagSymbolChat(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagStartWidget(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagSpecialAttackIcon(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagRivalTeamForceGauge(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagRadar(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagPlayerTeamForceGauge(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagPlayerInfo(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagOverlay(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagOperation(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagObjectDirection(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagNotifyWidget(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagMissionInfo(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagMarker(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagLockonAlert(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagHUD(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagHPGauge(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagFinishWidget(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagDomainExpansionGauge(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagDeadEffect(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagDashGauge(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagCutInWidget(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagCursedEnergyGauge(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagAll(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleWidgetShowFlagAlert(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestPair(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestCostumeIndex4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestCostumeIndex3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestCostumeIndex2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestCostumeIndex1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestColorIndex4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestColorIndex3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestColorIndex2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestColorIndex1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestCharacter4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestCharacter3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestCharacter2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestCharacter1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestBrain1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestAIMode4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestAIMode3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleTestAIMode2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattlePhotoMode(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetBattleLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAspectRatioType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeMissionIndex(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeClearFlag(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAIOperation4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAIOperation3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAIOperation2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAIMode4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAIMode3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAIMode2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAILevel4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAILevel3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetArcadeAILevel2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAlwaysSpecialActionSuccess(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAlwaysNormalDamage(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAlwaysLinkComboSuccess(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAlwaysJustGuard(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAlwaysEmptyCursedEnergyAutoCombo(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAlwaysDestruct(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAllCharacterLevelMax();
    
    UFUNCTION(BlueprintCallable)
    void OnSetAIOperation4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAIOperation3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAIOperation2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAIOperation1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAILevel4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAILevel3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAILevel2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAILevel1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAIDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetActionCameraNumber(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetActionCameraDisabled(bool bFlag);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAchievements(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSetAAMethod(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSelectPvEResultEvaluation(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSelectDebugNetworkOverrideStatusCode(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSelectDebugNetworkMockModePlayableCharacterIndex(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSelectDebugMenuLanguage(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnSaveReplay();
    
    UFUNCTION(BlueprintCallable)
    void OnSaveDebugSettings();
    
    UFUNCTION(BlueprintCallable)
    void OnSaveDataSave();
    
    UFUNCTION(BlueprintCallable)
    void OnSaveDataLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnSaveDataDelete();
    
    UFUNCTION(BlueprintCallable)
    void OnResetUserRankingRecord();
    
    UFUNCTION(BlueprintCallable)
    void OnResetShopLineup();
    
    UFUNCTION(BlueprintCallable)
    void OnResetDebugSettings();
    
    UFUNCTION(BlueprintCallable)
    void OnResetCharacterTransform();
    
    UFUNCTION(BlueprintCallable)
    void OnResetCameraValue();
    
    UFUNCTION(BlueprintCallable)
    void OnResetBuffDebuffAllCharacter();
    
    UFUNCTION(BlueprintCallable)
    void OnReplaySaveDataSave();
    
    UFUNCTION(BlueprintCallable)
    void OnReplaySaveDataLoad();
    
    UFUNCTION(BlueprintCallable)
    void OnReplaySaveDataDelete();
    
    UFUNCTION(BlueprintCallable)
    void OnReloadDebugSettings();
    
    UFUNCTION(BlueprintCallable)
    void OnReleaseBgmAll();
    
    UFUNCTION(BlueprintCallable)
    void OnPvEAIReset();
    
    UFUNCTION(BlueprintCallable)
    void OnPassionGaugeZero();
    
    UFUNCTION(BlueprintCallable)
    void OnPassionGaugeMax();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPhaseDebugBoot();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageUser2();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageUser1();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageUI();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageTop();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageSystem();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageStoryRoom();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageStoryDemo();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageStory();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageSoundVoiceTest();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageSoundSeTest();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageSound();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageSequencer();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageScript();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageSaveData();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageRendering2();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageRendering1();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPagePvP();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPagePvEMissionWave();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPagePvEMission();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPagePvEBindingVows();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPagePvEAI();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPagePvE();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPagePerformance();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageNetworkRanking();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageNetworkAging();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageNetwork();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageMap();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageDlc();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageCharacter();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageCamera();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageBattleTest();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageBattle2();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageBattle1();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageAsset();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageArcadeAI();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageArcade();
    
    UFUNCTION(BlueprintCallable)
    void OnOpenPageAI();
    
    UFUNCTION(BlueprintCallable)
    void OnOnlinePenaltyPvPRankMatch();
    
    UFUNCTION(BlueprintCallable)
    void OnOnlinePenaltyPvPFreeMatch();
    
    UFUNCTION(BlueprintCallable)
    void OnOnlinePenaltyPvE();
    
    UFUNCTION(BlueprintCallable)
    void OnMemReport();
    
    UFUNCTION(BlueprintCallable)
    void OnLoadReplay(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnLevelStreamingActorsUpdateTimeLimit(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnGetPvPAllTotalScoreRewards();
    
    UFUNCTION(BlueprintCallable)
    void OnGetAllItems();
    
    UFUNCTION(BlueprintCallable)
    void OnForceUnlockPvEMode();
    
    UFUNCTION(BlueprintCallable)
    void OnForceGaugeOne();
    
    UFUNCTION(BlueprintCallable)
    void OnForceDownAllCharacter();
    
    UFUNCTION(BlueprintCallable)
    void OnDynamicResolution(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnDumpWindows();
    
    UFUNCTION(BlueprintCallable)
    void OnDumpPrimaryAssetDataList();
    
    UFUNCTION(BlueprintCallable)
    void OnDumpLoadedAssetState();
    
    UFUNCTION(BlueprintCallable)
    void OnDumpGPUData();
    
    UFUNCTION(BlueprintCallable)
    void OnDumpCharacterTransform();
    
    UFUNCTION(BlueprintCallable)
    void OnDumpCharacterLog();
    
    UFUNCTION(BlueprintCallable)
    void OnDumpActionCameraParameter();
    
    UFUNCTION(BlueprintCallable)
    void OnDeleteDebugSettings();
    
    UFUNCTION(BlueprintCallable)
    void OnDeleteAllItems();
    
    UFUNCTION(BlueprintCallable)
    void OnDebugNetworkWriteLeaderboard();
    
    UFUNCTION(BlueprintCallable)
    void OnDebugNetworkShowWebURL();
    
    UFUNCTION(BlueprintCallable)
    void OnDebugNetworkShowStoreUI();
    
    UFUNCTION(BlueprintCallable)
    void OnDebugNetworkReadLeaderboard();
    
    UFUNCTION(BlueprintCallable)
    void OnDebugNetworkReadFriendsList();
    
    UFUNCTION(BlueprintCallable)
    void OnDebugNetworkLogout();
    
    UFUNCTION(BlueprintCallable)
    void OnDebugNetworkLogin();
    
    UFUNCTION(BlueprintCallable)
    void OnDebugNetworkLeaderboardType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnCursedEnergyZero();
    
    UFUNCTION(BlueprintCallable)
    void OnCursedEnergyMax();
    
    UFUNCTION(BlueprintCallable)
    void OnCheckPvELotteryIdDefinitions();
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterUniquePossessionEmpty();
    
    UFUNCTION(BlueprintCallable)
    void OnCharacterGather();
    
    UFUNCTION(BlueprintCallable)
    void OnChangeViewMode(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnChangePlayCreditType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnChangeInputGuideType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnChangeFixedLotteryResult(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnAsyncLoadingTimeLimit(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnArcadeAIReset();
    
    UFUNCTION(BlueprintCallable)
    void OnAddBuffDebuffAllCharacter(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void LotteryItemLastOne();
    
    UFUNCTION(BlueprintCallable)
    void GetAllLotteryItem();
    
};


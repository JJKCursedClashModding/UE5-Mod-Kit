#include "DebugMenuWidget.h"

UDebugMenuWidget::UDebugMenuWidget() {
    this->RandomInputKeyCheckBox = NULL;
    this->LoadReplayComboBox = NULL;
    this->AddBuffDebuffComboBox = NULL;
    this->LeaderboardTypeComboBox = NULL;
    this->OnlinePenaltyLevelComboBox = NULL;
    this->OnlinePenaltyLevelDownBattleCountComboBox = NULL;
    this->ArcadeClearFlagComboBox = NULL;
    this->BuildUniqueIdSlider = NULL;
    this->FOVSlider = NULL;
    this->CullingDistanceNearSlider = NULL;
    this->FreeCameraDistanceSlider = NULL;
    this->TargetCameraDistanceSlider = NULL;
    this->TargetCameraActionDistanceSlider = NULL;
    this->ShootCameraDistanceSlider = NULL;
    this->CameraOwnerHeightOffsetSlider = NULL;
    this->CameraTargetHeightOffsetSlider = NULL;
    this->TargetCameraOffsetAngleVSlider = NULL;
    this->TargetCameraBaseAngleHSlider = NULL;
    this->RadialBlurWeightSlider = NULL;
    this->RadialBlurDistSlider = NULL;
    this->RadialBlurPosXSlider = NULL;
    this->RadialBlurPosYSlider = NULL;
    this->RadialBlurRadiusSlider = NULL;
    this->RadialBlurDensitySlider = NULL;
    this->NegaPosiWeightSlider = NULL;
    this->NegaPosiScaleSlider = NULL;
    this->FlareWeightSlider = NULL;
    this->FlarePosXSlider = NULL;
    this->FlarePosYSlider = NULL;
    this->FlareRotateSlider = NULL;
    this->FlareWidthMinSlider = NULL;
    this->FlareWidthMaxSlider = NULL;
    this->ChromaticAberrationWeightSlider = NULL;
    this->ChromaticAberrationScaleSlider = NULL;
    this->GrayScaleWeightSlider = NULL;
    this->GrayScaleScaleSlider = NULL;
    this->GammaValueSlider = NULL;
    this->PaniniDSlider = NULL;
    this->PaniniSSlider = NULL;
    this->PaniniScreenFitSlider = NULL;
    this->ScreenPercentageSlider = NULL;
    this->TAACurrentFrameWeightSlider = NULL;
    this->CameraRotateThresholdSlider = NULL;
    this->CameraTranslateThresholdSlider = NULL;
    this->LeaderboardScoreSlider = NULL;
    this->SkipFrameNumberSlider = NULL;
    this->ExperienceSlider = NULL;
    this->PvPWinCountSlider = NULL;
    this->ExtraMissionPointSlider = NULL;
    this->MoneySlider = NULL;
    this->RankPointSlider = NULL;
    this->RiskValueMaxSlider = NULL;
    this->UserRecordComboBox = NULL;
    this->UserRecordValueSlider = NULL;
    this->UserCharacterRecordIdComboBox = NULL;
    this->UserCharacterRecordValueTypeComboBox = NULL;
    this->UserCharacterRecordValueSlider = NULL;
    this->UserFixedLotteryResultComboBox = NULL;
}

void UDebugMenuWidget::ResetGetLotteryItem() {
}

void UDebugMenuWidget::OnUnlockAllShopLineup() {
}

void UDebugMenuWidget::OnTimeLimitOneSecond() {
}

void UDebugMenuWidget::OnTextureStreamingEnabled(bool bFlag) {
}

void UDebugMenuWidget::OnStoryDemoReleaseReset() {
}

void UDebugMenuWidget::OnStoryDemoReleaseAll() {
}

void UDebugMenuWidget::OnStatUnitGraph() {
}

void UDebugMenuWidget::OnStatUnit() {
}

void UDebugMenuWidget::OnStatSceneRendering() {
}

void UDebugMenuWidget::OnStatSceneMemory() {
}

void UDebugMenuWidget::OnStatRHI() {
}

void UDebugMenuWidget::OnStatMemoryPlatform() {
}

void UDebugMenuWidget::OnStatMemory() {
}

void UDebugMenuWidget::OnStatLevels() {
}

void UDebugMenuWidget::OnStatGame() {
}

void UDebugMenuWidget::OnStatFPS() {
}

void UDebugMenuWidget::OnShowLODInformation(bool bFlag) {
}

void UDebugMenuWidget::OnSetVoiceId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetVoiceDisabled(const bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleWidgetFocusArea(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleWidgetAnimationLog(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleSoundLog(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleScript(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleSafeArea(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleRankingRecord(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleMouseHoverArea(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleMission(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleGrowthStatus(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleGroundInformation(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleEffectWallCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleEffectCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleDestructibleCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleComboCount(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterWallCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterTrail(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterStatus(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterMoveCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterLocation(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterDamageCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterClashingCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterAxis(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterAttackCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleCharacterAction(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagOther(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagNoTransprency(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagGameTransprency(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagGameRoof(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagGameGround(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagGameDestructibleRoof(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagGameBackground(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagDestructible(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionFlagAll(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollisionCheckParentVisibility(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleBackgroundCollision(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleAIThink4P(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleAIThink3P(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleAIThink2P(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleAIThink1P(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleAIMove4P(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleAIMove3P(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleAIMove2P(bool bFlag) {
}

void UDebugMenuWidget::OnSetVisibleAIMove1P(bool bFlag) {
}

void UDebugMenuWidget::OnSetUserRecordValue(float Value) {
}

void UDebugMenuWidget::OnSetUserRecord(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetUserCharacterRecordValueType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetUserCharacterRecordValue(float Value) {
}

void UDebugMenuWidget::OnSetUserCharacterRecordId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetUsePlayableCamera(bool bFlag) {
}

void UDebugMenuWidget::OnSetUpdateSessionInfo(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetUniquePairVoiceForceSecond(bool bFlag) {
}

void UDebugMenuWidget::OnSetUniqueModeIndex(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetTimeLimitStop(bool bFlag) {
}

void UDebugMenuWidget::OnSetTimeDilationRate(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetTensionLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetTensionGaugeFixed(bool bFlag) {
}

void UDebugMenuWidget::OnSetTensionGaugeConsumeDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetTargetCameraOffsetAngleV(float Value) {
}

void UDebugMenuWidget::OnSetTargetCameraDistance(float Value) {
}

void UDebugMenuWidget::OnSetTargetCameraBaseAngleH(float Value) {
}

void UDebugMenuWidget::OnSetTargetCameraActionDistance(float Value) {
}

void UDebugMenuWidget::OnSetTAACurrentFrameWeight(float Value) {
}

void UDebugMenuWidget::OnSetSystemSaveDataLoadEnabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetSymbolChatEnabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetStoryVoiceOverrideIndex(float Value) {
}

void UDebugMenuWidget::OnSetStoryRoomPlacementId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetStepActionTriggerInputEnabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetSpecialAttackUnlimited(bool bFlag) {
}

void UDebugMenuWidget::OnSetSoloSpecialTagCombo(bool bFlag) {
}

void UDebugMenuWidget::OnSetShowUnlockItemName(bool bFlag) {
}

void UDebugMenuWidget::OnSetShowTextId(bool bFlag) {
}

void UDebugMenuWidget::OnSetShowSequencerFrame(bool bFlag) {
}

void UDebugMenuWidget::OnSetShowSequencerBindingLODInfo(bool bFlag) {
}

void UDebugMenuWidget::OnSetShootCameraDistance(float Value) {
}

void UDebugMenuWidget::OnSetSequencerDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetSeId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetSeDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetScreenPercentage(float Value) {
}

void UDebugMenuWidget::OnSetRiskValueMax(float Value) {
}

void UDebugMenuWidget::OnSetResultVoiceOverwhelmingWin(bool bFlag) {
}

void UDebugMenuWidget::OnSetReplaySaveDataIndex(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetReleaseStoryDemoIdChapter09(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetReleaseStoryDemoIdChapter08(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetReleaseStoryDemoId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetRankPoint(float Value) {
}

void UDebugMenuWidget::OnSetRandomInputKey(bool bFlag) {
}

void UDebugMenuWidget::OnSetRadialBlurWeight(float Value) {
}

void UDebugMenuWidget::OnSetRadialBlurRadius(float Value) {
}

void UDebugMenuWidget::OnSetRadialBlurPosY(float Value) {
}

void UDebugMenuWidget::OnSetRadialBlurPosX(float Value) {
}

void UDebugMenuWidget::OnSetRadialBlurDist(float Value) {
}

void UDebugMenuWidget::OnSetRadialBlurDensity(float Value) {
}

void UDebugMenuWidget::OnSetPvPWinCount(float Value) {
}

void UDebugMenuWidget::OnSetPvESurvivalModeMissionNum(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvENormalModeMissionNum(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEMissionWaveId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEMissionId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEMissionBattleLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEBindingVowsId3(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEBindingVowsId2(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEBindingVowsId1(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAllyCharacterId(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIOperation6P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIOperation5P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIOperation4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIOperation3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIOperation2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIMode6P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIMode5P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIMode4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIMode3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAIMode2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAILevel6P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAILevel5P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAILevel4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAILevel3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPvEAILevel2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPostProcessAnimDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetPlatform(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetPhotoMode(bool bFlag) {
}

void UDebugMenuWidget::OnSetPassionGaugeConsumeDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetPaniniScreenFit(float Value) {
}

void UDebugMenuWidget::OnSetPaniniS(float Value) {
}

void UDebugMenuWidget::OnSetPaniniD(float Value) {
}

void UDebugMenuWidget::OnSetPairSequencerFixedValue(float Value) {
}

void UDebugMenuWidget::OnSetOutputSequenceLog(bool bFlag) {
}

void UDebugMenuWidget::OnSetOnlineUserNameHidden(bool bFlag) {
}

void UDebugMenuWidget::OnSetOnlinePenaltyTime(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetOnlinePenaltyLevelDownBattleCount(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetOnlinePenaltyLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetOcclusionCameraTranslateThreshold(float Value) {
}

void UDebugMenuWidget::OnSetOcclusionCameraRotateThreshold(float Value) {
}

void UDebugMenuWidget::OnSetNormalAttackVoicePattern(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNetworkSendWaitFrame(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNetworkInputDelayCount(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNetworkAgingShuffleCharacterIndex(bool bFlag) {
}

void UDebugMenuWidget::OnSetNetworkAgingFixedRandomStreamSeedIndex(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNetworkAgingCharacter4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNetworkAgingCharacter3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNetworkAgingCharacter2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNetworkAgingCharacter1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNetworkAgingBattleLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetNegaPosiWeight(float Value) {
}

void UDebugMenuWidget::OnSetNegaPosiScale(float Value) {
}

void UDebugMenuWidget::OnSetMSAASampleCount(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetMoveSpeedRate(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetMoveCollisionDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetMotionBlurEnabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetMoney(float Value) {
}

void UDebugMenuWidget::OnSetMaterialPattern(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetMatchingRegion(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetLookAtDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetLODSettings(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetInterpolationDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetInputMashEnabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetInputGuidePlatformHidden(bool bFlag) {
}

void UDebugMenuWidget::OnSetHitSlowDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetHitPointOne() {
}

void UDebugMenuWidget::OnSetHitPointMax() {
}

void UDebugMenuWidget::OnSetHISMCHidden(bool bFlag) {
}

void UDebugMenuWidget::OnSetHideStaticMesh(bool bFlag) {
}

void UDebugMenuWidget::OnSetGuardBreakDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetGridHidden(bool bFlag) {
}

void UDebugMenuWidget::OnSetGridHeight(float Value) {
}

void UDebugMenuWidget::OnSetGrayScaleWeight(float Value) {
}

void UDebugMenuWidget::OnSetGrayScaleScale(float Value) {
}

void UDebugMenuWidget::OnSetGammaValue(float Value) {
}

void UDebugMenuWidget::OnSetFreeCameraDistance(float Value) {
}

void UDebugMenuWidget::OnSetFreeCamera(bool bFlag) {
}

void UDebugMenuWidget::OnSetFrameRate(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetFOV(float Value) {
}

void UDebugMenuWidget::OnSetForceNeutralCamera(bool bFlag) {
}

void UDebugMenuWidget::OnSetForceGaugeMax(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetForceGaugeInfinity(bool bFlag) {
}

void UDebugMenuWidget::OnSetForceFeedbackDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetFootIKDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetFlareWidthMin(float Value) {
}

void UDebugMenuWidget::OnSetFlareWidthMax(float Value) {
}

void UDebugMenuWidget::OnSetFlareWeight(float Value) {
}

void UDebugMenuWidget::OnSetFlareRotation(float Value) {
}

void UDebugMenuWidget::OnSetFlarePosY(float Value) {
}

void UDebugMenuWidget::OnSetFlarePosX(float Value) {
}

void UDebugMenuWidget::OnSetFallbackFacialParameter(bool bFlag) {
}

void UDebugMenuWidget::OnSetExtraMissionPoint(float Value) {
}

void UDebugMenuWidget::OnSetExtraMissionOccurs(bool bFlag) {
}

void UDebugMenuWidget::OnSetExperienceZero() {
}

void UDebugMenuWidget::OnSetExperienceMax() {
}

void UDebugMenuWidget::OnSetEffectNotSpawn(bool bFlag) {
}

void UDebugMenuWidget::OnSetEffectHidden(bool bFlag) {
}

void UDebugMenuWidget::OnSetEffectDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetEffectAsyncLoad(bool bFlag) {
}

void UDebugMenuWidget::OnSetDownIKDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDomainExpansionUnlimited(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlcItemCheckEnabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc11Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc10Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc08Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc07Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc05Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc04Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc03Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc02Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDlc01Enabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDisableFocusColor(bool bFlag) {
}

void UDebugMenuWidget::OnSetDisableAutoMouthAnimation(bool bFlag) {
}

void UDebugMenuWidget::OnSetDecalFadeScreenSize(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetDebugReplay(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkTimeOutDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkSkipFrameNumber(float Value) {
}

void UDebugMenuWidget::OnSetDebugNetworkSendInputDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkSameCharacterEnabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkPacket(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkNoOutOfSyncError(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkMockMode(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkMatchingSolo(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkMatchingDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkLogFile(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkLeaderboardScore(float Value) {
}

void UDebugMenuWidget::OnSetDebugNetworkLANMatch(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkHighDelayMode(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkForceMatchingHost(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkForceError(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkForceBlockedUser(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugNetworkDisplayLog(bool bFlag) {
}

void UDebugMenuWidget::OnSetDebugCamera(bool bFlag) {
}

void UDebugMenuWidget::OnSetDashGaugeInfinity(bool bFlag) {
}

void UDebugMenuWidget::OnSetDamageCollisionDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetCursedEnergyLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetCursedEnergyFixed(bool bFlag) {
}

void UDebugMenuWidget::OnSetCursedEnergyConsumeDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetCursedEnergyAttackVoicePattern(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetCullingDistanceNear(float Value) {
}

void UDebugMenuWidget::OnSetChromaticAberrationWeight(float Value) {
}

void UDebugMenuWidget::OnSetChromaticAberrationScale(float Value) {
}

void UDebugMenuWidget::OnSetCharacterUniquePossessionConsumeDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetCharacterMeshHidden(bool bFlag) {
}

void UDebugMenuWidget::OnSetCharacterInvincible(bool bFlag) {
}

void UDebugMenuWidget::OnSetCharacterInstantDeath(bool bFlag) {
}

void UDebugMenuWidget::OnSetChangeOnlineUserNameDummy(bool bFlag) {
}

void UDebugMenuWidget::OnSetCameraTargetHeightOffset(float Value) {
}

void UDebugMenuWidget::OnSetCameraShakeDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetCameraOwnerHeightOffset(float Value) {
}

void UDebugMenuWidget::OnSetBuildUniqueId(float Value) {
}

void UDebugMenuWidget::OnSetBgmDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagTimeLimit(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagTargetCursor(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagTagComboHitWidget(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagTagComboChanceWidget(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagSymbolChat(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagStartWidget(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagSpecialAttackIcon(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagRivalTeamForceGauge(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagRadar(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagPlayerTeamForceGauge(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagPlayerInfo(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagOverlay(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagOperation(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagObjectDirection(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagNotifyWidget(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagMissionInfo(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagMarker(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagLockonAlert(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagHUD(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagHPGauge(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagFinishWidget(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagDomainExpansionGauge(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagDeadEffect(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagDashGauge(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagCutInWidget(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagCursedEnergyGauge(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagAll(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleWidgetShowFlagAlert(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleTestPair(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestCostumeIndex4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestCostumeIndex3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestCostumeIndex2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestCostumeIndex1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestColorIndex4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestColorIndex3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestColorIndex2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestColorIndex1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestCharacter4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestCharacter3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestCharacter2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestCharacter1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestBrain1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestAIMode4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestAIMode3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattleTestAIMode2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetBattlePhotoMode(bool bFlag) {
}

void UDebugMenuWidget::OnSetBattleLevel(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAspectRatioType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeMissionIndex(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeClearFlag(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAIOperation4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAIOperation3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAIOperation2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAIMode4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAIMode3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAIMode2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAILevel4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAILevel3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetArcadeAILevel2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAlwaysSpecialActionSuccess(bool bFlag) {
}

void UDebugMenuWidget::OnSetAlwaysNormalDamage(bool bFlag) {
}

void UDebugMenuWidget::OnSetAlwaysLinkComboSuccess(bool bFlag) {
}

void UDebugMenuWidget::OnSetAlwaysJustGuard(bool bFlag) {
}

void UDebugMenuWidget::OnSetAlwaysEmptyCursedEnergyAutoCombo(bool bFlag) {
}

void UDebugMenuWidget::OnSetAlwaysDestruct(bool bFlag) {
}

void UDebugMenuWidget::OnSetAllCharacterLevelMax() {
}

void UDebugMenuWidget::OnSetAIOperation4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAIOperation3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAIOperation2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAIOperation1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAILevel4P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAILevel3P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAILevel2P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAILevel1P(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAIDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetActionCameraNumber(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetActionCameraDisabled(bool bFlag) {
}

void UDebugMenuWidget::OnSetAchievements(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSetAAMethod(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSelectPvEResultEvaluation(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSelectDebugNetworkOverrideStatusCode(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSelectDebugNetworkMockModePlayableCharacterIndex(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSelectDebugMenuLanguage(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnSaveReplay() {
}

void UDebugMenuWidget::OnSaveDebugSettings() {
}

void UDebugMenuWidget::OnSaveDataSave() {
}

void UDebugMenuWidget::OnSaveDataLoad() {
}

void UDebugMenuWidget::OnSaveDataDelete() {
}

void UDebugMenuWidget::OnResetUserRankingRecord() {
}

void UDebugMenuWidget::OnResetShopLineup() {
}

void UDebugMenuWidget::OnResetDebugSettings() {
}

void UDebugMenuWidget::OnResetCharacterTransform() {
}

void UDebugMenuWidget::OnResetCameraValue() {
}

void UDebugMenuWidget::OnResetBuffDebuffAllCharacter() {
}

void UDebugMenuWidget::OnReplaySaveDataSave() {
}

void UDebugMenuWidget::OnReplaySaveDataLoad() {
}

void UDebugMenuWidget::OnReplaySaveDataDelete() {
}

void UDebugMenuWidget::OnReloadDebugSettings() {
}

void UDebugMenuWidget::OnReleaseBgmAll() {
}

void UDebugMenuWidget::OnPvEAIReset() {
}

void UDebugMenuWidget::OnPassionGaugeZero() {
}

void UDebugMenuWidget::OnPassionGaugeMax() {
}

void UDebugMenuWidget::OnOpenPhaseDebugBoot() {
}

void UDebugMenuWidget::OnOpenPageUser2() {
}

void UDebugMenuWidget::OnOpenPageUser1() {
}

void UDebugMenuWidget::OnOpenPageUI() {
}

void UDebugMenuWidget::OnOpenPageTop() {
}

void UDebugMenuWidget::OnOpenPageSystem() {
}

void UDebugMenuWidget::OnOpenPageStoryRoom() {
}

void UDebugMenuWidget::OnOpenPageStoryDemo() {
}

void UDebugMenuWidget::OnOpenPageStory() {
}

void UDebugMenuWidget::OnOpenPageSoundVoiceTest() {
}

void UDebugMenuWidget::OnOpenPageSoundSeTest() {
}

void UDebugMenuWidget::OnOpenPageSound() {
}

void UDebugMenuWidget::OnOpenPageSequencer() {
}

void UDebugMenuWidget::OnOpenPageScript() {
}

void UDebugMenuWidget::OnOpenPageSaveData() {
}

void UDebugMenuWidget::OnOpenPageRendering2() {
}

void UDebugMenuWidget::OnOpenPageRendering1() {
}

void UDebugMenuWidget::OnOpenPagePvP() {
}

void UDebugMenuWidget::OnOpenPagePvEMissionWave() {
}

void UDebugMenuWidget::OnOpenPagePvEMission() {
}

void UDebugMenuWidget::OnOpenPagePvEBindingVows() {
}

void UDebugMenuWidget::OnOpenPagePvEAI() {
}

void UDebugMenuWidget::OnOpenPagePvE() {
}

void UDebugMenuWidget::OnOpenPagePerformance() {
}

void UDebugMenuWidget::OnOpenPageNetworkRanking() {
}

void UDebugMenuWidget::OnOpenPageNetworkAging() {
}

void UDebugMenuWidget::OnOpenPageNetwork() {
}

void UDebugMenuWidget::OnOpenPageMap() {
}

void UDebugMenuWidget::OnOpenPageDlc() {
}

void UDebugMenuWidget::OnOpenPageCharacter() {
}

void UDebugMenuWidget::OnOpenPageCamera() {
}

void UDebugMenuWidget::OnOpenPageBattleTest() {
}

void UDebugMenuWidget::OnOpenPageBattle2() {
}

void UDebugMenuWidget::OnOpenPageBattle1() {
}

void UDebugMenuWidget::OnOpenPageAsset() {
}

void UDebugMenuWidget::OnOpenPageArcadeAI() {
}

void UDebugMenuWidget::OnOpenPageArcade() {
}

void UDebugMenuWidget::OnOpenPageAI() {
}

void UDebugMenuWidget::OnOnlinePenaltyPvPRankMatch() {
}

void UDebugMenuWidget::OnOnlinePenaltyPvPFreeMatch() {
}

void UDebugMenuWidget::OnOnlinePenaltyPvE() {
}

void UDebugMenuWidget::OnMemReport() {
}

void UDebugMenuWidget::OnLoadReplay(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnLevelStreamingActorsUpdateTimeLimit(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnGetPvPAllTotalScoreRewards() {
}

void UDebugMenuWidget::OnGetAllItems() {
}

void UDebugMenuWidget::OnForceUnlockPvEMode() {
}

void UDebugMenuWidget::OnForceGaugeOne() {
}

void UDebugMenuWidget::OnForceDownAllCharacter() {
}

void UDebugMenuWidget::OnDynamicResolution(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnDumpWindows() {
}

void UDebugMenuWidget::OnDumpPrimaryAssetDataList() {
}

void UDebugMenuWidget::OnDumpLoadedAssetState() {
}

void UDebugMenuWidget::OnDumpGPUData() {
}

void UDebugMenuWidget::OnDumpCharacterTransform() {
}

void UDebugMenuWidget::OnDumpCharacterLog() {
}

void UDebugMenuWidget::OnDumpActionCameraParameter() {
}

void UDebugMenuWidget::OnDeleteDebugSettings() {
}

void UDebugMenuWidget::OnDeleteAllItems() {
}

void UDebugMenuWidget::OnDebugNetworkWriteLeaderboard() {
}

void UDebugMenuWidget::OnDebugNetworkShowWebURL() {
}

void UDebugMenuWidget::OnDebugNetworkShowStoreUI() {
}

void UDebugMenuWidget::OnDebugNetworkReadLeaderboard() {
}

void UDebugMenuWidget::OnDebugNetworkReadFriendsList() {
}

void UDebugMenuWidget::OnDebugNetworkLogout() {
}

void UDebugMenuWidget::OnDebugNetworkLogin() {
}

void UDebugMenuWidget::OnDebugNetworkLeaderboardType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnCursedEnergyZero() {
}

void UDebugMenuWidget::OnCursedEnergyMax() {
}

void UDebugMenuWidget::OnCheckPvELotteryIdDefinitions() {
}

void UDebugMenuWidget::OnCharacterUniquePossessionEmpty() {
}

void UDebugMenuWidget::OnCharacterGather() {
}

void UDebugMenuWidget::OnChangeViewMode(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnChangePlayCreditType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnChangeInputGuideType(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnChangeFixedLotteryResult(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnAsyncLoadingTimeLimit(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::OnArcadeAIReset() {
}

void UDebugMenuWidget::OnAddBuffDebuffAllCharacter(const FString& SelectedItem, TEnumAsByte<ESelectInfo::Type> SelectionType) {
}

void UDebugMenuWidget::LotteryItemLastOne() {
}

void UDebugMenuWidget::GetAllLotteryItem() {
}



#include "GameOnlineBeaconClient.h"

AGameOnlineBeaconClient::AGameOnlineBeaconClient(const FObjectInitializer& ObjectInitializer) : Super(ObjectInitializer) {
}

void AGameOnlineBeaconClient::ServerUnreliableSendInput_Implementation(const TArray<FGameOnlineServerInput>& InPacket) {
}
bool AGameOnlineBeaconClient::ServerUnreliableSendInput_Validate(const TArray<FGameOnlineServerInput>& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerStartPvEInterval_Implementation(const FGameOnlinePvEIntervalStart& InPvEIntervalStart) {
}
bool AGameOnlineBeaconClient::ServerStartPvEInterval_Validate(const FGameOnlinePvEIntervalStart& InPvEIntervalStart) {
    return true;
}

void AGameOnlineBeaconClient::ServerStartCharacterSelect_Implementation() {
}

void AGameOnlineBeaconClient::ServerSendUserSettings_Implementation(const FGameOnlineUserBattleSettings& InPacket) {
}
bool AGameOnlineBeaconClient::ServerSendUserSettings_Validate(const FGameOnlineUserBattleSettings& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendSyncWait_Implementation() {
}

void AGameOnlineBeaconClient::ServerSendSkipAppearance_Implementation() {
}

void AGameOnlineBeaconClient::ServerSendRestartVisualLobby_Implementation() {
}

void AGameOnlineBeaconClient::ServerSendRequestResumeSyncInput_Implementation() {
}

void AGameOnlineBeaconClient::ServerSendRequestRestartVisualLobby_Implementation(const FGameOnlineRestartVisualLobbyMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ServerSendRequestRestartVisualLobby_Validate(const FGameOnlineRestartVisualLobbyMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendRequestRematch_Implementation(const EGameOnlineRematchType InRequestRematch) {
}
bool AGameOnlineBeaconClient::ServerSendRequestRematch_Validate(const EGameOnlineRematchType InRequestRematch) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendReadyMessage_Implementation(const FGameOnlineReadyMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ServerSendReadyMessage_Validate(const FGameOnlineReadyMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendPvEIntervalAction_Implementation(const FGameOnlinePvEIntervalAction& InPvEIntervalAction) {
}
bool AGameOnlineBeaconClient::ServerSendPvEIntervalAction_Validate(const FGameOnlinePvEIntervalAction& InPvEIntervalAction) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendPvEBindingVows_Implementation(const FGameOnlinePvEBindingVows& InPvEBindingVows) {
}
bool AGameOnlineBeaconClient::ServerSendPvEBindingVows_Validate(const FGameOnlinePvEBindingVows& InPvEBindingVows) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendPong_Implementation(const FDateTime& InSendPingTime) {
}
bool AGameOnlineBeaconClient::ServerSendPong_Validate(const FDateTime& InSendPingTime) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendMessage_Implementation(const TArray<FString>& InSendUserIdArray, const FGameOnlineSendMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ServerSendMessage_Validate(const TArray<FString>& InSendUserIdArray, const FGameOnlineSendMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendCharacterSelecting_Implementation(const FGameOnlineCharacterSelectingMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ServerSendCharacterSelecting_Validate(const FGameOnlineCharacterSelectingMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendCharacterSelect_Implementation(const FGameOnlineCharacterSelect& InPacket) {
}
bool AGameOnlineBeaconClient::ServerSendCharacterSelect_Validate(const FGameOnlineCharacterSelect& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerSendAgreeBattle_Implementation(const bool bInAgree) {
}
bool AGameOnlineBeaconClient::ServerSendAgreeBattle_Validate(const bool bInAgree) {
    return true;
}

void AGameOnlineBeaconClient::ServerReliableSendInput_Implementation(const TArray<FGameOnlineServerInput>& InPacket) {
}
bool AGameOnlineBeaconClient::ServerReliableSendInput_Validate(const TArray<FGameOnlineServerInput>& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerFirstMessage_Implementation(const FGameOnlineFirstMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ServerFirstMessage_Validate(const FGameOnlineFirstMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ServerConnectedMessage_Implementation(const FGameOnlineConnectedMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ServerConnectedMessage_Validate(const FGameOnlineConnectedMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientUpdatePvEIntervalStatus_Implementation(const FGameOnlinePvEIntervalStatus& InPvEIntervalStatus) {
}
bool AGameOnlineBeaconClient::ClientUpdatePvEIntervalStatus_Validate(const FGameOnlinePvEIntervalStatus& InPvEIntervalStatus) {
    return true;
}

void AGameOnlineBeaconClient::ClientUnreliableSendedInput_Implementation(const int32 InFrameNumber) {
}
bool AGameOnlineBeaconClient::ClientUnreliableSendedInput_Validate(const int32 InFrameNumber) {
    return true;
}

void AGameOnlineBeaconClient::ClientUnreliableReceiveInput_Implementation(const FGameOnlineClientInput& InPacket) {
}
bool AGameOnlineBeaconClient::ClientUnreliableReceiveInput_Validate(const FGameOnlineClientInput& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientSetCharacterSelectSettings_Implementation(const FGameOnlineCharacterSelectSettings& InCharacterSelectSettings) {
}
bool AGameOnlineBeaconClient::ClientSetCharacterSelectSettings_Validate(const FGameOnlineCharacterSelectSettings& InCharacterSelectSettings) {
    return true;
}

void AGameOnlineBeaconClient::ClientSetCharacterSelect_Implementation(const EGameCharacterIndex InCharacterIndex, const FGameOnlineCharacterSelect& InOnlineCharacterSelect) {
}
bool AGameOnlineBeaconClient::ClientSetCharacterSelect_Validate(const EGameCharacterIndex InCharacterIndex, const FGameOnlineCharacterSelect& InOnlineCharacterSelect) {
    return true;
}

void AGameOnlineBeaconClient::ClientSendPing_Implementation(const FGameOnlinePingMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ClientSendPing_Validate(const FGameOnlinePingMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientResumeSyncInput_Implementation() {
}

void AGameOnlineBeaconClient::ClientReliableSendedInput_Implementation(const int32 InFrameNumber) {
}
bool AGameOnlineBeaconClient::ClientReliableSendedInput_Validate(const int32 InFrameNumber) {
    return true;
}

void AGameOnlineBeaconClient::ClientReliableReceiveInput_Implementation(const FGameOnlineClientInput& InPacket) {
}
bool AGameOnlineBeaconClient::ClientReliableReceiveInput_Validate(const FGameOnlineClientInput& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientReceiveVisualLobbySettings_Implementation(const EGameCharacterIndex InCharacterIndex, const FGameOnlineVisualLobbySettings& InPacket, const bool bDisconnectedUser) {
}
bool AGameOnlineBeaconClient::ClientReceiveVisualLobbySettings_Validate(const EGameCharacterIndex InCharacterIndex, const FGameOnlineVisualLobbySettings& InPacket, const bool bDisconnectedUser) {
    return true;
}

void AGameOnlineBeaconClient::ClientReceiveVisualLobbyNextGameMode_Implementation(const FGameOnlineVisualLobbyNextGameMode& InPacket) {
}
bool AGameOnlineBeaconClient::ClientReceiveVisualLobbyNextGameMode_Validate(const FGameOnlineVisualLobbyNextGameMode& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientReceiveSyncWait_Implementation() {
}

void AGameOnlineBeaconClient::ClientReceiveRestartVisualLobby_Implementation() {
}

void AGameOnlineBeaconClient::ClientReceiveRequestReturnVisualLobby_Implementation() {
}

void AGameOnlineBeaconClient::ClientReceiveRequestRestartVisualLobby_Implementation(const FGameOnlineRestartVisualLobbyMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ClientReceiveRequestRestartVisualLobby_Validate(const FGameOnlineRestartVisualLobbyMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientReceiveRequestRematchResult_Implementation(const FGameOnlineRequestRematchResultMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ClientReceiveRequestRematchResult_Validate(const FGameOnlineRequestRematchResultMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientReceivePvEIntervalResult_Implementation(const FGameOnlinePvEIntervalResult& InPvEIntervalResult) {
}
bool AGameOnlineBeaconClient::ClientReceivePvEIntervalResult_Validate(const FGameOnlinePvEIntervalResult& InPvEIntervalResult) {
    return true;
}

void AGameOnlineBeaconClient::ClientReceivePvEIntervalAction_Implementation(const FGameOnlinePvEIntervalAction& InPvEIntervalAction) {
}
bool AGameOnlineBeaconClient::ClientReceivePvEIntervalAction_Validate(const FGameOnlinePvEIntervalAction& InPvEIntervalAction) {
    return true;
}

void AGameOnlineBeaconClient::ClientReceiveMessage_Implementation(const FString& InSenderUserId, const EGameCharacterIndex InCharacterIndex, const FGameOnlineSendMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ClientReceiveMessage_Validate(const FString& InSenderUserId, const EGameCharacterIndex InCharacterIndex, const FGameOnlineSendMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientReceiveDisagreeBattle_Implementation() {
}

void AGameOnlineBeaconClient::ClientReceiveCharacterSelecting_Implementation(const EGameCharacterIndex InCharacterIndex, const FGameOnlineCharacterSelectingMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ClientReceiveCharacterSelecting_Validate(const EGameCharacterIndex InCharacterIndex, const FGameOnlineCharacterSelectingMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientOtherClientDisconnected_Implementation(const EGameCharacterIndex InCharacterIndex, const FGameOnlineUserInfo& InUserInfo) {
}
bool AGameOnlineBeaconClient::ClientOtherClientDisconnected_Validate(const EGameCharacterIndex InCharacterIndex, const FGameOnlineUserInfo& InUserInfo) {
    return true;
}

void AGameOnlineBeaconClient::ClientOtherClientConnected_Implementation(const FGameOnlineUserInfo& InUserInfo) {
}
bool AGameOnlineBeaconClient::ClientOtherClientConnected_Validate(const FGameOnlineUserInfo& InUserInfo) {
    return true;
}

void AGameOnlineBeaconClient::ClientFirstMessage_Implementation(const FGameOnlineReturnFirstMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ClientFirstMessage_Validate(const FGameOnlineReturnFirstMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientEveryoneReadyMessage_Implementation(const FGameOnlineEveryoneReadyMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ClientEveryoneReadyMessage_Validate(const FGameOnlineEveryoneReadyMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientConnectedMessage_Implementation(const FGameOnlineConnectedReturnMessage& InPacket) {
}
bool AGameOnlineBeaconClient::ClientConnectedMessage_Validate(const FGameOnlineConnectedReturnMessage& InPacket) {
    return true;
}

void AGameOnlineBeaconClient::ClientBattleSettings_Implementation(const FGameOnlineBattleSettings& InPacket) {
}
bool AGameOnlineBeaconClient::ClientBattleSettings_Validate(const FGameOnlineBattleSettings& InPacket) {
    return true;
}

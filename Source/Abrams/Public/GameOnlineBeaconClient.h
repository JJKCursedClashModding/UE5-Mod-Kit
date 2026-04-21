#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "OnlineBeaconClient.h"
#include "EGameCharacterIndex.h"
#include "EGameOnlineRematchType.h"
#include "GameOnlineBattleSettings.h"
#include "GameOnlineBeaconInterface.h"
#include "GameOnlineCharacterSelect.h"
#include "GameOnlineCharacterSelectSettings.h"
#include "GameOnlineCharacterSelectingMessage.h"
#include "GameOnlineClientInput.h"
#include "GameOnlineConnectedMessage.h"
#include "GameOnlineConnectedReturnMessage.h"
#include "GameOnlineEveryoneReadyMessage.h"
#include "GameOnlineFirstMessage.h"
#include "GameOnlinePingMessage.h"
#include "GameOnlinePvEBindingVows.h"
#include "GameOnlinePvEIntervalAction.h"
#include "GameOnlinePvEIntervalResult.h"
#include "GameOnlinePvEIntervalStart.h"
#include "GameOnlinePvEIntervalStatus.h"
#include "GameOnlineReadyMessage.h"
#include "GameOnlineRequestRematchResultMessage.h"
#include "GameOnlineRestartVisualLobbyMessage.h"
#include "GameOnlineReturnFirstMessage.h"
#include "GameOnlineSendMessage.h"
#include "GameOnlineServerInput.h"
#include "GameOnlineUserBattleSettings.h"
#include "GameOnlineUserInfo.h"
#include "GameOnlineVisualLobbyNextGameMode.h"
#include "GameOnlineVisualLobbySettings.h"
#include "GameOnlineBeaconClient.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API AGameOnlineBeaconClient : public AOnlineBeaconClient, public IGameOnlineBeaconInterface {
    GENERATED_BODY()
public:
    AGameOnlineBeaconClient(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable, Server, Unreliable, WithValidation)
    void ServerUnreliableSendInput(const TArray<FGameOnlineServerInput>& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerStartPvEInterval(const FGameOnlinePvEIntervalStart& InPvEIntervalStart);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerStartCharacterSelect();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendUserSettings(const FGameOnlineUserBattleSettings& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSendSyncWait();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSendSkipAppearance();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSendRestartVisualLobby();
    
    UFUNCTION(BlueprintCallable, Reliable, Server)
    void ServerSendRequestResumeSyncInput();
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendRequestRestartVisualLobby(const FGameOnlineRestartVisualLobbyMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendRequestRematch(const EGameOnlineRematchType InRequestRematch);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendReadyMessage(const FGameOnlineReadyMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendPvEIntervalAction(const FGameOnlinePvEIntervalAction& InPvEIntervalAction);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendPvEBindingVows(const FGameOnlinePvEBindingVows& InPvEBindingVows);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendPong(const FDateTime& InSendPingTime);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendMessage(const TArray<FString>& InSendUserIdArray, const FGameOnlineSendMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendCharacterSelecting(const FGameOnlineCharacterSelectingMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendCharacterSelect(const FGameOnlineCharacterSelect& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerSendAgreeBattle(const bool bInAgree);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerReliableSendInput(const TArray<FGameOnlineServerInput>& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerFirstMessage(const FGameOnlineFirstMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Reliable, Server, WithValidation)
    void ServerConnectedMessage(const FGameOnlineConnectedMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientUpdatePvEIntervalStatus(const FGameOnlinePvEIntervalStatus& InPvEIntervalStatus);
    
    UFUNCTION(BlueprintCallable, Client, Unreliable, WithValidation)
    void ClientUnreliableSendedInput(const int32 InFrameNumber);
    
    UFUNCTION(BlueprintCallable, Client, Unreliable, WithValidation)
    void ClientUnreliableReceiveInput(const FGameOnlineClientInput& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientSetCharacterSelectSettings(const FGameOnlineCharacterSelectSettings& InCharacterSelectSettings);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientSetCharacterSelect(const EGameCharacterIndex InCharacterIndex, const FGameOnlineCharacterSelect& InOnlineCharacterSelect);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientSendPing(const FGameOnlinePingMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientResumeSyncInput();
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReliableSendedInput(const int32 InFrameNumber);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReliableReceiveInput(const FGameOnlineClientInput& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReceiveVisualLobbySettings(const EGameCharacterIndex InCharacterIndex, const FGameOnlineVisualLobbySettings& InPacket, const bool bDisconnectedUser);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReceiveVisualLobbyNextGameMode(const FGameOnlineVisualLobbyNextGameMode& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientReceiveSyncWait();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientReceiveRestartVisualLobby();
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientReceiveRequestReturnVisualLobby();
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReceiveRequestRestartVisualLobby(const FGameOnlineRestartVisualLobbyMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReceiveRequestRematchResult(const FGameOnlineRequestRematchResultMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReceivePvEIntervalResult(const FGameOnlinePvEIntervalResult& InPvEIntervalResult);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReceivePvEIntervalAction(const FGameOnlinePvEIntervalAction& InPvEIntervalAction);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReceiveMessage(const FString& InSenderUserId, const EGameCharacterIndex InCharacterIndex, const FGameOnlineSendMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable)
    void ClientReceiveDisagreeBattle();
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientReceiveCharacterSelecting(const EGameCharacterIndex InCharacterIndex, const FGameOnlineCharacterSelectingMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientOtherClientDisconnected(const EGameCharacterIndex InCharacterIndex, const FGameOnlineUserInfo& InUserInfo);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientOtherClientConnected(const FGameOnlineUserInfo& InUserInfo);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientFirstMessage(const FGameOnlineReturnFirstMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientEveryoneReadyMessage(const FGameOnlineEveryoneReadyMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientConnectedMessage(const FGameOnlineConnectedReturnMessage& InPacket);
    
    UFUNCTION(BlueprintCallable, Client, Reliable, WithValidation)
    void ClientBattleSettings(const FGameOnlineBattleSettings& InPacket);
    

    // Fix for true pure virtual functions not being implemented
};


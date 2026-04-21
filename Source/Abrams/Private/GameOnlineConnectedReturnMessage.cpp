#include "GameOnlineConnectedReturnMessage.h"

FGameOnlineConnectedReturnMessage::FGameOnlineConnectedReturnMessage() {
    this->ConnectStatus = EGameOnlineConnectStatus::Disconnect;
    this->StatusCode = EGameOnlineStatusCode::Processing;
    this->BeaconId = 0;
}


#include "GameOnlineKpi.h"

UGameOnlineKpi::UGameOnlineKpi() {
    this->WebApiConnect = NULL;
}

void UGameOnlineKpi::OnReceive(ECosmosApiId ApiId, int32 Status, const TArray<uint8>& Data) {
}



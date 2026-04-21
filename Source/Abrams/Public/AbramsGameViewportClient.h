#pragma once
#include "CoreMinimal.h"
#include "Engine/GameViewportClient.h"
#include "AbramsGameViewportClient.generated.h"

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UAbramsGameViewportClient : public UGameViewportClient {
    GENERATED_BODY()
public:
    UAbramsGameViewportClient();

};


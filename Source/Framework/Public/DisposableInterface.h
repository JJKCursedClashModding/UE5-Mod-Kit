#pragma once
#include "CoreMinimal.h"
#include "UObject/Interface.h"
#include "DisposableInterface.generated.h"

UINTERFACE(MinimalAPI)
class UDisposableInterface : public UInterface {
    GENERATED_BODY()
};

class IDisposableInterface : public IInterface {
    GENERATED_BODY()
public:
};


#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ECosmosApiId.h"
#include "GameOnlineKpi.generated.h"

class UWebApiConnect;

UCLASS(Blueprintable)
class ABRAMS_API UGameOnlineKpi : public UObject {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UWebApiConnect* WebApiConnect;
    
public:
    UGameOnlineKpi();

protected:
    UFUNCTION(BlueprintCallable)
    void OnReceive(ECosmosApiId ApiId, int32 Status, const TArray<uint8>& Data);
    
};


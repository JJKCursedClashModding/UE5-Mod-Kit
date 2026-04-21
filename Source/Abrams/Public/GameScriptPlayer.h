#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameScriptPlayer.generated.h"

class UGameScriptData;
class UGameScriptParameter;

UCLASS(Blueprintable)
class ABRAMS_API UGameScriptPlayer : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameScriptData* ScriptData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameScriptParameter* ScriptParameter;
    
public:
    UGameScriptPlayer();

};


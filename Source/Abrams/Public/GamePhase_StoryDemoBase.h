#pragma once
#include "CoreMinimal.h"
#include "GamePhase.h"
#include "GamePhase_StoryDemoBase.generated.h"

class UGameScriptPlayer;

UCLASS(Abstract, Blueprintable)
class ABRAMS_API UGamePhase_StoryDemoBase : public UGamePhase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameScriptPlayer* ScriptPlayer;
    
public:
    UGamePhase_StoryDemoBase();

};


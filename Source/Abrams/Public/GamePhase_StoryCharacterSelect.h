#pragma once
#include "CoreMinimal.h"
#include "GamePhase.h"
#include "GamePhase_StoryCharacterSelect.generated.h"

class AGameCharacterCaptureActor;

UCLASS(Blueprintable)
class ABRAMS_API UGamePhase_StoryCharacterSelect : public UGamePhase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameCharacterCaptureActor* CharacterSelectCaptureActor;
    
public:
    UGamePhase_StoryCharacterSelect();

};


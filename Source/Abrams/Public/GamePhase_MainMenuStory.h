#pragma once
#include "CoreMinimal.h"
#include "GamePhase_MainMenuBase.h"
#include "GamePhase_MainMenuStory.generated.h"

class AGameCharacter;

UCLASS(Blueprintable)
class ABRAMS_API UGamePhase_MainMenuStory : public UGamePhase_MainMenuBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGameCharacter*> CharacterArray;
    
public:
    UGamePhase_MainMenuStory();

};


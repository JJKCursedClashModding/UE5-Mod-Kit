#pragma once
#include "CoreMinimal.h"
#include "GameBoxComponent.h"
#include "GameBoxComponent_BattleAreaCharacter.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameBoxComponent_BattleAreaCharacter : public UGameBoxComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTouchedEffectEnabled;
    
    UGameBoxComponent_BattleAreaCharacter(const FObjectInitializer& ObjectInitializer);

};


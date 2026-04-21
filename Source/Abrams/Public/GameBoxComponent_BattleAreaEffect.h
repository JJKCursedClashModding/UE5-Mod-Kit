#pragma once
#include "CoreMinimal.h"
#include "GameBoxComponent.h"
#include "GameBoxComponent_BattleAreaEffect.generated.h"

UCLASS(Blueprintable, EditInlineNew, ClassGroup=Custom, meta=(BlueprintSpawnableComponent))
class ABRAMS_API UGameBoxComponent_BattleAreaEffect : public UGameBoxComponent {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bTrapHitEnabled;
    
    UGameBoxComponent_BattleAreaEffect(const FObjectInitializer& ObjectInitializer);

};


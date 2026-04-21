#pragma once
#include "CoreMinimal.h"
#include "GameBattleFinishWidget.h"
#include "GameBattleFinishNormalWidget.generated.h"

class UOverlay;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleFinishNormalWidget : public UGameBattleFinishWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* Subtext_Group;
    
public:
    UGameBattleFinishNormalWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleAlertWidget.generated.h"

class UGameBattleLockonAlertWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleAlertWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleLockonAlertWidget* LockonAlert;
    
public:
    UGameBattleAlertWidget();


    // Fix for true pure virtual functions not being implemented
};


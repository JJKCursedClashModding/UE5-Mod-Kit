#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattlePracticeTaskListWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattlePracticeTaskListWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D TaskOffset;
    
public:
    UGameBattlePracticeTaskListWidget();


    // Fix for true pure virtual functions not being implemented
};


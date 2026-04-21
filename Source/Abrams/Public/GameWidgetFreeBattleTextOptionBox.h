#pragma once
#include "CoreMinimal.h"
#include "GameWidgetTextOptionBox.h"
#include "GameWidgetFreeBattleTextOptionBox.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetFreeBattleTextOptionBox : public UGameWidgetTextOptionBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* FocusImage;
    
public:
    UGameWidgetFreeBattleTextOptionBox();

};


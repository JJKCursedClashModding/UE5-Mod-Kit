#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameWidgetTabWindow.generated.h"

class UGameWidgetButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetTabWindow : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* PreviousListButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* NextListButton;
    
public:
    UGameWidgetTabWindow();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameWidgetScrollBoxWrapper.generated.h"

class UGameWidgetScrollBox;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetScrollBoxWrapper : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetScrollBox* ScrollBox;
    
public:
    UGameWidgetScrollBoxWrapper();

};


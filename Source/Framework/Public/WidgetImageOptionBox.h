#pragma once
#include "CoreMinimal.h"
#include "WidgetOptionBoxBase.h"
#include "WidgetImageOptionBox.generated.h"

class UImage;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetImageOptionBox : public UWidgetOptionBoxBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* Image;
    
public:
    UWidgetImageOptionBox();

};


#pragma once
#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "InputWidgetBase.h"
#include "WidgetEnterable.h"
#include "WidgetOptionBoxBase.generated.h"

class UWidgetButton;
class UWidgetOptionBoxItem;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class FRAMEWORK_API UWidgetOptionBoxBase : public UInputWidgetBase, public IWidgetEnterable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetButton* RightButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UWidgetButton* LeftButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TEnumAsByte<EOrientation> Orientation;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLoopOptions;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bLockFocus;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UWidgetOptionBoxItem*> Options;
    
public:
    UWidgetOptionBoxBase();


    // Fix for true pure virtual functions not being implemented
};


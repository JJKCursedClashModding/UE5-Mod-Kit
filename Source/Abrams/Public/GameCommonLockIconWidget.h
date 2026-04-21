#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCommonLockIconWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCommonLockIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LockIcon;
    
public:
    UGameCommonLockIconWidget();

};


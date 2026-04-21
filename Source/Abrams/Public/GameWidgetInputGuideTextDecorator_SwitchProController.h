#pragma once
#include "CoreMinimal.h"
#include "GameWidgetInputGuideTextDecorator.h"
#include "GameWidgetInputGuideTextDecorator_SwitchProController.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetInputGuideTextDecorator_SwitchProController : public UGameWidgetInputGuideTextDecorator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CustomImageSet;
    
public:
    UGameWidgetInputGuideTextDecorator_SwitchProController();

};


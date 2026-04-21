#pragma once
#include "CoreMinimal.h"
#include "GameWidgetInputGuideTextDecorator.h"
#include "GameWidgetInputGuideTextDecorator_DualSense.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetInputGuideTextDecorator_DualSense : public UGameWidgetInputGuideTextDecorator {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CustomImageSet;
    
public:
    UGameWidgetInputGuideTextDecorator_DualSense();

};


#pragma once
#include "CoreMinimal.h"
#include "WidgetWorldTickable.h"
#include "GameWidgetRetainerBox.h"
#include "GameWidgetDynamicMaterialRetainerBox.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetDynamicMaterialRetainerBox : public UGameWidgetRetainerBox, public IWidgetWorldTickable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimePeriod;
    
public:
    UGameWidgetDynamicMaterialRetainerBox();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "WidgetWorldTickable.h"
#include "GameWidgetImage.h"
#include "GameWidgetDynamicMaterialImage.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetDynamicMaterialImage : public UGameWidgetImage, public IWidgetWorldTickable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bUsePeriod;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TimePeriod;
    
public:
    UGameWidgetDynamicMaterialImage();


    // Fix for true pure virtual functions not being implemented
};


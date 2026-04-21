#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "GameWidgetImage.h"
#include "GameWidgetResolution.h"
#include "GameWidgetResolutionSwapImage.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetResolutionSwapImage : public UGameWidgetImage, public IGameWidgetResolution {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 HighResolutionThreshold;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 LowResolutionThreshold;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush DesignedResolutionBrush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush HighResolutionBrush;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush LowResolutionBrush;
    
public:
    UGameWidgetResolutionSwapImage();


    // Fix for true pure virtual functions not being implemented
};


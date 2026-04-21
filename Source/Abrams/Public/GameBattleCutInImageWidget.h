#pragma once
#include "CoreMinimal.h"
#include "GameWidgetDynamicMaterialImage.h"
#include "GameBattleCutInImageWidget.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameBattleCutInImageWidget : public UGameWidgetDynamicMaterialImage {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    uint8 ImageType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float OffsetRate;
    
public:
    UGameBattleCutInImageWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void SetOffsetRate(float InOffsetRate);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetOffsetRate() const;
    
};


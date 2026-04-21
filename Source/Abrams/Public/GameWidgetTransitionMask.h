#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameWidgetTransitionMask.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetTransitionMask : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Alpha;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Image;
    
public:
    UGameWidgetTransitionMask();

    UFUNCTION(BlueprintCallable)
    void SetAlpha(float InAlpha);
    
    UFUNCTION(BlueprintCallable, BlueprintPure)
    float GetAlpha() const;
    
};


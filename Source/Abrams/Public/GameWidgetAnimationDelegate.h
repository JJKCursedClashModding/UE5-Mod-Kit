#pragma once
#include "CoreMinimal.h"
#include "WidgetTransitionable.h"
#include "GameWidgetBase.h"
#include "GameWidgetAnimationDelegate.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetAnimationDelegate : public UGameWidgetBase, public IWidgetTransitionable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OnPreOpenAnimationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OnPostOpenAnimationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OnPreCloseAnimationName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName OnPostCloseAnimationName;
    
public:
    UGameWidgetAnimationDelegate();


    // Fix for true pure virtual functions not being implemented
};


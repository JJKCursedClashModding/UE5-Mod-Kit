#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameLoadingWidget.generated.h"

class UImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLoadingWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UImage* LoadingImage;
    
public:
    UGameLoadingWidget();

};


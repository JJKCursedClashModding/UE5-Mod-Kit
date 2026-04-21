#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameFooterWidget.generated.h"

class UHorizontalBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFooterWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHorizontalBox* LeftInputGuideButtonRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHorizontalBox* RightInputGuideButtonRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHorizontalBox* LeftMessageTextRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UHorizontalBox* RightMessageTextRoot;
    
public:
    UGameFooterWidget();

};


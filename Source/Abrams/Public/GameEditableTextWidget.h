#pragma once
#include "CoreMinimal.h"
#include "Types/SlateEnums.h"
#include "GameWindowBase.h"
#include "GameEditableTextWidget.generated.h"

class UGameWidgetEditableText;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameEditableTextWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetEditableText* EditableText;
    
public:
    UGameEditableTextWidget();

protected:
    UFUNCTION(BlueprintCallable)
    void OnCommit(const FText& InText, TEnumAsByte<ETextCommit::Type> InCommitMethod);
    
};


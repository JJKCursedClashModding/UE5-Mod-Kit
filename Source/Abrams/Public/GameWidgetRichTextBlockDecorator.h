#pragma once
#include "CoreMinimal.h"
#include "GameWidgetRichTextBlockDecoratorBase.h"
#include "GameWidgetRichTextBlockDecorator.generated.h"

class UDataTable;

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetRichTextBlockDecorator : public UGameWidgetRichTextBlockDecoratorBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* CustomImageSet;
    
public:
    UGameWidgetRichTextBlockDecorator();

};


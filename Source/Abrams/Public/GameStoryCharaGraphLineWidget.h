#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameStoryCharaGraphLineWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryCharaGraphLineWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* LineImage;
    
public:
    UGameStoryCharaGraphLineWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "Components/CanvasPanel.h"
#include "GameWidgetStoryCharaGraphLinePanel.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetStoryCharaGraphLinePanel : public UCanvasPanel {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterId1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName CharacterId2;
    
public:
    UGameWidgetStoryCharaGraphLinePanel();

};


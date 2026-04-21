#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryMissionSelectContentPanelWidget.generated.h"

class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryMissionSelectContentPanelWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ChapterId;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* ThumbnailTexture;
    
public:
    UGameStoryMissionSelectContentPanelWidget();

};


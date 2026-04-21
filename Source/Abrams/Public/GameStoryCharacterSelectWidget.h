#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameStoryCharacterSelectWidget.generated.h"

class UGameStoryCharacterSelectCharacterContentWidget;
class UGameStoryCharacterSelectMissionInfoWidget;
class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryCharacterSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* MapImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharacterSelectMissionInfoWidget* MissionInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharacterSelectCharacterContentWidget* CharacterInfo_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharacterSelectCharacterContentWidget* CharacterInfo_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameStoryCharacterSelectCharacterContentWidget* CharacterInfo_03;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float TeamMemberEnterAnimationDelayTime;
    
public:
    UGameStoryCharacterSelectWidget();

};


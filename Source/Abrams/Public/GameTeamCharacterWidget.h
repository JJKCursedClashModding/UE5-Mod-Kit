#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterCaptureType.h"
#include "WidgetTransitionable.h"
#include "WidgetWorldTickable.h"
#include "GameWidgetBase.h"
#include "GameWidgetCharacterCapture.h"
#include "GameTeamCharacterWidget.generated.h"

class UGameWidgetImage;
class UMaterialInstance;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameTeamCharacterWidget : public UGameWidgetBase, public IWidgetTransitionable, public IWidgetWorldTickable, public IGameWidgetCharacterCapture {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterCaptureType CaptureType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 CharacterIndex;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CharacterImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* OverrideMaterialInstance;
    
public:
    UGameTeamCharacterWidget();


    // Fix for true pure virtual functions not being implemented
};


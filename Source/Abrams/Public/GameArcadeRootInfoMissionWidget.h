#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameArcadeRootInfoMissionWidget.generated.h"

class UGameArcadeRootInfoCharacterIconWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameArcadeRootInfoMissionWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameArcadeRootInfoCharacterIconWidget* CharacterIconLeft;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameArcadeRootInfoCharacterIconWidget* CharacterIconRight;
    
public:
    UGameArcadeRootInfoMissionWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameArcadeRootInfoCharacterIconWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameArcadeRootInfoCharacterIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CharacterImage;
    
public:
    UGameArcadeRootInfoCharacterIconWidget();

};


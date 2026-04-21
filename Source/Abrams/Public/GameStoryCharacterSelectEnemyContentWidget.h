#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameStoryCharacterSelectEnemyContentWidget.generated.h"

class UGameWidgetButton;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryCharacterSelectEnemyContentWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* Button;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CharacterNameText;
    
public:
    UGameStoryCharacterSelectEnemyContentWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameLobbyCharacterIconWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameLobbyCharacterIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CharacterText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CharacterImage;
    
public:
    UGameLobbyCharacterIconWidget();

};


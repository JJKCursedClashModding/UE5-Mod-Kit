#pragma once
#include "CoreMinimal.h"
#include "EGameStoryCharacterSelectCharacterContentType.h"
#include "GameWidgetButton.h"
#include "GameStoryCharacterSelectCharacterContentWidget.generated.h"

class UGameCharacterCaptureWidget;
class UGameWidgetTextBlock;
class UMaterialInstance;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameStoryCharacterSelectCharacterContentWidget : public UGameWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* CaptureWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* SelectedTypeNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CharacterNameText;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameStoryCharacterSelectCharacterContentType ContentType;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* MaterialInstance;
    
public:
    UGameStoryCharacterSelectCharacterContentWidget();

};


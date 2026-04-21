#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleObjectDirectionIconWidget.generated.h"

class UCanvasPanel;
class UGameWidgetImage;
class UGameWidgetTextBlock;
class USizeBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleObjectDirectionIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* RootCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* IconImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* NameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USizeBox* NameTextBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* TagComboDamageImage;
    
public:
    UGameBattleObjectDirectionIconWidget();

};


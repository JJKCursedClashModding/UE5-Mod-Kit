#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameCharacterSelectCursorWidget.generated.h"

class UGameCharacterSelectArcadeClearIconWidget;
class UGameWidgetTextBlock;
class UOverlay;
class URetainerBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCharacterSelectCursorWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    URetainerBox* RetainerBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* PlayerTypeTextRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* PlayerTypeText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* PartnerTypeTextRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* PartnerTypeText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterSelectArcadeClearIconWidget* ArcadeClearIcon;
    
public:
    UGameCharacterSelectCursorWidget();

};


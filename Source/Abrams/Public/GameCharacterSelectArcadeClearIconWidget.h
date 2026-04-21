#pragma once
#include "CoreMinimal.h"
#include "EGameCharacterSelectArcadeClearType.h"
#include "GameWidgetBase.h"
#include "GameCharacterSelectArcadeClearIconWidget.generated.h"

class UGameWidgetImage;
class UOverlay;
class UPaperSprite;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCharacterSelectArcadeClearIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameCharacterSelectArcadeClearType, UPaperSprite*> ArcadeClearIcons;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UOverlay* IconRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* IconImage;
    
public:
    UGameCharacterSelectArcadeClearIconWidget();

};


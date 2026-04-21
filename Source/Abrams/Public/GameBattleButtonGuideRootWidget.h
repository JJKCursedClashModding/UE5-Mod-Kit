#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameWidgetResolution.h"
#include "GameBattleButtonGuideRootWidget.generated.h"

class UGameBattleButtonGuideWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleButtonGuideRootWidget : public UGameWidgetBase, public IGameBattleWidgetContent, public IGameWidgetResolution {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleButtonGuideWidget* ComboTechniqueGuide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleButtonGuideWidget* ExtractionTechniqueGuide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleButtonGuideWidget* TagComboGuide;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleButtonGuideWidget* CursedEnergyTechniqueGuide;
    
public:
    UGameBattleButtonGuideRootWidget();


    // Fix for true pure virtual functions not being implemented
};


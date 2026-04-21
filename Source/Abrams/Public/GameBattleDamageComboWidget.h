#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleDamageComboWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleDamageComboWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CharacterIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CharacterIndexText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TopCursedEnergyExpText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CurrentComboDamageText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CurrentComboAddCursedEnergyExpText;
    
public:
    UGameBattleDamageComboWidget();


    // Fix for true pure virtual functions not being implemented
};


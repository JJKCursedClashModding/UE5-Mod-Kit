#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameFreeBattleCharacterIndexSelectWidget.generated.h"

class UGameFreeBattleCharacterIndexContentWidget;
class UGameFreeBattleTeamCharacterSelectWidget;
class UGameWidgetInputImageButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFreeBattleCharacterIndexSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleCharacterIndexContentWidget* CharacterIndexContent_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleCharacterIndexContentWidget* CharacterIndexContent_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleCharacterIndexContentWidget* CharacterIndexContent_03;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleCharacterIndexContentWidget* CharacterIndexContent_04;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImageButton* IndexChangeLeftButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImageButton* IndexChangeRightButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleTeamCharacterSelectWidget* TeamCharacterSelectWidget;
    
public:
    UGameFreeBattleCharacterIndexSelectWidget();

};


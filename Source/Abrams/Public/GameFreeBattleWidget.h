#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameFreeBattleWidget.generated.h"

class UGameFreeBattleCharacterIndexSelectWidget;
class UGameFreeBattleCharacterUniqueSelectWidget;
class UGameFreeBattleRuleSelectWidget;
class UGameFreeBattleSettingsWidget;
class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFreeBattleWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* StageImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameFreeBattleSettingsWidget* FreeBattleSettingsWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleCharacterIndexSelectWidget* CharacterIndexSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleCharacterUniqueSelectWidget* CharacterUniqueSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameFreeBattleRuleSelectWidget* RuleSelectWidget;
    
public:
    UGameFreeBattleWidget();

};


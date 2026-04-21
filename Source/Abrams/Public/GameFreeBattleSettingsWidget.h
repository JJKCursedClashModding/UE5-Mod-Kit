#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameFreeBattleSettingsWidget.generated.h"

class UGameWidgetButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFreeBattleSettingsWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* CharacterSettingsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* CharacterUniqueSettingsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* BattleSettingsButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* CommandListButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* BattleStartButton;
    
public:
    UGameFreeBattleSettingsWidget();

};


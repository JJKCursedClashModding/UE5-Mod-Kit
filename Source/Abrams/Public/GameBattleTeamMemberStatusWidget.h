#pragma once
#include "CoreMinimal.h"
#include "GameBattleCharacterStatusWidget.h"
#include "GameBattleTeamMemberStatusWidget.generated.h"

class UCanvasPanel;
class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleTeamMemberStatusWidget : public UGameBattleCharacterStatusWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CommandIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CommandName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* OrderCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* OrderIcon_Off;
    
public:
    UGameBattleTeamMemberStatusWidget();

};


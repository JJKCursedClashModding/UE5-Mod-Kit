#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleMarkerWidget.generated.h"

class UGameBattleCharacterMarkerWidget;
class UGameBattleLinkComboNotifyRootWidget;
class UGameBattleObjectDirectionWidget;
class UGameBattlePlayerInfoRootWidget;
class UGameBattleTargetCursorWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleMarkerWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleTargetCursorWidget* TargetCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePlayerInfoRootWidget* PlayerInfoRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleObjectDirectionWidget* ObjectDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleCharacterMarkerWidget* CharacterMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleLinkComboNotifyRootWidget* LinkComboNotifyRoot;
    
public:
    UGameBattleMarkerWidget();


    // Fix for true pure virtual functions not being implemented
};


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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleTargetCursorWidget* TargetCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattlePlayerInfoRootWidget* PlayerInfoRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleObjectDirectionWidget* ObjectDirection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleCharacterMarkerWidget* CharacterMarker;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameBattleLinkComboNotifyRootWidget* LinkComboNotifyRoot;
    
public:
    UGameBattleMarkerWidget();


    // Fix for true pure virtual functions not being implemented
};


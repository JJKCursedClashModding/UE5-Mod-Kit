#pragma once
#include "CoreMinimal.h"
#include "GameCollectionModeWidgetBase.h"
#include "GameCollectionBattleReplayWidget.generated.h"

class UGameCollectionBattleReplayListWidget;
class UGameCollectionListItemDataBase;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionBattleReplayWidget : public UGameCollectionModeWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionBattleReplayListWidget* BattleReplayListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameCollectionListItemDataBase*> ItemList;
    
public:
    UGameCollectionBattleReplayWidget();

};


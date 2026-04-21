#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameCollectionWidget.generated.h"

class UGameCollectionModeSelectWidget;
class UGameCollectionModeWidgetBase;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionModeSelectWidget* ModeSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionModeWidgetBase* ArchiveWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionModeWidgetBase* BattleReplayWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionModeWidgetBase* PlayRecordWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionModeWidgetBase* SoundWidget;
    
public:
    UGameCollectionWidget();

};


#pragma once
#include "CoreMinimal.h"
#include "GameCollectionModeWidgetBase.h"
#include "GameCollectionSoundWidget.generated.h"

class UGameCollectionSoundListViewWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionSoundWidget : public UGameCollectionModeWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionSoundListViewWidget* BgmListViewWidget;
    
public:
    UGameCollectionSoundWidget();

};


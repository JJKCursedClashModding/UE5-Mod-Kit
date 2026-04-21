#pragma once
#include "CoreMinimal.h"
#include "GameCustomizeCardTileItemWidget.h"
#include "GameCustomizeCardPlateTileItemWidget.generated.h"

class UCanvasPanel;
class UGamePlayerCardPlateWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizeCardPlateTileItemWidget : public UGameCustomizeCardTileItemWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGamePlayerCardPlateWidget* PlateWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* LoadingPanel;
    
public:
    UGameCustomizeCardPlateTileItemWidget();

};


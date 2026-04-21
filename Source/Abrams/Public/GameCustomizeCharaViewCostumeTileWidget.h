#pragma once
#include "CoreMinimal.h"
#include "GameCustomizeCharaViewTileWidget.h"
#include "GameCustomizeCharaViewCostumeTileWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizeCharaViewCostumeTileWidget : public UGameCustomizeCharaViewTileWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ItemText;
    
public:
    UGameCustomizeCharaViewCostumeTileWidget();

};


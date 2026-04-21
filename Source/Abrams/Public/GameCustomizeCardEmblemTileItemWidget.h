#pragma once
#include "CoreMinimal.h"
#include "GameCustomizeCardTileItemWidget.h"
#include "GameCustomizeCardEmblemTileItemWidget.generated.h"

class UGamePlayerCardEmblemWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizeCardEmblemTileItemWidget : public UGameCustomizeCardTileItemWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGamePlayerCardEmblemWidget* EmblemWidget;
    
public:
    UGameCustomizeCardEmblemTileItemWidget();

};


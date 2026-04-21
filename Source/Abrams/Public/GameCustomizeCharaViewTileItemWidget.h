#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameWidgetScrollListItem.h"
#include "GameCustomizeCharaViewTileItemWidget.generated.h"

class UCanvasPanel;
class UGameCommonLockIconWidget;
class UGameItemIconWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizeCharaViewTileItemWidget : public UGameWidgetButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameItemIconWidget* ItemIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* LockPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* NewPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* FavoritePanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCommonLockIconWidget* LockIcon;
    
public:
    UGameCustomizeCharaViewTileItemWidget();


    // Fix for true pure virtual functions not being implemented
};


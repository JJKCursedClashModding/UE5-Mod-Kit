#pragma once
#include "CoreMinimal.h"
#include "GameWidgetTabWindow.h"
#include "GameCustomizePlayerCardEditWidget.generated.h"

class UGameCustomizeCardEmblemTileWidget;
class UGameCustomizeCardNicknameTileWidget;
class UGameCustomizeCardPlateTileWidget;
class UGameCustomizeCardTitleTileWidget;
class UGamePlayerCardWidget;
class UGameWidgetCustomizeCardButton;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizePlayerCardEditWidget : public UGameWidgetTabWindow {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGamePlayerCardWidget* PlayerCardWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCustomizeCardTitleTileWidget* TitleTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCustomizeCardNicknameTileWidget* TopNicknameTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCustomizeCardNicknameTileWidget* BottomNicknameTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCustomizeCardEmblemTileWidget* EmblemTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCustomizeCardPlateTileWidget* PlateTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetCustomizeCardButton* TitleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetCustomizeCardButton* TopNicknameButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetCustomizeCardButton* BottomNicknameButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetCustomizeCardButton* EmblemButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetCustomizeCardButton* PlateButton;
    
public:
    UGameCustomizePlayerCardEditWidget();

};


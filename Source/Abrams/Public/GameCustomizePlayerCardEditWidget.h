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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGamePlayerCardWidget* PlayerCardWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeCardTitleTileWidget* TitleTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeCardNicknameTileWidget* TopNicknameTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeCardNicknameTileWidget* BottomNicknameTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeCardEmblemTileWidget* EmblemTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCustomizeCardPlateTileWidget* PlateTileView;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetCustomizeCardButton* TitleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetCustomizeCardButton* TopNicknameButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetCustomizeCardButton* BottomNicknameButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetCustomizeCardButton* EmblemButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetCustomizeCardButton* PlateButton;
    
public:
    UGameCustomizePlayerCardEditWidget();

};


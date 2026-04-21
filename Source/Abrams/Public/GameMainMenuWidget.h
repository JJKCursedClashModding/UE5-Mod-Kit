#pragma once
#include "CoreMinimal.h"
#include "EGameMainMenuType.h"
#include "GameWindowBase.h"
#include "GameMainMenuWidget.generated.h"

class UCanvasPanel;
class UGameBannerWidget;
class UGameMainMenuButtonWidget;
class UGameMainMenuFriendIconWidget;
class UGameMovieWidget;
class UGameWidgetNiagaraEffect;
class UGameWidgetRichTextBlock;
class UPaperSprite;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameMainMenuWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuButtonWidget* StoryButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuButtonWidget* VsPlayerButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuButtonWidget* VsEnemyButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuButtonWidget* LobbyButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuButtonWidget* FreeBattleButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuButtonWidget* CollectionButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuButtonWidget* ShopButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuButtonWidget* ArcadeButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMovieWidget* MovieWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMainMenuFriendIconWidget* FriendIconWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* HelpText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBannerWidget* BannerWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ContentToBannerEffectPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetNiagaraEffect* Niagara_Move;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Interp, meta=(AllowPrivateAccess=true))
    float ContentToBannerRate;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameMainMenuType, UPaperSprite*> TextureBaseIconMap;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameMainMenuType, UPaperSprite*> TextureAddIconMap;
    
public:
    UGameMainMenuWidget();

};


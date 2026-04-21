#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetBattleTitleType.h"
#include "GameWindowBase.h"
#include "GameBattleSituationOverviewWidget.generated.h"

class UCanvasPanel;
class UGameBattleSituationOverviewArcadeWidget;
class UGameBattleSituationOverviewChatMessageWidget;
class UGameBattleSituationOverviewPlayerCardWidget;
class UGameCharacterCaptureWidget;
class UGameWidgetImage;
class UGameWidgetTextBlock;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSituationOverviewWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* MapImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ModeTitleImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ModeTitleTextCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ModeTitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* WinConditionCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* WinConditionTitle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* WinConditionText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewChatMessageWidget* ChatMessage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* SoloAlly;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* TagAlly_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* TagAlly_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* SoloEnemy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* TagEnemy_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* TagEnemy_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* TrioEnemy_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* TrioEnemy_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* TrioEnemy_03;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* QuartetEnemy_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* QuartetEnemy_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* QuartetEnemy_03;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterCaptureWidget* QuartetEnemy_04;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* PlayerCards;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewPlayerCardWidget* PlayerCardAlly_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewPlayerCardWidget* PlayerCardAlly_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewPlayerCardWidget* PlayerCardEnemy_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewPlayerCardWidget* PlayerCardEnemy_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewArcadeWidget* ArcadeWidget;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetBattleTitleType, UTexture2D*> ModeTitleTextureMap;
    
public:
    UGameBattleSituationOverviewWidget();

};


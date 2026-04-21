#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameWindowBase.h"
#include "GameCharacterSelectWidget.generated.h"

class UCanvasPanel;
class UGameCharacterSelectArcadeRewardInfoWidget;
class UGameCharacterSelectCharacterListData;
class UGameCharacterSelectCharacterListWidget;
class UGameCharacterSelectCursorWidget;
class UGameCharacterSelectPlayerInfoWidget;
class UGameWidgetTextBlock;
class USpacer;
class UVerticalBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCharacterSelectWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* RootCanvasPanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpacer* Spacer_CurrentSelectStatus_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCharacterSelectPlayerInfoWidget* FirstPlayerInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpacer* Spacer_CurrentSelectStatus_02;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCharacterSelectPlayerInfoWidget* SecondPlayerInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UVerticalBox* StageNameCanvas;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* StageNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCharacterSelectArcadeRewardInfoWidget* ArcadeRewardInfo;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCharacterSelectCursorWidget* PlayerCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCharacterSelectCursorWidget* PartnerCursor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameCharacterSelectCharacterListWidget* CharacterList;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D CursorFitOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float ListItemLeftPaddingSize;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameCharacterSelectCharacterListData*> ListDataArray;
    
public:
    UGameCharacterSelectWidget();

};


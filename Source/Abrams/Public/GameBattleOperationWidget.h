#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameWidgetInputGuide.h"
#include "GameBattleOperationWidget.generated.h"

class UGameBattleChatMethodDirectionWidget;
class UGameWidgetImage;
class UGameWidgetInputImage;
class UGameWidgetTextBlock;
class UPanelWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleOperationWidget : public UGameWidgetBase, public IGameBattleWidgetContent, public IGameWidgetInputGuide {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleChatMethodDirectionWidget* UpKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleChatMethodDirectionWidget* DownKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleChatMethodDirectionWidget* RightKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleChatMethodDirectionWidget* LeftKey;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UPanelWidget* TargetChangePanel;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetInputImage* InputImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ChatInputImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TargetText;
    
public:
    UGameBattleOperationWidget();


    // Fix for true pure virtual functions not being implemented
};


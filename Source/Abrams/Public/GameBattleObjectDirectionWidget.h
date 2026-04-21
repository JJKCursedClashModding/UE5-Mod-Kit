#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameWidgetOverrideColorParameter.h"
#include "GameBattleObjectDirectionWidget.generated.h"

class UGameBattleObjectDirectionIconWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleObjectDirectionWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float DisplayMarginRate;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetOverrideColorParameter PlayerIconColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleObjectDirectionIconWidget* Player1Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleObjectDirectionIconWidget* Player2Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleObjectDirectionIconWidget* Player3Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleObjectDirectionIconWidget* Player4Icon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleObjectDirectionIconWidget* Player5Icon;
    
public:
    UGameBattleObjectDirectionWidget();


    // Fix for true pure virtual functions not being implemented
};


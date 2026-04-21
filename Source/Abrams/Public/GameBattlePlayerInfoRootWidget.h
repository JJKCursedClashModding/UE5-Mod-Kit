#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameWidgetOverrideColorParameter.h"
#include "GameBattlePlayerInfoRootWidget.generated.h"

class UGameBattlePlayerInfoWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattlePlayerInfoRootWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetOverrideColorParameter PlayerInfoFrameColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePlayerInfoWidget* Player1Info;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePlayerInfoWidget* Player2Info;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePlayerInfoWidget* Player3Info;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePlayerInfoWidget* Player4Info;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattlePlayerInfoWidget* Player5Info;
    
public:
    UGameBattlePlayerInfoRootWidget();


    // Fix for true pure virtual functions not being implemented
};


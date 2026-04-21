#pragma once
#include "CoreMinimal.h"
#include "EGameBuffDebuff.h"
#include "UObject/NoExportTypes.h"
#include "GameBattleBuffDebuffIconParameter.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleBuffDebuffIconListWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleBuffDebuffIconListWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameBuffDebuff, FGameBattleBuffDebuffIconParameter> IconParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D IconOffset;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* OverCountText;
    
public:
    UGameBattleBuffDebuffIconListWidget();


    // Fix for true pure virtual functions not being implemented
};


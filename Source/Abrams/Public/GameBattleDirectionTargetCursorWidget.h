#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameWidgetOverrideColorParameter.h"
#include "GameBattleDirectionTargetCursorWidget.generated.h"

class UGameBattleDirectionTargetCursorIconWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleDirectionTargetCursorWidget : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float Radius;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    float CoverAngle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameWidgetOverrideColorParameter PlayerIconColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleDirectionTargetCursorIconWidget* Player1DirectionIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleDirectionTargetCursorIconWidget* Player2DirectionIcon;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleDirectionTargetCursorIconWidget* Player3DirectionIcon;
    
public:
    UGameBattleDirectionTargetCursorWidget();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "EGameMissionDifficulty.h"
#include "Styling/SlateBrush.h"
#include "GameWidgetBase.h"
#include "GameVsEnemyMatchingSettingsDifficultyWidget.generated.h"

class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyMatchingSettingsDifficultyWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameMissionDifficulty, FSlateBrush> DifficultyBrushMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* DifficultyImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* DifficultyTextBlock;
    
public:
    UGameVsEnemyMatchingSettingsDifficultyWidget();

};


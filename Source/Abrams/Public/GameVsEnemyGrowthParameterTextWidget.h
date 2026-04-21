#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameVsEnemyGrowthParameterTextWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyGrowthParameterTextWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ParameterText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ChangeText;
    
public:
    UGameVsEnemyGrowthParameterTextWidget();

};


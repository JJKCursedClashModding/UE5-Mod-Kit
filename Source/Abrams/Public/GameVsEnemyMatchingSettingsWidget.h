#pragma once
#include "CoreMinimal.h"
#include "GameWindowBase.h"
#include "GameVsEnemyMatchingSettingsWidget.generated.h"

class UGameVsEnemyMatchingSettingsDifficultyWidget;
class UGameWidgetButton;
class UGameWidgetTextBlock;
class UGameWidgetVsEnemyMatchingSettingsOptionBox;
class UGameWidgetVsEnemyMatchingSettingsValueBox;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameVsEnemyMatchingSettingsWidget : public UGameWindowBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* OkButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* BackButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyMatchingSettingsValueBox* RiskValueBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* SearchRangeHeaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyMatchingSettingsValueBox* UpperSearchRangeValueBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyMatchingSettingsValueBox* LowerSearchRangeValueBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetVsEnemyMatchingSettingsOptionBox* HelpMatchEnabledOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyMatchingSettingsDifficultyWidget* LowerDifficultyWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameVsEnemyMatchingSettingsDifficultyWidget* UpperDifficultyWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* DifficultySymbolTextBlock;
    
public:
    UGameVsEnemyMatchingSettingsWidget();

};


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
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetButton* OkButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetButton* BackButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TitleText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyMatchingSettingsValueBox* RiskValueBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* SearchRangeHeaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyMatchingSettingsValueBox* UpperSearchRangeValueBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyMatchingSettingsValueBox* LowerSearchRangeValueBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetVsEnemyMatchingSettingsOptionBox* HelpMatchEnabledOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyMatchingSettingsDifficultyWidget* LowerDifficultyWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameVsEnemyMatchingSettingsDifficultyWidget* UpperDifficultyWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* DifficultySymbolTextBlock;
    
public:
    UGameVsEnemyMatchingSettingsWidget();

};


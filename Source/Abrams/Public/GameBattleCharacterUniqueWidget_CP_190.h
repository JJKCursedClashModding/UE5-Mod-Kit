#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "GameBattleCharacterUniqueWidget.h"
#include "GameBattleCharacterUniqueWidget_CP_190.generated.h"

class UGameWidgetImage;
class UGameWidgetProgressBar;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleCharacterUniqueWidget_CP_190 : public UGameBattleCharacterUniqueWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BloodPackEnabledColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FLinearColor BloodPackDisabledColor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetProgressBar* BloodManipulationGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BloodPackImage1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BloodPackImage2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BloodPackImage3;
    
public:
    UGameBattleCharacterUniqueWidget_CP_190();

};


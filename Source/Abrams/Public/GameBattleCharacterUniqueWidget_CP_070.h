#pragma once
#include "CoreMinimal.h"
#include "GameBattleCharacterUniqueWidget.h"
#include "GameBattleCharacterUniqueWidget_CP_070.generated.h"

class UGameWidgetImage;
class UGameWidgetProgressBar;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleCharacterUniqueWidget_CP_070 : public UGameBattleCharacterUniqueWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetProgressBar* ThroatGauge;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ThroatTreatImage1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ThroatTreatImage2;
    
public:
    UGameBattleCharacterUniqueWidget_CP_070();

};


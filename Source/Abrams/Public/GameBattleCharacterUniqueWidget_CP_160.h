#pragma once
#include "CoreMinimal.h"
#include "GameBattleCharacterUniqueWidget.h"
#include "GameBattleCharacterUniqueWidget_CP_160.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleCharacterUniqueWidget_CP_160 : public UGameBattleCharacterUniqueWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* IconImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* HighlightImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* RecastGaugeImage;
    
public:
    UGameBattleCharacterUniqueWidget_CP_160();

};


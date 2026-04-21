#pragma once
#include "CoreMinimal.h"
#include "GameWidgetTextOptionBox.h"
#include "GameWidgetVsEnemyMatchingSettingsOptionBox.generated.h"

class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetVsEnemyMatchingSettingsOptionBox : public UGameWidgetTextOptionBox {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName HeaderTextId;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* HeaderText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* SelectedImage;
    
public:
    UGameWidgetVsEnemyMatchingSettingsOptionBox();

};


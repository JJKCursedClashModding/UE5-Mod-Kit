#pragma once
#include "CoreMinimal.h"
#include "EGameConfigCategoryFlag.h"
#include "GameWidgetButton.h"
#include "GameConfigCategoryTab.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameConfigCategoryTab : public UGameWidgetButton {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameConfigCategoryFlag CategoryType;
    
public:
    UGameConfigCategoryTab();

};


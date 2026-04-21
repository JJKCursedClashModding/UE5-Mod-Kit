#pragma once
#include "CoreMinimal.h"
#include "GamePaginationListViewDialogWidget.h"
#include "GameUnlockDlcContentDialogWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameUnlockDlcContentDialogWidget : public UGamePaginationListViewDialogWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TitleText;
    
public:
    UGameUnlockDlcContentDialogWidget();

};


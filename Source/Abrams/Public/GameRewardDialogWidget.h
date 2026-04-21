#pragma once
#include "CoreMinimal.h"
#include "GamePaginationListViewDialogWidget.h"
#include "GameRewardDialogWidget.generated.h"

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameRewardDialogWidget : public UGamePaginationListViewDialogWidget {
    GENERATED_BODY()
public:
    UGameRewardDialogWidget();

};


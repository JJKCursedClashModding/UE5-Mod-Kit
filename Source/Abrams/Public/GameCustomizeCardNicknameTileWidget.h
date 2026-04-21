#pragma once
#include "CoreMinimal.h"
#include "EGameNicknameType.h"
#include "GameWidgetPaginationListView.h"
#include "GameCustomizeCardNicknameTileWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCustomizeCardNicknameTileWidget : public UGameWidgetPaginationListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameNicknameType TargetNicknameType;
    
public:
    UGameCustomizeCardNicknameTileWidget();

};


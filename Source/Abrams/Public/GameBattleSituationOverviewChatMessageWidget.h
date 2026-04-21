#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameBattleSituationOverviewChatMessageWidget.generated.h"

class UGameBattleSituationOverviewChatMessageContentWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleSituationOverviewChatMessageWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewChatMessageContentWidget* Player1Chat;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameBattleSituationOverviewChatMessageContentWidget* Player2Chat;
    
public:
    UGameBattleSituationOverviewChatMessageWidget();

};


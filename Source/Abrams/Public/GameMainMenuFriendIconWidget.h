#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GameMainMenuFriendIconWidget.generated.h"

class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameMainMenuFriendIconWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* FriendNumText;
    
public:
    UGameMainMenuFriendIconWidget();

};


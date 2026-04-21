#pragma once
#include "CoreMinimal.h"
#include "GameBattleWidgetContent.h"
#include "GameWidgetBase.h"
#include "GameBattleTransitionWidgetBase.generated.h"

class UGameWidgetRichTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameBattleTransitionWidgetBase : public UGameWidgetBase, public IGameBattleWidgetContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* SubText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* SubText_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetRichTextBlock* SubText_3;
    
public:
    UGameBattleTransitionWidgetBase();


    // Fix for true pure virtual functions not being implemented
};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetButton.h"
#include "GameWidgetScrollListItem.h"
#include "GameRankingFilterConditionListItemCharaWidget.generated.h"

class UCanvasPanel;
class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameRankingFilterConditionListItemCharaWidget : public UGameWidgetButton, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* CharacterIconImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CharacterNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* CheckIconPanel;
    
public:
    UGameRankingFilterConditionListItemCharaWidget();


    // Fix for true pure virtual functions not being implemented
};


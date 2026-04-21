#pragma once
#include "CoreMinimal.h"
#include "EGameArcadeDifficulty.h"
#include "UObject/NoExportTypes.h"
#include "GameWidgetRecyclerListView.h"
#include "GameArcadeRootSelectWidget.generated.h"

class UGameArcadeRootInfoWidget;
class UGameArcadeRootSelectListItemData;
class UGameWidgetButton;
class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameArcadeRootSelectWidget : public UGameWidgetRecyclerListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameArcadeDifficulty, FLinearColor> DifficultyColorMap_BG_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameArcadeDifficulty, FLinearColor> DifficultyColorMap_BG_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BG_HorizontalGradation_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* BG_HorizontalGradation_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* DifficultyText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* DifficultyRightArrowButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetButton* DifficultyLeftArrowButton;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Difficulty_BG_Easy;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Difficulty_BG_Normal;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* Difficulty_BG_Hard;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameArcadeRootInfoWidget* RootInfoWidget;
    
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameArcadeRootSelectListItemData*> ListItemDataArray;
    
public:
    UGameArcadeRootSelectWidget();

};


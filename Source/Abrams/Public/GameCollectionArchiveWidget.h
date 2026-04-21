#pragma once
#include "CoreMinimal.h"
#include "GameCollectionModeWidgetBase.h"
#include "GameCollectionArchiveWidget.generated.h"

class UGameCollectionArchiveMovieListWidget;
class UGameCollectionArchiveSelectWidget;
class UGameCollectionArchiveTextListWidget;
class UGameCollectionArchiveTileWidget;
class UGameWidgetTextBlock;
class UUserWidget;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionArchiveWidget : public UGameCollectionModeWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* ContentText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionArchiveSelectWidget* ArchiveSelectWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionArchiveTileWidget* ArchivePlateWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionArchiveTextListWidget* ArchiveTextListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionArchiveMovieListWidget* ArchiveMovieListWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCollectionArchiveTileWidget* ArchiveTileWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* DescriptionFrame_01;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UUserWidget* DescriptionFrame_02;
    
public:
    UGameCollectionArchiveWidget();

};


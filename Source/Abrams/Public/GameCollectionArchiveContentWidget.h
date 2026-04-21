#pragma once
#include "CoreMinimal.h"
#include "EGameCollectionArchiveContent.h"
#include "GameWidgetTabWindowContent.h"
#include "GameCollectionArchiveContentWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCollectionArchiveContentWidget : public UGameWidgetTabWindowContent {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* IconImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCollectionArchiveContent ArchiveContent;
    
public:
    UGameCollectionArchiveContentWidget();

};


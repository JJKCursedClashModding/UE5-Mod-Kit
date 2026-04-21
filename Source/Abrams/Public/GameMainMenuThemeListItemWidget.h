#pragma once
#include "CoreMinimal.h"
#include "WidgetWorldTickable.h"
#include "GameWidgetButton.h"
#include "GameWidgetResolution.h"
#include "GameWidgetScrollListItem.h"
#include "GameMainMenuThemeListItemWidget.generated.h"

class UGameMovieWidget;
class UGameWidgetImage;
class UTexture2D;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameMainMenuThemeListItemWidget : public UGameWidgetButton, public IGameWidgetScrollListItem, public IWidgetWorldTickable, public IGameWidgetResolution {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameMovieWidget* MovieWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ThumbnailImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* SelectImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* RandomImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UTexture2D* SmallRandomImage;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    uint32 HighResolutionThreshold;
    
public:
    UGameMainMenuThemeListItemWidget();


    // Fix for true pure virtual functions not being implemented
};


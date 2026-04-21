#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "Styling/SlateTypes.h"
#include "GameWidgetButton.h"
#include "GameWidgetMappingInputReceive.h"
#include "GameWidgetScrollListItem.h"
#include "GameCharacterSelectCharacterListItemWidget.generated.h"

class UCanvasPanel;
class UGameCharacterSelectArcadeClearIconWidget;
class UGameWidgetDynamicMaterialImage;
class UGameWidgetImage;
class UMaterialInstance;
class UMaterialInstanceDynamic;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameCharacterSelectCharacterListItemWidget : public UGameWidgetButton, public IGameWidgetMappingInputReceive, public IGameWidgetScrollListItem {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FButtonStyle RandomButtonStyle;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FVector2D CharacterImageSize;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FString HoldSeName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    int32 HoldSePitch;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstance* CharacterIconMaterial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialInstanceDynamic* CharacterIconMID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* ImageRoot;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* ButtonGlowImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetDynamicMaterialImage* ProgressFrameImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameCharacterSelectArcadeClearIconWidget* ArcadeClearIcon;
    
public:
    UGameCharacterSelectCharacterListItemWidget();


    // Fix for true pure virtual functions not being implemented
};


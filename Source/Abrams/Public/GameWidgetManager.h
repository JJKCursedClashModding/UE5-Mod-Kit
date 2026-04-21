#pragma once
#include "CoreMinimal.h"
#include "WidgetManager.h"
#include "EGameWidgetCaptureType.h"
#include "EGameWidgetInputGuideType.h"
#include "Templates/SubclassOf.h"
#include "GameWidgetManager.generated.h"

class AGameCharacterCaptureActor;
class UDataTable;
class UGameKeyRepeatController;
class UGameWidgetCharacterParameter;
class UGameWidgetConfigParameter;
class UGameWidgetDynamicIconParameter;
class UGameWidgetExchangeImageParameter;
class UGameWidgetFontParameter;
class UGameWidgetInputData;
class UGameWidgetInputGuideTextDecorator;
class UGameWidgetKeyRepeatParameter;
class UGameWidgetRichTextBlockDecorator;
class UGameWidgetSceneCaptureParameter;
class UGameWidgetStoryDemoParameter;
class UGameWidgetTextScrollParameter;
class UMaterialParameterCollection;
class URichTextBlockDecorator;

UCLASS(Blueprintable)
class ABRAMS_API AGameWidgetManager : public AWidgetManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameWidgetInputData*> InputDataArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameKeyRepeatController*> KeyRepeatControllerArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UDataTable* RichTextStyleData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<UGameWidgetRichTextBlockDecorator> CommonDecorator;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetInputGuideType, TSubclassOf<UGameWidgetInputGuideTextDecorator>> InputGuideDecoratorClasses;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetInputGuideType, URichTextBlockDecorator*> InputGuideDecoratorInstanceArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMaterialParameterCollection* TimeParameterCollection;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TSubclassOf<AGameCharacterCaptureActor> CharacterCaptureActorBP;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetExchangeImageParameter* ExchangeImageParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetSceneCaptureParameter* CaptureParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetKeyRepeatParameter* KeyRepeatParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetDynamicIconParameter* DynamicIconParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetCharacterParameter* CharacterParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetFontParameter* FontParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetStoryDemoParameter* StoryDemoParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetConfigParameter* ConfigParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameWidgetTextScrollParameter* TextScrollParameter;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetCaptureType, AGameCharacterCaptureActor*> SpawnedCaptureActorMap;
    
public:
    AGameWidgetManager(const FObjectInitializer& ObjectInitializer);

};


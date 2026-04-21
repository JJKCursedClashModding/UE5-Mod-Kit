#pragma once
#include "CoreMinimal.h"
#include "GameStoryDemoBackgroundParameter.h"
#include "GameStoryDemoCharacterParameter.h"
#include "GameStoryDemoEffectParameter.h"
#include "GameStoryDemoParameter.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetStoryDemoParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetStoryDemoParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameStoryDemoParameter StoryDemoParameter;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameStoryDemoCharacterParameter> CharacterParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameStoryDemoBackgroundParameter> BackgroundParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameStoryDemoEffectParameter> EffectParameterMap;
    
public:
    UGameWidgetStoryDemoParameter();

};


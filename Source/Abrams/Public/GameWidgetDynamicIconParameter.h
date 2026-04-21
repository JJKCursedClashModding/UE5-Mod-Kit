#pragma once
#include "CoreMinimal.h"
#include "EGameItemType.h"
#include "EGameRankPointClass.h"
#include "EGameChatInputKey.h"
#include "EGameCommonChatIconCategory.h"
#include "EGameWidgetBindingVowsCategoryType.h"
#include "EGameWidgetBindingVowsDifficultType.h"
#include "GameWidgetBindingVowsCategoryParameter.h"
#include "GameWidgetBindingVowsDifficultTypeParameter.h"
#include "GameWidgetChatParameter.h"
#include "GameWidgetCursedObjectsParameter.h"
#include "GameWidgetCursedToolsParameter.h"
#include "GameWidgetEmblemParameter.h"
#include "GameWidgetExtrasParameter.h"
#include "GameWidgetFallbackInputGuideParameter.h"
#include "GameWidgetItemCategoryParameter.h"
#include "GameWidgetOperationParameter.h"
#include "GameWidgetParameterBase.h"
#include "GameWidgetRankPointClassParameter.h"
#include "GameWidgetDynamicIconParameter.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameWidgetDynamicIconParameter : public UGameWidgetParameterBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetBindingVowsDifficultType, FGameWidgetBindingVowsDifficultTypeParameter> BindingVowsDifficultTypeParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameWidgetBindingVowsCategoryType, FGameWidgetBindingVowsCategoryParameter> BindingVowsCategoryParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameRankPointClass, FGameWidgetRankPointClassParameter> RankPointClassParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameWidgetEmblemParameter> EmblemParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameWidgetCursedToolsParameter> CursedToolsParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameWidgetCursedObjectsParameter> CursedObjectsParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameWidgetExtrasParameter> ExtrasParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameItemType, FGameWidgetItemCategoryParameter> ItemCategoryParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameItemType, FGameWidgetItemCategoryParameter> ItemCategorySmallParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameCommonChatIconCategory, FGameWidgetChatParameter> ChatParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EGameChatInputKey, FGameWidgetOperationParameter> OperationParameterMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FGameWidgetFallbackInputGuideParameter> FallbackInputGuideParameterMap;
    
public:
    UGameWidgetDynamicIconParameter();

};


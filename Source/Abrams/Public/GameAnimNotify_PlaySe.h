#pragma once
#include "CoreMinimal.h"
#include "GameAnimNotify.h"
#include "GameSoundPlayParameter.h"
#include "GameAnimNotify_PlaySe.generated.h"

UCLASS(Blueprintable, CollapseCategories)
class ABRAMS_API UGameAnimNotify_PlaySe : public UGameAnimNotify {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Id_SoundEffect;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bAttached;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName SpawnBoneName;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FGameSoundPlayParameter PlayParameter;
    
    UGameAnimNotify_PlaySe();

};


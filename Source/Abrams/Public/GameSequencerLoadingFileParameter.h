#pragma once
#include "CoreMinimal.h"
#include "GameSequencerAnimationReferenceParameter.h"
#include "GameSequencerDecalReferenceParameter.h"
#include "GameSequencerNPCReferenceParameter.h"
#include "GameSequencerTextureReferenceParameter.h"
#include "GameSequencerLoadingFileParameter.generated.h"

USTRUCT(BlueprintType)
struct FGameSequencerLoadingFileParameter {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName ID;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FName Filename;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepLighting;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bKeepFacial;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> BindingSupportCharacterIdMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, FName> BindingWeaponIdMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameSequencerAnimationReferenceParameter> AnimationReferenceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameSequencerDecalReferenceParameter> DecalReferenceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameSequencerTextureReferenceParameter> TextureReferenceParameters;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameSequencerNPCReferenceParameter> NPCReferenceParameters;
    
    ABRAMS_API FGameSequencerLoadingFileParameter();
};


#pragma once
#include "CoreMinimal.h"
#include "SoundManager.h"
#include "GameSoundManager.generated.h"

class AAtomAreaSoundVolume;
class UAtomComponent;

UCLASS(Blueprintable)
class ABRAMS_API AGameSoundManager : public ASoundManager {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAtomComponent* SystemSePlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAtomComponent*> SePlayerArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAtomComponent*> Se3DPlayerArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAtomComponent* AmbientSePlayer;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<TWeakObjectPtr<AAtomAreaSoundVolume>> AreaSoundVolumeArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UAtomComponent* SystemVoicePlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAtomComponent*> VoicePlayerArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UAtomComponent*> Voice3DPlayerArray;
    
public:
    AGameSoundManager(const FObjectInitializer& ObjectInitializer);

};


#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "TickableInterface.h"
#include "SequencerManager.generated.h"

class UCameraComponent;
class ULevelSequence;

UCLASS(Blueprintable)
class FRAMEWORK_API ASequencerManager : public AActor, public ITickableInterface {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, ULevelSequence*> LevelSequenceMap;
    
public:
    ASequencerManager(const FObjectInitializer& ObjectInitializer);

protected:
    UFUNCTION(BlueprintCallable)
    void OnStopSequencePlayer_Internal();
    
    UFUNCTION(BlueprintCallable)
    void OnPlaySequencePlayer_Internal();
    
    UFUNCTION(BlueprintCallable)
    void OnPlayReverseSequencePlayer_Internal();
    
    UFUNCTION(BlueprintCallable)
    void OnFinishedSequencePlayer_Internal();
    
    UFUNCTION(BlueprintCallable)
    void OnCameraCutSequencePlayer_Internal(UCameraComponent* CameraComponent);
    

    // Fix for true pure virtual functions not being implemented
};


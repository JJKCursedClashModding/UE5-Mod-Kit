#pragma once
#include "CoreMinimal.h"
#include "AbramsSequencerModuleBase.h"
#include "AbramsSequencerMovieModule.generated.h"

class AGameMovieActor;
class UFileManaMovie;
class UManaPlayer;

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerMovieModule : public UAbramsSequencerModuleBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameMovieActor* MovieActor;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UManaPlayer* ManaPlayer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UFileManaMovie* FileManaMovie;
    
public:
    UAbramsSequencerMovieModule();

};


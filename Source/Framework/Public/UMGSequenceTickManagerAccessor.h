#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "Animation/UMGSequenceTickManager.h"
#include "UMGSequenceTickManagerAccessor.generated.h"

class UMovieSceneEntitySystemLinker;
class UUserWidget;

UCLASS(Blueprintable)
class FRAMEWORK_API UUMGSequenceTickManagerAccessor : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    TMap<TWeakObjectPtr<UUserWidget>, FSequenceTickManagerWidgetData> WeakUserWidgetData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Transient, meta=(AllowPrivateAccess=true))
    UMovieSceneEntitySystemLinker* Linker;
    
    UUMGSequenceTickManagerAccessor();

};


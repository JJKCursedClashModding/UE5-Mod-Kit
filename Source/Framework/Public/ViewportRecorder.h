#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "ViewportRecorder.generated.h"

class UMovieSceneCapture;

UCLASS(Blueprintable)
class FRAMEWORK_API UViewportRecorder : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UMovieSceneCapture* SceneCapture;
    
public:
    UViewportRecorder();

};


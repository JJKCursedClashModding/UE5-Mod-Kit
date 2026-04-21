#include "ViewportRecorder.h"
#include "MovieSceneCapture.h"

UViewportRecorder::UViewportRecorder() {
    this->SceneCapture = CreateDefaultSubobject<UMovieSceneCapture>(TEXT("NewSceneCapture"));
}



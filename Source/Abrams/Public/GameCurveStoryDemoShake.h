#pragma once
#include "CoreMinimal.h"
#include "Curves/CurveBase.h"
#include "Curves/RichCurve.h"
#include "GameCurveStoryDemoShake.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameCurveStoryDemoShake : public UCurveBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    FRichCurve FloatCurves[4];
    
    UGameCurveStoryDemoShake();

};


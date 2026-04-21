#pragma once
#include "CoreMinimal.h"
#include "Sections/MovieSceneParameterSection.h"
#include "Sections/MovieSceneParameterSection.h"
#include "Sections/MovieSceneParameterSection.h"
#include "Sections/MovieSceneParameterSection.h"
#include "Sections/MovieSceneParameterSection.h"
#include "Sections/MovieSceneParameterSection.h"
#include "AbramsSequencerSectionBase.h"
#include "AbramsSequencerSectionValiableParameterBase.generated.h"

UCLASS(Blueprintable)
class ABRAMSSEQUENCER_API UAbramsSequencerSectionValiableParameterBase : public UAbramsSequencerSectionBase {
    GENERATED_BODY()
public:
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FBoolParameterNameAndCurve> BoolParameterNamesAndCurves;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FScalarParameterNameAndCurve> ScalarParameterNamesAndCurves;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVector2DParameterNameAndCurves> Vector2DParameterNamesAndCurves;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FVectorParameterNameAndCurves> VectorParameterNamesAndCurves;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FColorParameterNameAndCurves> ColorParameterNamesAndCurves;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FTransformParameterNameAndCurves> TransformParameterNamesAndCurves;
    
    UAbramsSequencerSectionValiableParameterBase();

};


#pragma once
#include "CoreMinimal.h"
#include "GameWidgetBase.h"
#include "GamePlayerRankGradeWidget.generated.h"

class UGameWidgetImage;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGamePlayerRankGradeWidget : public UGameWidgetBase {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* GradeMarkImage_1;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* GradeMarkImage_2;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* GradeMarkImage_3;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* GradeMarkImage_4;
    
public:
    UGamePlayerRankGradeWidget();

};


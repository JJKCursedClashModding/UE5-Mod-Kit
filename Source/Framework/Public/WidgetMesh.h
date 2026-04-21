#pragma once
#include "CoreMinimal.h"
#include "Styling/SlateBrush.h"
#include "Components/Widget.h"
#include "WidgetMesh.generated.h"

class USlateVectorArtData;

UCLASS(Abstract, Blueprintable)
class FRAMEWORK_API UWidgetMesh : public UWidget {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    USlateVectorArtData* MeshData;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    FSlateBrush Brush;
    
public:
    UWidgetMesh();

};


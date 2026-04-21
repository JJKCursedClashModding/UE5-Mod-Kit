#pragma once
#include "CoreMinimal.h"
#include "GameWidgetScrollListView.h"
#include "GameWidgetRecyclerListView.generated.h"

class USpacer;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetRecyclerListView : public UGameWidgetScrollListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpacer* HeadSpacer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpacer* TailSpacer;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    USpacer* MiddleSpacer;
    
public:
    UGameWidgetRecyclerListView();

};


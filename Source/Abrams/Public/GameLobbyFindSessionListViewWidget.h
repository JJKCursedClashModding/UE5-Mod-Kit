#pragma once
#include "CoreMinimal.h"
#include "GameWidgetScrollListView.h"
#include "GameLobbyFindSessionListViewWidget.generated.h"

class UCanvasPanel;
class UGameWidgetTextBlock;

UCLASS(Abstract, Blueprintable, EditInlineNew)
class ABRAMS_API UGameLobbyFindSessionListViewWidget : public UGameWidgetScrollListView {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* HostIdText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UCanvasPanel* DisplayCanvas;
    
public:
    UGameLobbyFindSessionListViewWidget();

};


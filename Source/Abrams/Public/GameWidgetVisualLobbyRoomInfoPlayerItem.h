#pragma once
#include "CoreMinimal.h"
#include "InputWidgetBase.h"
#include "WidgetInputReceive.h"
#include "GameWidgetVisualLobbyRoomInfoPlayerItem.generated.h"

class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameWidgetVisualLobbyRoomInfoPlayerItem : public UInputWidgetBase, public IWidgetInputReceive {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* UserNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* RankIconImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* FriendIconImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true, BindWidget))
    UGameWidgetImage* HostIconImage;
    
public:
    UGameWidgetVisualLobbyRoomInfoPlayerItem();


    // Fix for true pure virtual functions not being implemented
};


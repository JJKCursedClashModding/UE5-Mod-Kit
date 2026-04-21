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
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* RankIconImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* FriendIconImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* HostIconImage;
    
public:
    UGameWidgetVisualLobbyRoomInfoPlayerItem();


    // Fix for true pure virtual functions not being implemented
};


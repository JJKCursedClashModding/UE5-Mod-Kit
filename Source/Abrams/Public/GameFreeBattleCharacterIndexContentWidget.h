#pragma once
#include "CoreMinimal.h"
#include "WidgetWorldTickable.h"
#include "EGameCharacterIndex.h"
#include "GameWidgetButton.h"
#include "GameFreeBattleCharacterIndexContentWidget.generated.h"

class UGameTeamCharacterWidget;
class UGameWidgetFreeBattleTextOptionBox;
class UGameWidgetImage;
class UGameWidgetTextBlock;

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UGameFreeBattleCharacterIndexContentWidget : public UGameWidgetButton, public IWidgetWorldTickable {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameTeamCharacterWidget* TeamCharacterWidget;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* TeamNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetTextBlock* CharacterNameText;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetFreeBattleTextOptionBox* PlayableOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetFreeBattleTextOptionBox* AILevelOptionBox;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* RandomImage;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* NameBackImage_PlayerTeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    UGameWidgetImage* NameBackImage_RivalTeam;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    EGameCharacterIndex CharacterIndex;
    
public:
    UGameFreeBattleCharacterIndexContentWidget();


    // Fix for true pure virtual functions not being implemented
};


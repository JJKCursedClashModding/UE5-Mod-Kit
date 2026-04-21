#pragma once
#include "CoreMinimal.h"
#include "DebugWidgetBase.h"
#include "Types/SlateEnums.h"
#include "DebugBootWidget.generated.h"

UCLASS(Blueprintable, EditInlineNew)
class ABRAMS_API UDebugBootWidget : public UDebugWidgetBase {
    GENERATED_BODY()
public:
    UDebugBootWidget();

    UFUNCTION(BlueprintCallable)
    void OnWidgetTest();
    
    UFUNCTION(BlueprintCallable)
    void OnTitle();
    
    UFUNCTION(BlueprintCallable)
    void OnSystemTest();
    
    UFUNCTION(BlueprintCallable)
    void OnStartup();
    
    UFUNCTION(BlueprintCallable)
    void OnSelectLanguage(const FString& SelectItem, TEnumAsByte<ESelectInfo::Type> SelectionType);
    
    UFUNCTION(BlueprintCallable)
    void OnScript();
    
    UFUNCTION(BlueprintCallable)
    void OnMainMenu();
    
    UFUNCTION(BlueprintCallable)
    void OnLogo();
    
    UFUNCTION(BlueprintCallable)
    void OnLobby();
    
    UFUNCTION(BlueprintCallable)
    void OnLevelSequencer();
    
    UFUNCTION(BlueprintCallable)
    void OnCredits();
    
    UFUNCTION(BlueprintCallable)
    void OnCalculateTest();
    
    UFUNCTION(BlueprintCallable)
    void OnBattleTest();
    
    UFUNCTION(BlueprintCallable)
    void OnBattleReplay();
    
    UFUNCTION(BlueprintCallable)
    void OnBattlePvP();
    
    UFUNCTION(BlueprintCallable)
    void OnBattlePvE();
    
    UFUNCTION(BlueprintCallable)
    void OnBattleFree();
    
    UFUNCTION(BlueprintCallable)
    void OnBattleArcade();
    
    UFUNCTION(BlueprintCallable)
    void OnAgingOnline();
    
};


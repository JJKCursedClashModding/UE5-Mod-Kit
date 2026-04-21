#pragma once
#include "CoreMinimal.h"
#include "EInputKey.h"
#include "EGameInputKey.h"
#include "GameKeyboardList.h"
#include "GameOnlineInputSettings.generated.h"

USTRUCT(BlueprintType)
struct FGameOnlineInputSettings {
    GENERATED_BODY()
public:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameInputKey> KeyBindingKeyArray;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EInputKey> KeyBindingValueArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<EGameInputKey> KeyboardBindingKeyArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FGameKeyboardList> KeyboardBindingValueArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bSpecialTagComboAssistEnabled;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFreeCameraReverseH;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    bool bFreeCameraReverseV;
    
    ABRAMS_API FGameOnlineInputSettings();
};


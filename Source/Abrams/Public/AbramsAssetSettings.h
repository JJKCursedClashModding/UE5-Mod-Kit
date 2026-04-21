#pragma once
#include "CoreMinimal.h"
#include "UObject/NoExportTypes.h"
#include "UObject/Object.h"
#include "AbramsAssetSettings.generated.h"

UCLASS(Blueprintable, DefaultConfig, Config=Game)
class ABRAMS_API UAbramsAssetSettings : public UObject {
    GENERATED_BODY()
public:
    UPROPERTY(AdvancedDisplay, BlueprintReadWrite, Config, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<FDirectoryPath> DirectoriesToCook;
    
    UAbramsAssetSettings();

};


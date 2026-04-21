#pragma once
#include "CoreMinimal.h"
#include "GameFramework/Actor.h"
#include "WidgetManager.generated.h"

class UDebugWidgetBase;
class UPaperSprite;
class UTexture2D;
class UWindowBase;

UCLASS(Abstract, Blueprintable)
class FRAMEWORK_API AWidgetManager : public AActor {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UWindowBase*> RootWindowArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, Instanced, meta=(AllowPrivateAccess=true))
    TArray<UDebugWidgetBase*> DebugWidgetArray;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UTexture2D*> DynamicLoadTextureMap;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<FName, UPaperSprite*> DynamicLoadSpriteMap;
    
public:
    AWidgetManager(const FObjectInitializer& ObjectInitializer);

};


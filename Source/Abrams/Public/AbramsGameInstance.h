#pragma once
#include "CoreMinimal.h"
#include "Engine/GameInstance.h"
#include "EAbramsActorTicker.h"
#include "AbramsGameInstance.generated.h"

class AActorTicker;
class AGameBattleManager;
class AGameCharacterManager;
class AGameCollisionManager;
class AGameDataTableManager;
class AGameDebugManager;
class AGameEffectManager;
class AGameInputManager;
class AGameManager;
class AGameOnlineManager;
class AGamePauseManager;
class AGamePhaseManager;
class AGameRenderManager;
class AGameScreenShotOverlay;
class AGameSequencerManager;
class AGameSoundManager;
class AGameTextManager;
class AGameTimeManager;
class AGameTrapManager;
class AGameWidgetManager;
class UGameObjectPoolManager;
class UGameOnlineAchievementsManager;
class UGameSaveDataManager;

UCLASS(Blueprintable, NonTransient)
class ABRAMS_API UAbramsGameInstance : public UGameInstance {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameBattleManager* GameBattleManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameCharacterManager* GameCharacterManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameCollisionManager* GameCollisionManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameDataTableManager* GameDataTableManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameInputManager* GameInputManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameEffectManager* GameEffectManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameManager* GameManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameOnlineManager* GameOnlineManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGamePauseManager* GamePauseManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGamePhaseManager* GamePhaseManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameRenderManager* GameRenderManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameSequencerManager* GameSequencerManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameSoundManager* GameSoundManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameTextManager* GameTextManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameTimeManager* GameTimeManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameTrapManager* GameTrapManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameWidgetManager* GameWidgetManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameScreenShotOverlay* GameScreenShotOverlay;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameObjectPoolManager* GameObjectPoolManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameOnlineAchievementsManager* GameOnlineAchievementsManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    UGameSaveDataManager* GameSaveDataManager;
    
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    AGameDebugManager* GameDebugManager;
    
    UPROPERTY(EditAnywhere, meta=(AllowPrivateAccess=true))
    TMap<EAbramsActorTicker, AActorTicker*> TickerMap;
    
public:
    UAbramsGameInstance();

};


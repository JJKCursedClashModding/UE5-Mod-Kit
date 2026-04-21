#pragma once
#include "CoreMinimal.h"
#include "GamePhase_MainMenuBase.h"
#include "GamePhase_MainMenuCollection.generated.h"

class UGameCollectionListItemDataBase;

UCLASS(Blueprintable)
class ABRAMS_API UGamePhase_MainMenuCollection : public UGamePhase_MainMenuBase {
    GENERATED_BODY()
public:
private:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<UGameCollectionListItemDataBase*> ReplayItemList;
    
public:
    UGamePhase_MainMenuCollection();

};


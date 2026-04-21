#pragma once
#include "CoreMinimal.h"
#include "UObject/Object.h"
#include "GameCharacterWeaponController.generated.h"

class AGameWeapon;

UCLASS(Blueprintable)
class ABRAMS_API UGameCharacterWeaponController : public UObject {
    GENERATED_BODY()
public:
protected:
    UPROPERTY(BlueprintReadWrite, EditAnywhere, meta=(AllowPrivateAccess=true))
    TArray<AGameWeapon*> WeaponArray;
    
public:
    UGameCharacterWeaponController();

};


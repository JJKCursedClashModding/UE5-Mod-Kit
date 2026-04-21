#pragma once
#include "CoreMinimal.h"
#include "KeyRepeatController.h"
#include "GameKeyRepeatController.generated.h"

UCLASS(Blueprintable)
class ABRAMS_API UGameKeyRepeatController : public UKeyRepeatController {
    GENERATED_BODY()
public:
    UGameKeyRepeatController();

};


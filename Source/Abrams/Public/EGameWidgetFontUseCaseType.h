#pragma once
#include "CoreMinimal.h"
#include "EGameWidgetFontUseCaseType.generated.h"

UENUM()
enum class EGameWidgetFontUseCaseType : int8 {
    None,
    Title,
    SubTitle,
    Text,
    Label,
    UserName,
    UserNameBold,
    Unique,
    Max,
};


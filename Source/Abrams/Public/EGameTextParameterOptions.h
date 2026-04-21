#pragma once
#include "CoreMinimal.h"
#include "EGameTextParameterOptions.generated.h"

UENUM()
enum class EGameTextParameterOptions : uint32 {
    None,
    ConvertAbsolute,
    ConvertRateToPercent,
    UseFullWidthNumber = 4,
    UseHalfWidthNumber = 8,
    DecimalPlace_1 = 1024,
    DecimalPlace_2 = 2048,
    DecimalPlace_3 = 4096,
    DecimalPlace_4 = 8192,
    UseDecimalNumber = 1048576,
    SupportIntParameter = 13,
    SupportFloatParameter = 15375,
    SupportStringParameter = 1048588,
    Invalid = 4294967295,
};

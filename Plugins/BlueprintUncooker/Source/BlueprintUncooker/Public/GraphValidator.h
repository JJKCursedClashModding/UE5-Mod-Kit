#pragma once

#include "CoreMinimal.h"

class UBlueprint;

DECLARE_LOG_CATEGORY_EXTERN(LogGraphValidator, Log, All);

/**
 * Dumps a human-readable description of every graph, node, and pin in a Blueprint
 * to both the Output Log and a text file under {Project}/Saved/BlueprintUncooker/.
 * Called automatically after every uncook operation.
 */
class BLUEPRINTUNCOOKER_API FGraphValidator
{
public:
	static void DumpBlueprint(UBlueprint* BP);
};

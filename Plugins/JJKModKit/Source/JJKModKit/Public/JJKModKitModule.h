#pragma once

#include "Modules/ModuleManager.h"

class FJJKModKitModule : public IModuleInterface
{
public:
	virtual void StartupModule() override;
	virtual void ShutdownModule() override;
};

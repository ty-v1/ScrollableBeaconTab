﻿#pragma once

#include "CoreMinimal.h"
#include "Modules/ModuleManager.h"

class FScrollableBeaconTabModule : public FDefaultGameModuleImpl
{
public:
	virtual void StartupModule() override;
	virtual bool IsGameModule() const override { return true; }
};

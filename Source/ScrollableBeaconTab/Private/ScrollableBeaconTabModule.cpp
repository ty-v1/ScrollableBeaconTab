#include "ScrollableBeaconTabModule.h"

#include "SML/Public/Patching/NativeHookManager.h"
#include "FGGameMode.h"
#include "FGWorkBench.h"
#include "FGCheatManager.h"
#include "FGGameState.h"
#include "FGGameMode.h"
#include "SML/Public/Patching/NativeHookManager.h"
#include "SML/Public/Patching/BlueprintHookManager.h"
#include "SML/Public/Patching/BlueprintHookHelper.h"
#include "SML/Public/Util/BlueprintLoggingLibrary.h"

#define LOCTEXT_NAMESPACE "FScrollableBeaconTabModule"

void FScrollableBeaconTabModule::StartupModule()
{
#if !WITH_EDITOR
	AFGGameMode* gameModeCDO = GetMutableDefault<AFGGameMode>();
	SUBSCRIBE_METHOD_VIRTUAL(AFGGameMode::PostLogin, gameModeCDO, [](auto& scope, AFGGameMode* self, APlayerController* playerController) {
	});
#endif
}

#undef LOCTEXT_NAMESPACE

IMPLEMENT_MODULE(FScrollableBeaconTabModule, ScrollableBeaconTab)

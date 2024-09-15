#pragma once
#include "Patching/BlueprintHookHelper.h"

DECLARE_LOG_CATEGORY_EXTERN(SBTLog, Log, All);

/**
 * Before displaying the map, copy all the beacons into the ScrollBox.
 */
void OnConstruct(const FBlueprintHookHelper& Helper);

/**
 * Restore all beacons when clear the search field.
 */
void OnClearSearchHook(const FBlueprintHookHelper& Helper);


/**
 * Copy all beacons from the search results when modify the search field.
 */
void OnPopulateSearchResults(const FBlueprintHookHelper& Helper);

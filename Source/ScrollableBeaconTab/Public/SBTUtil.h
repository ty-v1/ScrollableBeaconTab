#pragma once
#include "UI/FGInteractWidget.h"

/**
 * Find ScrollBox from WidgetScrollbox named Widget_Scrollbox_C_1.
 *
 * @param
 *
 * @return ScrollBox
 */
UScrollBox* FindScrollBox(const UUserWidget* MapFiltersContainer);

/**
 * Find Widget_Map_Filters_Container in Widget_MapContainer
 *
 * @param MapContainer Widget_MapContainer
 *
 * @return Widget_Map_Filters_Container.
 */
UUserWidget* FindMapFiltersContainer(const UFGInteractWidget* MapContainer);


/**
 * Find BeaconContainer in Widget_Map_Filters_Container
 *
 * @param MapFiltersContainer Widget_Map_Filters_Container
 * @param Name Container name
 *
 * @return BeaconContainer
 */
UVerticalBox* FindBeaconContainer(const UObject* MapFiltersContainer, const FName Name);

/**
 * Load Widget_MapContainer
 *
 * @return Widget_MapContainer
 */
UClass* LoadMapContainerWidgetClass();

/**
 * Create SizeBox
 *
 * @return SizeBox
 */
USizeBox* CreateSizeBox(const UFGInteractWidget* MapContainer);

/**
 * Return true if MapContainer has the SizeBox
 *
 * @return SizeBox
 */
bool ExistsSizeBox(const UFGInteractWidget* MapContainer);

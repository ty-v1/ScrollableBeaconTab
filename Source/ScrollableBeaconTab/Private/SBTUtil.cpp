#include "SBTUtil.h"

static const FName GSize_Box_Name = FName(TEXT("__SBT_SIZE_BOX__"));

/**
 * Find a ScrollBox from WidgetScrollbox with named Widget_Scrollbox_C_1.
 */
UScrollBox* FindScrollBox(const UUserWidget* MapFiltersContainer)
{
	const FObjectProperty* WidgetScrollboxProps = CastFieldChecked<FObjectProperty>(
		MapFiltersContainer->GetClass()->FindPropertyByName(TEXT("Widget_Scrollbox_C_1"))
	);
	const UUserWidget* WidgetScrollBox = CastChecked<UUserWidget>(
		WidgetScrollboxProps->GetPropertyValue_InContainer(MapFiltersContainer, 0)
	);

	const FObjectProperty* ScrollBoxProp = CastFieldChecked<FObjectProperty>(
		WidgetScrollBox->GetClass()->FindPropertyByName(TEXT("mScrollBox"))
	);
	return CastChecked<UScrollBox>(
		ScrollBoxProp->GetPropertyValue_InContainer(WidgetScrollBox, 0)
	);
}

UUserWidget* FindMapFiltersContainer(const UFGInteractWidget* MapContainer)
{
	const FObjectProperty* MapFiltersContainerProps = CastFieldChecked<FObjectProperty>(
		MapContainer->GetClass()->FindPropertyByName(TEXT("Widget_Map_Filters_Container"))
	);
	return CastChecked<UUserWidget>(
		MapFiltersContainerProps->GetPropertyValue_InContainer(MapContainer, 0)
	);
}

UVerticalBox* FindBeaconContainer(const UObject* MapFiltersContainer, const FName Name)
{
	const FObjectProperty* Property = CastFieldChecked<FObjectProperty>(
		MapFiltersContainer->GetClass()->FindPropertyByName(Name)
	);
	return CastChecked<UVerticalBox>(
		Property->GetPropertyValue_InContainer(MapFiltersContainer, 0)
	);
}

UClass* LoadMapContainerWidgetClass()
{
	return LoadObject<UClass>(
		nullptr,
		TEXT("/Game/FactoryGame/Interface/UI/Minimap/Widget_MapContainer.Widget_MapContainer_C")
	);
}

USizeBox* CreateSizeBox(const UFGInteractWidget* MapContainer)
{
	USizeBox* SizeBox = MapContainer->WidgetTree->ConstructWidget<USizeBox>(
		USizeBox::StaticClass(),
		GSize_Box_Name
	);
	SizeBox->SetMaxDesiredHeight(557.0f);
	SizeBox->SetMinDesiredWidth(480.0f);
	return SizeBox;
}

bool ExistsSizeBox(const UFGInteractWidget* MapContainer)
{
	UWidget* SizeBox = MapContainer->WidgetTree->FindWidget(GSize_Box_Name);
	return SizeBox != nullptr;
}

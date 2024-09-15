#include "SBTHook.h"

#include "SBTUtil.h"
#include "UI/FGInteractWidget.h"

DEFINE_LOG_CATEGORY(SBTLog);

void OnConstruct(const FBlueprintHookHelper& Helper)
{
	const UFGInteractWidget* MapContainer = CastChecked<UFGInteractWidget>(Helper.GetContext());
	if (ExistsSizeBox(MapContainer))
	{
		return;
	}

	const UUserWidget* MapFilterContainer = FindMapFiltersContainer(MapContainer);
	UScrollBox* ScrollBox = FindScrollBox(MapFilterContainer);
	UPanelWidget* Overlay = ScrollBox->GetParent();

	USizeBox* SizeBox = CreateSizeBox(MapContainer);
	ScrollBox->RemoveFromParent();
	SizeBox->AddChild(ScrollBox);

	UVerticalBox* BeaconContainer = FindBeaconContainer(
		MapFilterContainer,
		TEXT("mBeaconContainer")
	);
	UVerticalBox* BeaconSearchResults = FindBeaconContainer(
		MapFilterContainer,
		TEXT("mBeaconSearchResults")
	);

	// copy all beacons
	for (UWidget* Beacon : BeaconContainer->GetAllChildren())
	{
		ScrollBox->AddChild(Beacon);
	}

	// hidden BeaconContainer and BeaconSearchResults
	UVerticalBox* BeaconContainersBox = MapContainer->WidgetTree->ConstructWidget<UVerticalBox>(
		UVerticalBox::StaticClass(),
		NAME_None
	);
	BeaconContainer->RemoveFromParent();
	BeaconContainer->SetVisibility(ESlateVisibility::Collapsed);

	BeaconSearchResults->RemoveFromParent();
	BeaconSearchResults->SetVisibility(ESlateVisibility::Collapsed);

	BeaconContainersBox->AddChildToVerticalBox(BeaconContainer);
	BeaconContainersBox->AddChildToVerticalBox(BeaconSearchResults);
	BeaconContainersBox->SetVisibility(ESlateVisibility::Collapsed);

	Overlay->AddChild(SizeBox);
	Overlay->AddChild(BeaconContainersBox);
}

void OnClearSearchHook(const FBlueprintHookHelper& Helper)
{
}


void OnPopulateSearchResults(const FBlueprintHookHelper& Helper)
{
}

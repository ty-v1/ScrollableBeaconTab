using UnrealBuildTool;

public class ScrollableBeaconTab : ModuleRules
{
	public ScrollableBeaconTab(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new[]
			{
				"Core", "CoreUObject",
				"Engine",
				"InputCore",
				"OnlineSubsystem",
				"OnlineSubsystemUtils",
				"OnlineSubsystemNULL",
				"SignificanceManager",
				"PhysX",
				"APEX",
				"PhysXVehicles",
				"ApexDestruction",
				"AkAudio",
				"ReplicationGraph",
				"UMG",
				"AIModule",
				"NavigationSystem",
				"AssetRegistry",
				"GameplayTasks",
				"AnimGraphRuntime",
				"Slate",
				"SlateCore",
				"Json"
			}
		);


		if (Target.Type == TargetRules.TargetType.Editor)
		{
			PublicDependencyModuleNames.AddRange(new[] {"OnlineBlueprintSupport", "AnimGraph"});
		}

		PublicDependencyModuleNames.AddRange(new[] {"FactoryGame", "SML"});
	}
}

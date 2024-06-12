// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TopDown_UE54 : ModuleRules
{
	public TopDown_UE54(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;
	
		PublicDependencyModuleNames.AddRange(new string[] { 
            "Core", "CoreUObject", "Engine", "InputCore", "EnhancedInput",
            "AIModule", "Niagara", "XRBase", "HeadMountedDisplay", "UMG",  "GameplayAbilities"
        });

		PrivateDependencyModuleNames.AddRange(new string[] { "GameplayTags", "GameplayTasks" });

        PrivateIncludePaths.Add("TopDown_UE54");
        PrivateIncludePaths.Add("TopDown_UE54/GAS");
        PrivateIncludePaths.AddRange(new string[] {
                "TopDown_UE54",
                "TopDown_UE54/GAS/Private",
                "TopDown_UE54/GAS/Public",
                "TopDown_UE54/VR/Private",
                "TopDown_UE54/VR/Public",

    });

        // Uncomment if you are using Slate UI
        // PrivateDependencyModuleNames.AddRange(new string[] { "Slate", "SlateCore" });

        // Uncomment if you are using online features
        // PrivateDependencyModuleNames.Add("OnlineSubsystem");

        // To include OnlineSubsystemSteam, add it to the plugins section in your uproject file with the Enabled attribute set to true
    }
}

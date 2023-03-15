// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class GDENG02_UECHAL2 : ModuleRules
{
	public GDENG02_UECHAL2(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay", "EnhancedInput" });
	}
}

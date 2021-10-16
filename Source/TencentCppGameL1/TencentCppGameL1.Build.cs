// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class TencentCppGameL1 : ModuleRules
{
	public TencentCppGameL1(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

		PublicDependencyModuleNames.AddRange(new string[] { "Core", "CoreUObject", "Engine", "InputCore", "HeadMountedDisplay" });
	}
}

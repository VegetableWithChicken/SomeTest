// Copyright 1998-2019 Epic Games, Inc. All Rights Reserved.

#include "SimpleZIP.h"
#include "Core.h"
#include "Modules/ModuleManager.h"
#include "Interfaces/IPluginManager.h"
#include "SimpleZIPLibrary/ZIP_SDK_Library/ZIP_SDK_Library.h"

#define LOCTEXT_NAMESPACE "FSimpleZIPModule"

void FSimpleZIPModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// Get the base directory of this plugin
	FString BaseDir = IPluginManager::Get().FindPlugin("SimpleZIP")->GetBaseDir();

	// Add on the relative location of the third party dll and load it
	FString LibraryPath;
#if PLATFORM_WINDOWS

#if WITH_EDITOR
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SimpleZIPLibrary/x64/Release/ZIP_SDK_Library.dll"));
#endif
	FString Platform = TEXT("Win64");
#if !WITH_EDITOR
	LibraryPath = FPaths::Combine(*BaseDir, TEXT("../../Binaries") / Platform / ("ZIP_SDK_Library.dll"));
#endif

#elif PLATFORM_MAC
   // LibraryPath = FPaths::Combine(*BaseDir, TEXT("Source/ThirdParty/SimpleZIPLibrary/Mac/Release/ZIP_SDK_Library.dylib"));
#endif // PLATFORM_WINDOWS

	ExampleLibraryHandle = !LibraryPath.IsEmpty() ? FPlatformProcess::GetDllHandle(*LibraryPath) : nullptr;

	if (ExampleLibraryHandle)
	{
		// Call the test function in the third party library that opens a message box
	//	ExampleLibraryFunction();
	}
	else
	{
		FMessageDialog::Open(EAppMsgType::Ok, LOCTEXT("ThirdPartyLibraryError", "Failed to load example third party library"));
	}
}

void FSimpleZIPModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// Free the dll handle
	FPlatformProcess::FreeDllHandle(ExampleLibraryHandle);
	ExampleLibraryHandle = nullptr;
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FSimpleZIPModule, SimpleZIP)
